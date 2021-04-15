#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_WORLDLOADER_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_WORLDLOADER_H

#include "KaraCore.h"
#include <vector>
#include <memory>
#include <fstream>

namespace kara {

class WorldLoader {
private:
    const std::shared_ptr<kara::WorldBuilder> worldBuilder;
    mpw::Size loadedWorldDimensions;

public:
    static std::unique_ptr<WorldLoader> initializeFor(kara::KaraGame& game);

    void loadFromResourceFile(const std::string& worldFile);

    void loadFromInputStream(std::ifstream& inputStream);

private:

    explicit WorldLoader(std::shared_ptr<kara::WorldBuilder> worldBuilder);

    void interpretLoadedWorldLines(const std::vector<std::string>& list);

    void setSizeFromStrings(const std::vector<std::string>& lines);

    void buildTiles(const std::vector<std::string>& lines);

    static std::vector<std::string> readLinesFromWorldResourceFile(const std::string& worldFileName);

    static std::vector<std::string> readLinesFromWorldInputStream(std::ifstream& inputStream);

    void createTreeAt(const mpw::Location& currentLocation);
    void createLeafAt(const mpw::Location& currentLocation);
    void createMushroomAt(const mpw::Location& currentLocation);
};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_WORLDLOADER_H
