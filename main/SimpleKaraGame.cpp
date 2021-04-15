#include "SimpleKaraGame.h"

#include "KaraApplicationHandler.h"

using namespace kara;

namespace karasimulator {

SimpleKaraGame::SimpleKaraGame()
        : game(KaraGame::create()), kara(*game->getWorld()->getKara()) {
    initializeGame();
    game->startGamePaused();
}

void SimpleKaraGame::initializeGame() {
    try {
        loadWorldFromResourceFile("resources/" + DEFAULT_KARA_WORLD);
    } catch (std::exception& e) {
        throw std::runtime_error("failed to load the default world: " + std::string(e.what()));
    }
}

void SimpleKaraGame::startGame() {
    game->startGame();
}

void SimpleKaraGame::doRun() {
    displayInNewGameWindow();
}

void SimpleKaraGame::loadWorldFromResourceFile(const std::string& resourceFilePath) {
    try {
        game->hardReset();
        WorldLoader::initializeFor(*game)->loadFromResourceFile(resourceFilePath);
    } catch (std::exception& e) {
        throw std::runtime_error("failed to load the world '" + resourceFilePath + "' :" + std::string(e.what()));
    }
}

void SimpleKaraGame::displayInNewGameWindow() {
    KaraApplicationHandler applicationHandler(game, [&]() {
        try {
            run();
        } catch (framework::GameAbortedException& e) {
            // End this game
        } catch (std::exception& e) {
            this->game->confirmAlert(e);
            throw e;
        }
        this->game->stopGame();
    });

    SdlApplication application(getWindowTitle(), applicationHandler);
    application.initialize(SCREEN_WIDTH, SCREEN_HEIGHT);

    application.runApplication();
}

std::string SimpleKaraGame::getWindowTitle() {
    return "Simple Kara Game";
}

}
