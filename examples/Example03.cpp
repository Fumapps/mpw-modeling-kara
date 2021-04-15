#include "SimpleKaraGame.h"

using namespace kara;

class Example03 : public karasimulator::SimpleKaraGame {
protected:
    void run() override;
};

void Example03::run() {
    loadWorldFromResourceFile("resources/worlds/example03.ter");
    startGame();

    kara.turnRight();
    kara.move();
}

int main() {
    karasimulator::SimpleKaraGame::createInstance<Example03>();
    return 0;
}
