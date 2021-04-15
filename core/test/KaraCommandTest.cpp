#include "gtest/gtest.h"

#include "Kara.h"
#include "KaraGame.h"
#include "World.h"
#include "Tile.h"
#include "Tree.h"
#include "Leaf.h"
#include "Mushroom.h"
#include "ConcreteKara.h"
#include "GameWorld.h"
#include "Stage.h"
#include "GameLog.h"
#include "LogEntry.h"
#include "CommandConstraintException.h"
#include "WorldBuilder.h"

#include "util/GameStringifier.h"
#include "util/TestUtils.h"

#include <utility>
#include <vector>
#include <string>

using namespace mpw;
using namespace kara;
using namespace framework;
using namespace util;

/**
 * Tests for game commands on the facade layer, which are using the {@link GameStringifier} to create
 * simple string based representations.
 * @note use 'NO-LINT' comment at tests to suppress a warning caused by TEST_F
 */
class KaraCommandTest : public testing::Test {
private:
    std::shared_ptr<KaraGame> game{};
    std::shared_ptr<Kara> sut{};

public:

    void withWorld(const std::string& map);
    std::shared_ptr<WorldBuilder> withWorldBuilder(const std::string& map);

    static Location locationOf(int x, int y);
    void start();
    void turnLeft();
    void turnRight();
    void move();
    void removeLeaf();
    void putLeaf();
    void write(const std::string& message);

    void assertWorld(const std::string& expected);
    void assertFrontIsClear();
    void assertTreeFront();
    void assertMushroomFront();
    void assertOnLeaf();
    void assertNotOnLeaf();
    void assertGameLog(const std::vector<std::string>& expectedStrings);
};

//</editor-fold>


//<editor-fold desc="Feature: move">
TEST_F(KaraCommandTest, givenKaraEast_whenMove_thenMovedToEast) { /* NOLINT */
    withWorld(
            "  #;"
            "> #;"
            "  #;");

    move();

    assertWorld(
            "  #;"
            " >#;"
            "  #;");
}

TEST_F(KaraCommandTest, givenKaraNorth_whenMove_thenMovedToNorth) { /* NOLINT */
    withWorld(
            "  #;"
            "^ #;"
            "  #;");

    move();

    assertWorld(
            "^ #;"
            "  #;"
            "  #;");
}

TEST_F(KaraCommandTest, givenKaraSouth_whenMove_thenMovedToSouth) { /* NOLINT */
    withWorld(
            "  #;"
            "v #;"
            "  #;");

    move();

    assertWorld(
            "  #;"
            "  #;"
            "v #;");
}

TEST_F(KaraCommandTest, givenKaraWest_whenMove_thenMovedToWest) { /* NOLINT */
    withWorld(
            "  #;"
            " <#;"
            "  #;");

    move();

    assertWorld(
            "  #;"
            "< #;"
            "  #;");
}
//</editor-fold>

//<editor-fold desc="Feature: move mushroom">
TEST_F(KaraCommandTest, givenKaraEast_andMushroomFront_whenMove_thenMovedToEast) { /* NOLINT */
    withWorld(">@ ;");
    move();
    assertWorld(" >@;");
}

TEST_F(KaraCommandTest, givenKaraNorth_andMushroomFront_whenMove_thenMovedToNorth) { /* NOLINT */
    withWorld(" ;"
              "@;"
              "^;");
    move();
    assertWorld("@;"
                "^;"
                " ;");
}

TEST_F(KaraCommandTest, givenKaraSouth_andMushroomFront_whenMove_thenMovedToSouth) { /* NOLINT */
    withWorld(
            "v;"
            "@;"
            " ;");

    move();

    assertWorld(" ;"
                "v;"
                "@;");
}

TEST_F(KaraCommandTest, givenKaraWest_andMushroomFront_whenMove_thenMovedToWest) { /* NOLINT */
    withWorld(" @<;");

    move();

    assertWorld("@< ;");
}
//</editor-fold>

//<editor-fold desc="Feature: move mushroom blocked">
TEST_F(KaraCommandTest, givenKaraEast_andMushroomFront_andTreeBehind_whenMove_thenFailed) { /* NOLINT */
    withWorld(">@#;");
    TestUtils::assertThrows(typeid(CommandConstraintException), [&]() {
        move();
    });
}

TEST_F(KaraCommandTest, givenKaraNorth_andMushroomFront_andTreeBehind_whenMove_thenFailed) { /* NOLINT */
    withWorld("#;"
              "@;"
              "^;");
    TestUtils::assertThrows(typeid(CommandConstraintException), [&]() {
        move();
    });
}

