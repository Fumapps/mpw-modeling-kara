#include "KaraViewModelStringifier.h"

#include <algorithm>

namespace viewmodel {

KaraViewModelStringifier::KaraViewModelStringifier(
        const std::unordered_map<std::string, std::string>& imageCharsMapping, int maxCharsPerCell)
        : imageCharsMapping(imageCharsMapping), maxCharsPerCell(maxCharsPerCell) {
}

std::string KaraViewModelStringifier::worldToExpectationString(const GameViewModel& viewModel) {
    std::string actual;
    int height = viewModel.getSize().getRowCount();
    for (int y = 0; y < height; y++) {
        std::string rowString = rowToString(viewModel, y);
        actual.append(rowString);
        actual.append("\n");
    }
    return actual;
}

std::string KaraViewModelStringifier::rowToString(const GameViewModel& viewModel, int y) const {
    std::string result = "|";
    int width = viewModel.getSize().getColumnCount();
    for (int x = 0; x < width; x++) {
        auto cell = viewModel.getCellAt(y, x);
        result.append(cellToString(*cell));
        result.append("|");
    }
    return result;
}

std::string KaraViewModelStringifier::cellToString(const ViewModelCell& cell) const {
    std::string result;
    for (const auto& layer : cell.getLayers()) {
        if (layer.getVisible()) {
            std::string key = layer.getImageName();
            int rotation = layer.getRotation();
            if (rotation != 0) {
                key.append("[");
                key.append(std::to_string(rotation));
                key.append("]");
            }
            result.append(getImageCharMapping(key));
        }
    }
    int length = static_cast<int>(result.length());
    int spaces = std::max(0, maxCharsPerCell - length);
    for (size_t i = 0; i < spaces; i++) {
        result.append(" ");
    }
    return result;
}

std::string KaraViewModelStringifier::logToString(const GameViewModel& viewModel) {
    std::string actual;
    auto& logEntries = viewModel.getLogEntries();
    for (auto& entry : logEntries) {
        actual.append(entry.getMessage());
        actual.append("\n");
    }
    return actual;
}

const std::string& KaraViewModelStringifier::getImageCharMapping(const std::string& key) const {
    auto iter = imageCharsMapping.find(key);
    return (*iter).second;
}

std::string KaraViewModelStringifier::buttonBarToExpectationString(const GameViewModel& viewModel) {
    std::string actual;
    actual.append(buttonToString("play", viewModel.getPlayButtonEnabled()));
    actual.append(" ");
    actual.append(buttonToString("pause", viewModel.getPauseButtonEnabled()));
    actual.append(" ");
    actual.append(buttonToString("undo", viewModel.getUndoButtonEnabled()));
    actual.append(" ");
    actual.append(buttonToString("redo", viewModel.getRedoButtonEnabled()));
    return actual;
}

std::string KaraViewModelStringifier::buttonToString(const std::string& name, bool enabled) {
    if (enabled) {
        return "[" + name + "]";
    }
    return "/" + name + "/";
}

}
