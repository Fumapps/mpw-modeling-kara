#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_KARAVIEWTESTBASE_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_KARAVIEWTESTBASE_H

#include <gtest/gtest.h>
#include "KaraCore.h"

#include "GameViewModel.h"

#include <unordered_map>
#include <GameViewPresenter.h>

class KaraViewTestBase : public testing::Test {
private:

    int maxCharsPerCell = 2;
    static std::unordered_map<std::string, std::string> characterMap;
    std::shared_ptr<kara::KaraGame> game;
    std::shared_ptr<viewmodel::GameViewPresenter> presenter;

protected:

    void SetUp() override;
    void TearDown() override;

    void withWorld(const std::string& path);
    void initializeOtherWorld(const std::string& path);

    void clickPlay();
    void clickPause();
    void clickUndo();
    void clickRedo();

    void assertWorld(const std::string& expected);
    void assertLog(const std::string& expected);
    void assertLayersAt(mpw::Location location, const std::vector<std::string>& expectedLayerImageNames);
    void assertButtons(const std::string& expected);

    std::shared_ptr<kara::Kara> kara;
    std::shared_ptr<viewmodel::GameViewInput> viewInput;
    std::shared_ptr<viewmodel::GameViewModel> viewModel;

private:

    static void initCharMapping();

    void assertLocationsAreSet();
    void assertSizeIsConsistent();

};


#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_KARAVIEWTESTBASE_H