TEST_F(KaraCommandTest, givenKaraSouth_andMushroomFront_andTreeBehind_whenMove_thenFailed) { /* NOLINT */
    withWorld(
            "v;"
            "@;"
            "#;");
    TestUtils::assertThrows(typeid(CommandConstraintException), [&]() {
        move();
    });
}

TEST_F(KaraCommandTest, givenKaraWest_andMushroomFront_andTreeBehind_whenMove_thenFailed) { /* NOLINT */
    withWorld("#@<;");
    TestUtils::assertThrows(typeid(CommandConstraintException), [&]() {
        move();
    });
}
//</editor-fold>

//<editor-fold desc="Feature: remove/put leafs">

TEST_F(KaraCommandTest, givenKaraWithLeafAvailable_whenRemoveLeaf_thenRemovedLeaf) { /* NOLINT */
    withWorldBuilder(">;")
            ->addLeafToTile(0, 0);

    start();
    removeLeaf();

    assertNotOnLeaf();
}

TEST_F(KaraCommandTest, givenKaraWithoutLeaf_whenPutLeaf_thenPutLeafOnTile) { /* NOLINT */
    withWorld(">;");

    putLeaf();

    assertOnLeaf();
}

TEST_F(KaraCommandTest, givenKaraNotOnLeaf_andLeafBesidesKara_whenPutLeaf_andRemoveLeaf_thenNoLeafIsOnTile) { /* NOLINT */
    withWorld(">;"
              "*;");

    putLeaf();
    removeLeaf();

    assertNotOnLeaf();
}

TEST_F(KaraCommandTest, givenKaraWithNoLeafAvailable_whenRemoveLeaf_ThenExceptionIsThrown) { /* NOLINT */
    withWorld(">;");

    TestUtils::assertThrows(typeid(CommandConstraintException), [&]() {
        removeLeaf();
    });
}

TEST_F(KaraCommandTest, givenKaraWithLeafAvailable_whenRemoveLeafTwoTimes_ThenExceptionIsThrown) { /* NOLINT */
    withWorld(">;");
    putLeaf();

    removeLeaf();
    TestUtils::assertThrows(typeid(CommandConstraintException), [&]() {
        removeLeaf();
    });
}

TEST_F(KaraCommandTest, givenKaraWithNoLeaf_whenPutLeafTwoTimes_ThenExceptionIsThrown) { /* NOLINT */
    withWorld(">;");

    putLeaf();
    TestUtils::assertThrows(typeid(CommandConstraintException), [&]() {
        putLeaf();
    });
}

//</editor-fold>

//<editor-fold desc="Feature: turnLeft">
TEST_F(KaraCommandTest, givenKaraEast_whenTurnLeft_thenDirectionIsNorth) { /* NOLINT */
    withWorld(">;");
    turnLeft();
    assertWorld("^;");
}
TEST_F(KaraCommandTest, givenKaraNorth_whenTurnLeft_thenDirectionIsWest) { /* NOLINT */
    withWorld("^;");
    turnLeft();
    assertWorld("<;");
}
TEST_F(KaraCommandTest, givenKaraWest_whenTurnLeft_thenDirectionIsSouth) { /* NOLINT */
    withWorld("<;");
    turnLeft();
    assertWorld("v;");
}
TEST_F(KaraCommandTest, givenKaraSouth_whenTurnLeft_thenDirectionIsEast) { /* NOLINT */
    withWorld("v;");
    turnLeft();
    assertWorld(">;");
}
//</editor-fold>

//<editor-fold desc="Feature: turnRight">
TEST_F(KaraCommandTest, givenKaraEast_whenTurnRight_thenDirectionIsNorth) { /* NOLINT */
    withWorld(">;");
    turnRight();
    assertWorld("v;");
}
TEST_F(KaraCommandTest, givenKaraNorth_whenTurnRight_thenDirectionIsWest) { /* NOLINT */
    withWorld("^;");
    turnRight();
    assertWorld(">;");
}
TEST_F(KaraCommandTest, givenKaraWest_whenTurnRight_thenDirectionIsSouth) { /* NOLINT */
    withWorld("<;");
    turnRight();
    assertWorld("^;");
}
TEST_F(KaraCommandTest, givenKaraSouth_whenTurnRight_thenDirectionIsEast) { /* NOLINT */
    withWorld("v;");
    turnRight();
    assertWorld("<;");
}
//</editor-fold>

//<editor-fold desc="Feature: front check">
TEST_F(KaraCommandTest, givenKaraInAnyDirection_andFrontCellIsEmpty_whenCheckFrontIsClear_thenIsTrue) { /* NOLINT */
    withWorld(" <;");
    assertFrontIsClear();

    withWorld("> ;");
    assertFrontIsClear();

    withWorld(" ;^;");
    assertFrontIsClear();

    withWorld("v; ;");
    assertFrontIsClear();
}

