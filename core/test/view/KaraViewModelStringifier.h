#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_KARAVIEWMODELSTRINGIFIER_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_KARAVIEWMODELSTRINGIFIER_H

#include "GameViewModel.h"
#include "ViewModelRow.h"
#include "ViewModelCell.h"
#include "ViewModelCellLayer.h"
#include "ViewModelLogEntry.h"

#include <unordered_map>

namespace viewmodel {

/**
 * Helper class to represent the view-model in a string representation.
 *
 * With {@link KaraViewModelStringifier::maxCharsPerCell} the width of a cell in characters is specified.
 * Also, {@link KaraViewModelStringifier::imageCharsMapping} defines a mapping from a symbolic image name to
 * a character sequence, e.g. "Tree" -> " #". Cells are further separated by '|'.
 */
class KaraViewModelStringifier {
public:

    KaraViewModelStringifier(const std::unordered_map<std::string, std::string>& imageCharsMapping,
                                int maxCharsPerCell);

    std::string worldToExpectationString(const GameViewModel& viewModel);

    static std::string logToString(const GameViewModel& viewModel);

    static std::string buttonBarToExpectationString(const GameViewModel& viewModel);

private:

    const std::string& getImageCharMapping(const std::string& key) const;

    std::string rowToString(const GameViewModel& viewModel, int y) const;
    std::string cellToString(const ViewModelCell& cell) const;
    static std::string buttonToString(const std::string& name, bool enabled);

    const std::unordered_map<std::string, std::string>& imageCharsMapping;
    const int maxCharsPerCell;
};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_KARAVIEWMODELSTRINGIFIER_H
