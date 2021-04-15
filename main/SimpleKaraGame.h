#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_SIMPLEKARAGAME_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_SIMPLEKARAGAME_H

#include "Kara.h"
#include "World.h"
#include "KaraGame.h"

#include <string>
#include <exception>
#include <stdexcept>
#include <utility>

namespace karasimulator {

const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 400;

class SimpleKaraGame {

private:

    const std::string DEFAULT_KARA_WORLD = "worlds/example01.ter";

public:
    template<typename T>
    static void createInstance() {
        T program;
        program.doRun();
    }

protected:

    /**
     * The game object of this simple game. Can be used to start, stop, reset,
     * or display the game.
     */
    const std::shared_ptr<kara::KaraGame> game;

    /**
     * Variable inherited to child classes containing the default kara
     * which is named kara here. Intentionally, no getter or setter is used
     * as they are introduced only after lecture 2.
     */
    kara::Kara& kara;

public:
    /**
     * Initialized a simple kara game by loading a default world
     * and setting protected references to contain kara and
     * the game.
     */
    SimpleKaraGame();

protected:
    /**
     * Initialized a simple kara game by loading a default world.
     * This resets the game if it was already started. After the world was loaded, the game is
     * in mode INITIALIZING. To start the game, game.startGame() should be called.
     */
    void initializeGame();

    /**
     * Convenient method to start the current game.
     * The game has to be in mode INITIALIZING.
     */
    void startGame();

public:
    /**
     * Method to start the execution of a kara game and handle any exceptions happening
     * while running.
     */
    void doRun();

protected:

    /**
     * Predefined kara method designed to be overridden in subclass.
     * Put the kara code into this method. This parent class version
     * is empty, so that the kara does not do anything by default.
     */
    virtual void run() = 0;

    /**
     * Loads the World from a resources file.
     * Only resource paths relative to the binary output are allowed. E.g. the fileName "/world.ter" represents the
     * file world.ter in the binary output directory
     * This resets the game if it was already started. After the world was loaded, the game is
     * in mode INITIALIZING. To start the game, game.startGame() should be called
     *
     * @param fileName An absolute path to the resource file.
     * @throws std::runtime_error if fileName is no valid resource path
     *                            or if the file was not found
     */
    void loadWorldFromResourceFile(const std::string& resourceFilePath);


    /**
     * Displays the kara game in a new game window
     */
    void displayInNewGameWindow();

    /**
     * @return the window title of the simulator.
     */
    virtual std::string getWindowTitle();
};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_SIMPLEKARAGAME_H
