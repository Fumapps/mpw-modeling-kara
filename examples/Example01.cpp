#include "SimpleKaraGame.h"

using namespace kara;

class Example01 : public karasimulator::SimpleKaraGame {
protected:
    void run() override;
};

void Example01::run() {
    kara.move();
    kara.turnRight();
    kara.move();
    kara.removeLeaf();
    kara.turnLeft();
    kara.turnLeft();
    kara.move();
    kara.putLeaf();
    kara.turnLeft();
    kara.move();
    kara.turnRight();
    kara.turnRight();
}

int main() {
    karasimulator::SimpleKaraGame::createInstance<Example01>();
    return 0;
}

