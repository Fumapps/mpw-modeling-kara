#include "KaraApplicationHandler.h"

#include "util/GameLogControl.h"
#include "util/SpeedSliderControl.h"
#include "util/ColorConverter.h"
#include "util/UiDimensions.h"

#include <utility>
#include <thread>

using namespace viewmodel;

const std::string imagePath = "resources/images/";

namespace karasimulator {

KaraApplicationHandler::KaraApplicationHandler(std::shared_ptr<kara::KaraGame> game,
                                                     std::function<void()> karaProgram)
        : game(std::move(game)), karaProgram(std::move(karaProgram)),
          presenter(std::make_shared<KaraGameViewPresenter>(this->game)) {
}

KaraApplicationHandler::~KaraApplicationHandler() {
    this->game->getPerformance()->abortOrStopGame();
    karaThread.join();
}

void KaraApplicationHandler::onInitialized(SdlApplication& application) {
    this->application = &application;

    this->sdlGameInputInterface = std::make_shared<SdlGameInputInterface>(application.getNanoguiScreen());
    this->game->setUserInputInterface(sdlGameInputInterface);

    auto viewModel = this->presenter->getViewModel();
    createButton("Play24", viewModel->playButtonEnabledProperty(), [this]() { presenter->playClicked(); });
    createButton("Pause24", viewModel->pauseButtonEnabledProperty(), [this]() { presenter->pauseClicked(); });
    createButton("Undo24", viewModel->undoButtonEnabledProperty(), [this]() { presenter->undoClicked(); });
    createButton("Redo24", viewModel->redoButtonEnabledProperty(), [this]() { presenter->redoClicked(); });

    loadTexture("Tile");

    std::vector<Color> colorValues{Color::BLACK, Color::BLUE, Color::GREEN, Color::YELLOW, Color::PINK, Color::MAGENTA,
                                   Color::RED};
    loadTexture("Kara");
    loadTexture("Tree");
    loadTexture("Leaf");
    loadTexture("Mushroom");

    presenter->bind();

    gameLogControl = new GameLogControl(application.getNanoguiScreen());
    gameLogControl->bindToGameLog(*viewModel);

    auto speedControl = new SpeedSliderControl(application.getNanoguiScreen());
    speedControl->bindToSpeed(*viewModel, *presenter);

    onResized(); // initially ensure that resizing logic is triggered

    karaThread = std::thread(karaProgram);
}

void KaraApplicationHandler::createButton(const std::string& imageName,
                                             const framework::ObservablePrimitiveProperty<bool>& buttonEnabledProperty,
                                             std::function<void()> clickFunction) {
    SDL_Rect rect{TOOLBAR_MARGIN, TOOLBAR_MARGIN, BUTTON_SIZE, BUTTON_SIZE};
    int previousButtonsCount = static_cast<int>(buttons.size());
    rect.x += (previousButtonsCount * BUTTON_SIZE + previousButtonsCount * TOOLBAR_MARGIN);
    loadTexture(imageName);

    auto& button = buttons.emplace_back();
    button.rect = rect;
    button.texture = texturesByImageName[imageName];
    button.clickFunction = clickFunction;
    button.clicking = false;
    button.buttonEnabledProperty = &buttonEnabledProperty;
}

void KaraApplicationHandler::loadTexture(const std::string& imageName) {
    texturesByImageName[imageName] = &application->loadTexture(imagePath + imageName + ".png");
}

void KaraApplicationHandler::loadTextureWithCustomKey(const std::string& imageName, const std::string& key) {
    texturesByImageName[key] = &application->loadTexture(imagePath + imageName + ".png");
}

void KaraApplicationHandler::onEvent(SDL_Event& event) {
    sdlGameInputInterface->onEvent(event);

    if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
        onResized();
    }

    if (sdlGameInputInterface->isActive()) {
        return;
    }

