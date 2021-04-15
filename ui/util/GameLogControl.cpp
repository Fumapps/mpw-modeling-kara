#include "GameLogControl.h"

#include "WidgetBackgroundWrapper.h"
#include "ControlWindowTheme.h"
#include "ColorConverter.h"
#include "util/UiDimensions.h"

#include <sdlgui/label.h>
#include <sdlgui/vscrollpanel.h>

const float COLOR_DARK_FACTOR = 0.5;
const SDL_Color LOG_ENTRY_ALTERNATE_COLOR = {216, 216, 216, 150};

const int LOG_ENTRY_RIGHT_MARGIN = 6;
const int LOG_ENTRY_HEIGHT = 20;
const int LOG_ENTRY_MIN_X = 450;

using namespace sdlgui;

karasimulator::GameLogControl::GameLogControl(sdlgui::Screen& screen)
        : Window(&screen, ""), screen(screen) {

    Vector2i windowSize(GAMELOG_MIN_WIDTH, screen.height() - TOOLBAR_MARGIN * 2);
    setFixedSize(windowSize);

    setTheme(new ControlWindowTheme(screen.sdlRenderer()));
    scrollPanel = &vscrollpanel();
    listPanel = &scrollPanel->withFixedSize({windowSize.x, windowSize.y})
            .widget()
            .withLayout<BoxLayout>(Orientation::Vertical, Alignment::Fill, 0, 0);
}

void karasimulator::GameLogControl::bindToGameLog(const viewmodel::GameViewModel& viewModel) {
    viewModel.logEntriesProperty().addOnAddedListener([&](const viewmodel::ViewModelLogEntry& logEntry) {
        SDL_Color color = LOG_ENTRY_ALTERNATE_COLOR;
        if (viewModel.getLogEntries().size() % 2 == 0) {
            color = {0, 0, 0, 0};
        }

        auto& widget = listPanel->wdg<WidgetBackgroundWrapper>(color)
                .withFixedSize({width() - LOG_ENTRY_RIGHT_MARGIN, LOG_ENTRY_HEIGHT});
        Color darkifiedColor = ColorConverter::toDarkerColor(logEntry.getColor(), COLOR_DARK_FACTOR);
        widget.label(logEntry.getMessage())
                .setColor(darkifiedColor);
        logEntryWidgets[&logEntry] = &widget;

        scrollPanel->scrollEvent({}, {0, static_cast<float>(-scrollPanel->height())});
        screen.performLayout();
    });

    viewModel.logEntriesProperty().addOnRemovedListener([&](const viewmodel::ViewModelLogEntry& logEntry) {
        auto iterator = logEntryWidgets.find(&logEntry);
        if (iterator != logEntryWidgets.end()) {
            auto widget = (*iterator).second;
            listPanel->removeChild(widget);
            logEntryWidgets.erase(iterator);
        }
        screen.performLayout();
    });

    screen.performLayout();
}

void karasimulator::GameLogControl::draw(SDL_Renderer* surface) {
    SDL_Rect previousSdlRect;
    SDL_RenderGetClipRect(surface, &previousSdlRect);

    const PntRect& rect = getAbsoluteCliprect();
    SDL_Rect sdlRect = {rect.x1, rect.y1, rect.x2 - rect.x1, rect.y2 - rect.y1};

    SDL_RenderSetClipRect(surface, &sdlRect);
    Window::draw(surface);
    SDL_RenderSetClipRect(surface, nullptr);

    SDL_RenderDrawRect(surface, &sdlRect);
}

void karasimulator::GameLogControl::performLayout(SDL_Renderer* ctx) {
    int gameLogPositionX = std::max(LOG_ENTRY_MIN_X, screen.width() - fixedWidth() - TOOLBAR_MARGIN);
    setPosition(gameLogPositionX, position().y);
    int heightToSet = screen.height() - TOOLBAR_MARGIN * 2;
    setHeight(heightToSet);
    scrollPanel->setFixedWidth(fixedWidth());
    scrollPanel->setFixedHeight(heightToSet-8);

    for (auto logEntryWidgetMapping : logEntryWidgets) {
        auto logEntryWidget = logEntryWidgetMapping.second;
        logEntryWidget->setFixedWidth(fixedWidth() - LOG_ENTRY_RIGHT_MARGIN);
    }

    Window::performLayout(ctx);
}