TEST_F(KaraCommandTest, givenKaraInAnyDirection_andFrontCellIsTree_whenCheckTreeFront_thenIsTrue) { /* NOLINT */
    withWorld("#<;");
    assertTreeFront();

    withWorld(">#;");
    assertTreeFront();

    withWorld("#;^;");
    assertTreeFront();

    withWorld("v;#;");
    assertTreeFront();
}

TEST_F(KaraCommandTest, givenKaraInAnyDirection_andFrontCellIsMushroom_whenCheckMushroomFront_thenIsTrue) { /* NOLINT */
    withWorld("@<;");
    assertMushroomFront();

    withWorld(">@;");
    assertMushroomFront();

    withWorld("@;^;");
    assertMushroomFront();

    withWorld("v;@;");
    assertMushroomFront();
}

TEST_F(KaraCommandTest, givenKaraInAnyDirection_andFrontCellIsLeaf_whenCheckFrontIsClear_thenIsTrue) { /* NOLINT */
    withWorld("*<;");
    assertFrontIsClear();

    withWorld(">*;");
    assertFrontIsClear();

    withWorld("*;^;");
    assertFrontIsClear();

    withWorld("v;*;");
    assertFrontIsClear();
}

TEST_F(KaraCommandTest, givenKaraBeforeTree_whenMove_ThenExceptionIsThrown) { /* NOLINT */
    withWorld("#<;");

    TestUtils::assertThrows(typeid(CommandConstraintException), [&]() {
        move();
    });
}

//</editor-fold>

//<editor-fold desc="Feature: gameLog">
TEST_F(KaraCommandTest, givenKara_whenExecuteAndCommand_thenGameLogIsAdded) { /* NOLINT */
    withWorld(">*;");

    move();
    removeLeaf();
    putLeaf();
    turnLeft();
    write("Custom Message");

    assertGameLog({
            "Move",
            "Remove Leaf",
            "Put Leaf",
            "Turn Left",
            "Custom Message" });
}

//</editor-fold>

//<editor-fold desc="helpers">

void KaraCommandTest::withWorld(const std::string& map) {
    game = GameStringifier::createFromStringStarted(map);
    sut = game->getWorld()->getKara();
}

std::shared_ptr<WorldBuilder> KaraCommandTest::withWorldBuilder(const std::string& map) {
    game = GameStringifier::createFromString(map);
    sut = game->getWorld()->getKara();
    return std::make_shared<WorldBuilder>(game);
}

void KaraCommandTest::start() {
    game->startGame();
}

Location KaraCommandTest::locationOf(int x, int y) {
    return Location::from(x, y);
}

void KaraCommandTest::turnLeft() {
    sut->turnLeft();
}

void KaraCommandTest::turnRight() {
    sut->turnRight();
}

void KaraCommandTest::move() {
    sut->move();
}

void KaraCommandTest::removeLeaf() {
    sut->removeLeaf();
}

void KaraCommandTest::putLeaf() {
    sut->putLeaf();
}

void KaraCommandTest::write(const std::string& message) {
    sut->write(message);
}

void KaraCommandTest::assertWorld(const std::string& expected) {
    std::string actual = GameStringifier::toString(*game);
    EXPECT_EQ(expected, actual);
}

void KaraCommandTest::assertFrontIsClear() {
    EXPECT_FALSE(sut->treeFront());
    EXPECT_FALSE(sut->mushroomFront());
}

void KaraCommandTest::assertTreeFront() {
    EXPECT_TRUE(sut->treeFront());
    EXPECT_FALSE(sut->mushroomFront());
}

void KaraCommandTest::assertMushroomFront() {
    EXPECT_TRUE(sut->mushroomFront());
    EXPECT_FALSE(sut->treeFront());
}

void KaraCommandTest::assertOnLeaf() {
    EXPECT_TRUE(sut->onLeaf());
}

void KaraCommandTest::assertNotOnLeaf() {
    EXPECT_FALSE(sut->onLeaf());
}

static std::vector<std::string> toMessages(GameLog& log) {
    std::vector<std::string> result;
    for (auto& entry : log.getLogEntries()) {
        result.push_back(entry.getMessage());
    }
    return result;
}

void KaraCommandTest::assertGameLog(const std::vector<std::string>& expectedStrings) {
    std::string actual = TestUtils::join("|", toMessages(*game->getGameLog()));
    std::string expected = TestUtils::join("|", expectedStrings);
    EXPECT_EQ(expected, actual);
}

//</editor-fold>