    if (event.type == SDL_MOUSEBUTTONDOWN) {
        SDL_MouseButtonEvent& buttonEvent = event.button;
        auto buttonIndex = getButtonForPosition(buttonEvent.x, buttonEvent.y);
        if (buttonIndex.has_value()) {
            buttons[buttonIndex.value()].clicking = true;
        }
    } else if (event.type == SDL_MOUSEBUTTONUP) {
        SDL_MouseButtonEvent& buttonEvent = event.button;
        auto buttonIndex = getButtonForPosition(buttonEvent.x, buttonEvent.y);
        if (buttonIndex.has_value()) {
            SimpleButton& button = buttons[buttonIndex.value()];
            if (button.buttonEnabledProperty->get()) {
                button.clickFunction();
            }
        }
        for (auto& button : buttons) {
            button.clicking = false;
        }
    }
}

std::optional<size_t> KaraApplicationHandler::getButtonForPosition(int x, int y) {
    SDL_Point point{x, y};
    for (size_t i = 0; i < buttons.size(); i++) {
        if (SDL_PointInRect(&point, &buttons[i].rect)) {
            return i;
        }
    }
    return std::nullopt;
}

void KaraApplicationHandler::onRender(SDL_Renderer& renderer) {
    renderToolbar(renderer);
    renderWorld(renderer);

    SDL_Delay(16);
}

void KaraApplicationHandler::renderToolbar(SDL_Renderer& renderer) {
    for (auto& button : buttons) {
        if (!button.buttonEnabledProperty->get()) {
            SDL_SetTextureColorMod(button.texture, 128, 128, 128);
        } else if (button.clicking) {
            SDL_SetTextureColorMod(button.texture, 128, 128, 255);
        } else {
            SDL_SetTextureColorMod(button.texture, 255, 255, 255);
        }
        SDL_RenderCopy(&renderer, button.texture, nullptr, &button.rect);
    }
}

void KaraApplicationHandler::renderWorld(SDL_Renderer& renderer) {
    SDL_Rect rect{0, 0, currentTileSize, currentTileSize};

    auto lock = presenter->getSemaphore().lock();
    auto viewModel = presenter->getViewModel();

    unsigned rowIndex = 0;
    for (auto& row : viewModel->getRows()) {
        unsigned columnIndex = 0;
        rect.y = rowIndex * currentTileSize + WORLD_OFFSET;
        for (auto& cell : row.getCells()) {
            rect.x = columnIndex * currentTileSize;
            renderCell(rect, cell, renderer);
            columnIndex++;
        }
        rowIndex++;
    }
}

void KaraApplicationHandler::renderCell(SDL_Rect& rect, ViewModelCell& cell,
                                           SDL_Renderer& renderer) {
    render(renderer, rect, "Tile");
    for (auto& layer : cell.getLayers()) {
        if (layer.getVisible()) {
            render(renderer, rect, layer.getImageName(), layer.getRotation());
        }
    }
}

void KaraApplicationHandler::render(SDL_Renderer& renderer, SDL_Rect& rect,
                                       const std::string& imageName, int rotation) {
    SDL_Texture* texture = texturesByImageName[imageName];
    SDL_RenderCopyEx(&renderer, texture, nullptr, &rect, rotation, nullptr, SDL_FLIP_NONE);
}

void KaraApplicationHandler::onClose() {

}

void KaraApplicationHandler::onResized() {
    currentTileSize = calculateTileSize();
    gameLogControl->setFixedWidth(calculateGameLogSize());
    application->getNanoguiScreen().performLayout();
}

int KaraApplicationHandler::calculateTileSize() {
    const mpw::Size size = game->getWorld()->getWorldSize();
    const int columns = size.getColumnCount();
    const int rows = size.getRowCount();

    sdlgui::Screen& screen = application->getNanoguiScreen();
    const int pixPerCellWidth = (screen.width() - (WORLD_GAMELOG_MARGIN + GAMELOG_MIN_WIDTH)) / (columns == 0 ? 1 : columns);
    const int pixPerCellHeight = (screen.height() - WORLD_OFFSET) / (rows == 0 ? 1 : rows);

    const int tileSize = std::min(pixPerCellHeight, pixPerCellWidth);
    return std::max(MINIMUM_TILE_SIZE, tileSize);
}

int KaraApplicationHandler::calculateGameLogSize() {
    const mpw::Size size = game->getWorld()->getWorldSize();
    const int columns = size.getColumnCount();

    sdlgui::Screen& screen = application->getNanoguiScreen();
    return screen.width() - (columns*currentTileSize) - WORLD_GAMELOG_MARGIN;
}

}
