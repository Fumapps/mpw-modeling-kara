#include "WorldLoader.h"

#include <utility>
#include <optional>

using namespace mpw;
using namespace kara;

namespace kara {

std::unique_ptr<WorldLoader> WorldLoader::initializeFor(kara::KaraGame& game) {
    auto builder = std::make_shared<WorldBuilder>(game.shared_from_this());
    return std::unique_ptr<WorldLoader>(new WorldLoader(builder));
}

WorldLoader::WorldLoader(std::shared_ptr<kara::WorldBuilder> worldBuilder)
        : worldBuilder(std::move(worldBuilder)) {

}

void WorldLoader::loadFromResourceFile(const std::string& worldFile) {
    std::vector<std::string> list = readLinesFromWorldResourceFile(worldFile);
    return interpretLoadedWorldLines(list);
}

void WorldLoader::loadFromInputStream(std::ifstream& inputStream) {
    std::vector<std::string> list = readLinesFromWorldInputStream(inputStream);
    interpretLoadedWorldLines(list);
}

void WorldLoader::interpretLoadedWorldLines(const std::vector<std::string>& list) {
    setSizeFromStrings(list);
    std::vector<std::string> worldDefinition(list.begin() + 2, list.end());
    buildTiles(worldDefinition);
}

void WorldLoader::setSizeFromStrings(const std::vector<std::string>& lines) {
    this->loadedWorldDimensions.setColumnCount(std::stoi(lines[0]));
    this->loadedWorldDimensions.setRowCount(std::stoi(lines[1]));
    this->worldBuilder->initWorld(this->loadedWorldDimensions.getColumnCount(),
                                          this->loadedWorldDimensions.getRowCount());
}

void WorldLoader::buildTiles(const std::vector<std::string>& lines) {
    std::optional<Location> defaultKaraLocation = std::nullopt;
    std::optional<Direction> defaultKaraDirection = std::nullopt;

    for (int row = 0; row < this->loadedWorldDimensions.getRowCount(); row++) {
        for (int column = 0; column < this->loadedWorldDimensions.getColumnCount(); column++) {
            Location currentLocation(column, row);
            const char tileCode = lines[row][column];
            switch (tileCode) {
                case ' ':
                    break;
                case '#':
                    createTreeAt(currentLocation);
                    break;
                case '*':
                    createLeafAt(currentLocation);
                    break;
                case '@':
                    createMushroomAt(currentLocation);
                    break;
                case '^':
                    defaultKaraLocation = currentLocation;
                    defaultKaraDirection = Direction::NORTH;
                    break;
                case '>':
                    defaultKaraLocation = currentLocation;
                    defaultKaraDirection = Direction::EAST;
                    break;
                case 'v':
                    defaultKaraLocation = currentLocation;
                    defaultKaraDirection = Direction::SOUTH;
                    break;
                case '<':
                    defaultKaraLocation = currentLocation;
                    defaultKaraDirection = Direction::WEST;
                    break;
                default:
                    throw std::runtime_error("World error.");
            }
        }
    }
    worldBuilder->initKara(defaultKaraLocation.value(), defaultKaraDirection.value());
}

void WorldLoader::createTreeAt(const Location& currentLocation) {
    worldBuilder->addTreeToTile(currentLocation);
}

void WorldLoader::createLeafAt(const Location& currentLocation) {
    worldBuilder->addLeafToTile(currentLocation);
}

void WorldLoader::createMushroomAt(const Location& currentLocation) {
    worldBuilder->addMushroomToTile(currentLocation);
}

std::vector<std::string> WorldLoader::readLinesFromWorldResourceFile(const std::string& worldFileName) {
    std::ifstream in;

    in.open(worldFileName);
    if (!in.is_open()) {
        throw std::runtime_error("Unable to load the world from the filename: " + worldFileName);
    }
    auto result = readLinesFromWorldInputStream(in);
    if (in.bad()) {
        throw std::runtime_error("Error while loading the world from the filename: " + worldFileName);
    }
    in.close();
    return result;
}

std::vector<std::string> WorldLoader::readLinesFromWorldInputStream(std::ifstream& inputStream) {
    std::vector<std::string> result;

    std::string line;
    while (std::getline(inputStream, line)) {
        result.push_back(line);
    }

    return result;
}

}
