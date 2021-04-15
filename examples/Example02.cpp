#include "SimpleKaraGame.h"

using namespace kara;

class Example02 : public karasimulator::SimpleKaraGame {
protected:
    void run() override;

    void rotate180Degrees();
};

void Example02::run() {
    loadWorldFromResourceFile("resources/worlds/example02.ter");
    startGame();
    
    kara.turnRight();

    for (int i = 0; i < 3; i++) {
        kara.move();
        kara.putLeaf();
    }

    rotate180Degrees();

    for (int i = 0; i < 3; i++) {
        kara.removeLeaf();
        kara.move();
    }
}

void Example02::rotate180Degrees() {
    kara.turnLeft();
    kara.turnLeft();
}

int main() {
    karasimulator::SimpleKaraGame::createInstance<Example02>();
    return 0;
}
