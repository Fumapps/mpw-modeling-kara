#include "gtest/gtest.h"

#include "KaraCore.h"
#include "KaraViewTestBase.h"

#include "view/KaraViewModelStringifier.h"
#include "util/TestUtils.h"

#include <utility>
#include <vector>
#include <string>

using namespace mpw;
using namespace kara;
using namespace framework;
using namespace util;

/**
 * Tests on the view-model layer, which are using the {@link viewmodel::KaraViewModelStringifier} to create
 * string based representations.
 * @note use 'NO-LINT' comment at tests to suppress a warning caused by TEST_F
 */
class KaraViewModelTest : public KaraViewTestBase {
private:
public:
};


TEST_F(KaraViewModelTest, testInit) {
    withWorld("/worlds/example01.ter");
    assertWorld(
        "|##|##|##|##|##|\n"
        "|##|> |@ |  |##|\n"
        "|##|##|* |##|##|\n");
    EXPECT_EQ(true, kara->mushroomFront());
    EXPECT_EQ(true, kara->treeLeft());
    EXPECT_EQ(true, kara->treeRight());
    EXPECT_EQ(false, kara->treeFront());
    EXPECT_EQ(Direction::EAST, kara->getDirection());
    EXPECT_EQ(1, kara->getLocation().getRow());
    EXPECT_EQ(1, kara->getLocation().getColumn());
}

TEST_F(KaraViewModelTest, testMove) {
    withWorld("/worlds/example01.ter");
    kara->move();
    assertWorld(
        "|##|##|##|##|##|\n"
        "|##|  |> |@ |##|\n"
        "|##|##|* |##|##|\n");
    EXPECT_EQ(true, kara->mushroomFront());
    EXPECT_EQ(false, kara->treeRight());
    EXPECT_EQ(Direction::EAST, kara->getDirection());
    EXPECT_EQ(1, kara->getLocation().getRow());
    EXPECT_EQ(2, kara->getLocation().getColumn());
}

TEST_F(KaraViewModelTest, testMoveOnLeaf) {
    withWorld("/worlds/example01.ter");
    kara->move();
    kara->turnRight();
    kara->move();
    assertWorld(
        "|##|##|##|##|##|\n"
        "|##|  |  |@ |##|\n"
        "|##|##|*v|##|##|\n");
    EXPECT_EQ(true, kara->onLeaf());
}

TEST_F(KaraViewModelTest, testRemoveLeaf) {
    withWorld("/worlds/example01.ter");
    kara->move();
    kara->turnRight();
    kara->move();
    kara->removeLeaf();
    assertWorld(
        "|##|##|##|##|##|\n"
        "|##|  |  |@ |##|\n"
        "|##|##|v |##|##|\n");
    EXPECT_EQ(false, kara->onLeaf());
}

TEST_F(KaraViewModelTest, testPutLeaf) {
    withWorld("/worlds/example01.ter");
    kara->putLeaf();
    assertWorld(
        "|##|##|##|##|##|\n"
        "|##|*>|@ |  |##|\n"
        "|##|##|* |##|##|\n");
    EXPECT_EQ(true, kara->onLeaf());
}

TEST_F(KaraViewModelTest, testMoveAndRotateAndMove) {
    withWorld("/worlds/example01.ter");
    kara->move();
    kara->turnLeft();
    kara->turnLeft();
    kara->turnLeft();
    kara->move();
    kara->turnRight();
    kara->turnRight();
    kara->move();
    assertWorld(
        "|##|##|##|##|##|\n"
        "|##|  |^ |@ |##|\n"
        "|##|##|* |##|##|\n");
}

TEST_F(KaraViewModelTest, testMoveAgainstTree) {
    withWorld("/worlds/example01.ter");
    kara->move();
    kara->turnLeft();

    TestUtils::assertThrows(typeid(CommandConstraintException), [&] {
        kara->move();
    });
}

TEST_F(KaraViewModelTest, testMoveMushroomBlocked) {
    withWorld("/worlds/example01.ter");
    kara->move();

    TestUtils::assertThrows(typeid(CommandConstraintException), [&] {
        kara->move();
    });
}

TEST_F(KaraViewModelTest, testLog) {
    withWorld("/worlds/example01.ter");
    kara->move();
    kara->putLeaf();
    kara->turnLeft();
    kara->turnRight();
    kara->removeLeaf();
    kara->write("Hello");
    assertLog({
        "Move\n"
        "Put Leaf\n"
        "Turn Left\n"
        "Turn Right\n"
        "Remove Leaf\n"
        "Hello\n"});
}


/*
 * [button] means: button is enabled
 * /button/ means: button is disabled
 */
TEST_F(KaraViewModelTest, testButtonsForModes) {
    withWorld("/worlds/example01.ter");
    assertButtons("/play/ [pause] /undo/ /redo/");
    kara->move();
    kara->turnRight();
    assertButtons("/play/ [pause] /undo/ /redo/");
    clickPause();
    assertButtons("[play] /pause/ [undo] /redo/");
    clickUndo();
    assertButtons("[play] /pause/ [undo] [redo]");
    clickUndo();
    assertButtons("[play] /pause/ /undo/ [redo]");
    clickRedo();
    assertButtons("[play] /pause/ [undo] [redo]");
    clickPlay();
    assertButtons("/play/ [pause] /undo/ /redo/");
    clickPause();
    assertButtons("[play] /pause/ [undo] /redo/");
    assertWorld(
        "|##|##|##|##|##|\n"
        "|##|  |v |@ |##|\n"
        "|##|##|* |##|##|\n");
}