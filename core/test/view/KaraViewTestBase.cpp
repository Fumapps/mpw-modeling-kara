#include "KaraViewTestBase.h"

#include "KaraGameViewPresenter.h"
#include "UserInputInterfaceFake.h"
#include "KaraViewModelStringifier.h"

#include <memory>

using namespace kara;
using namespace viewmodel;

std::unordered_map<std::string, std::string> KaraViewTestBase::characterMap;

void KaraViewTestBase::SetUp() {
    initCharMapping();
}

void KaraViewTestBase::TearDown() {
    game->getPerformance()->abortOrStopGame();
}

void KaraViewTestBase::withWorld(const std::string& path) {
    game = KaraGame::create();
    WorldLoader::initializeFor(*game)->loadFromResourceFile("resources" + path);

    game->getPerformance()->setDelayEnabled(false);
    game->startGame();

    auto world = game->getWorld();
    kara = world->getKara();

    presenter = std::make_shared<KaraGameViewPresenter>(game);
    presenter->bind();
    viewInput = presenter;
    viewModel = presenter->getViewModel();

    game->setUserInputInterface(std::make_shared<UserInputInterfaceFake>());
}

void KaraViewTestBase::initializeOtherWorld(const std::string& path) {
    game->hardReset();
    WorldLoader::initializeFor(*game)->loadFromResourceFile("resources" + path);
}

void KaraViewTestBase::clickPlay() {
    viewInput->playClicked();
}

void KaraViewTestBase::clickPause() {
    viewInput->pauseClicked();
}

void KaraViewTestBase::clickUndo() {
    viewInput->undoClicked();
}

void KaraViewTestBase::clickRedo() {
    viewInput->redoClicked();
}

void KaraViewTestBase::assertWorld(const std::string& expected) {
    std::string actual = KaraViewModelStringifier(characterMap, maxCharsPerCell).worldToExpectationString(*viewModel);
    EXPECT_EQ(expected, actual);
    assertLocationsAreSet();
    assertSizeIsConsistent();
}

void KaraViewTestBase::assertLocationsAreSet() {
    int rowIndex = 0;
    for (auto& row : viewModel->getRows()) {
        int columnIndex = 0;
        for (auto& cell : row.getCells()) {
            EXPECT_EQ(columnIndex, cell.getLocation().getColumn());
            EXPECT_EQ(rowIndex, cell.getLocation().getRow());
            columnIndex++;
        }
        rowIndex++;
    }
}

void KaraViewTestBase::assertSizeIsConsistent() {
    auto& rows = viewModel->getRows();
    EXPECT_EQ(rows.size(), viewModel->getSize().getRowCount());
    for (auto& row : rows) {
        EXPECT_EQ(row.getCells().size(), viewModel->getSize().getColumnCount());
    }
}

void KaraViewTestBase::assertLog(const std::string& expected) {
    std::string actual = KaraViewModelStringifier::logToString(*viewModel);
    EXPECT_EQ(expected, actual);
}

void KaraViewTestBase::initCharMapping() {
    characterMap["Kara"] = ">";
    characterMap["Kara[90]"] = "v";
    characterMap["Kara[180]"] = "<";
    characterMap["Kara[270]"] = "^";
    characterMap["Leaf"] = "*";
    characterMap["Tree"] = "##";
    characterMap["Mushroom"] = "@";
}

void KaraViewTestBase::assertLayersAt(mpw::Location location, const std::vector<std::string>& expectedLayerImageNames) {
    std::string expected = "";
    for (auto& expectedName : expectedLayerImageNames) {
        expected += expectedName + "\n";
    }
    std::string actual = "";
    auto cell = viewModel->getCellAt(location.getRow(), location.getColumn());
    for (auto& layer : cell->getLayers()) {
        if (layer.getVisible()) {
            actual += layer.getImageName() + "\n";
        }
    }
    EXPECT_EQ(expected, actual);
}

void KaraViewTestBase::assertButtons(const std::string& expected) {
    std::string actual = KaraViewModelStringifier::buttonBarToExpectationString(*viewModel);
    EXPECT_EQ(expected, actual);
    assertLocationsAreSet();
    assertSizeIsConsistent();
}
