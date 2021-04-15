#include <CollectionHelpers.hpp>
#include "GameStringifier.h"

#include "Tile.h"
#include "Tree.h"
#include "Leaf.h"
#include "Mushroom.h"
#include "World.h"
#include "Kara.h"
#include "GameWorld.h"
#include "GameKara.h"
#include "GamePerformance.h"

#include "WorldBuilder.h"
#include "DirectionTestHelper.h"
#include "TestUtils.h"

using namespace mpw;
using namespace kara;

namespace util {

static void handleLine(WorldBuilder& worldBuilder, int y, const std::string& part);
static void handleCell(WorldBuilder& worldBuilder, int x, int y, char cell);

std::shared_ptr<kara::KaraGame> GameStringifier::createFromStringStarted(const std::string& map) {
    auto game = createFromString(map);
    game->startGame();
    return game;
}

std::shared_ptr<kara::KaraGame> GameStringifier::createFromString(const std::string& map) {
    auto game = KaraGame::create();

    std::vector<std::string> parts = TestUtils::split(";", map);
    int height = static_cast<int>(parts.size());
    int width = height > 0 ? static_cast<int>(parts[0].length()) : 0;

    auto worldBuilder = std::make_shared<WorldBuilder>(game);
    worldBuilder->initWorld(width, height);

    for (int y = 0; y < height; y++) {
        handleLine(*worldBuilder, y, parts[y]);
    }

    game->getPerformance()->setDelayEnabled(false);
    return game;
}

static void handleLine(WorldBuilder& worldBuilder, int y, const std::string& part) {
    for (int x = 0; x < part.length(); x++) {
        handleCell(worldBuilder, x, y, part[x]);
    }
}

static void handleCell(WorldBuilder& worldBuilder, int x, int y, char cell) {
    switch (cell) {
        case '>':
        case '<':
        case '^':
        case 'v':
            worldBuilder.initKara(x, y, DirectionTestHelper::toDirection(cell));
            break;
        case '*':
            worldBuilder.addLeafToTile(x, y);
            break;
        case '#':
            worldBuilder.addTreeToTile(x, y);
            break;
        case '@':
            worldBuilder.addMushroomToTile(x, y);
            break;
        default:;
    }
}

static void iterateTiles(const KaraGame& game, const std::function<void(const Tile&)>& lambda);

std::string GameStringifier::toString(const KaraGame& game) {
    std::string actual;

    auto kara = game.getWorld()->getKara()->getInternalKara();
    iterateTiles(game, [&](const Tile& currentTile) {
        if (kara->getCurrentTile().get() == &currentTile) {
            actual += util::DirectionTestHelper::toDirection(kara->getDirection());
        } else if (!collectionhelpers::type_select<Tree>(currentTile.getContents()).empty()) {
            actual += '#';
        } else if (!collectionhelpers::type_select<Leaf>(currentTile.getContents()).empty()) {
            actual += '*';
        } else if (!collectionhelpers::type_select<Mushroom>(currentTile.getContents()).empty()) {
            actual += '@';
        } else {
            actual += ' ';
        }

        if (currentTile.getEast() == nullptr) {
            actual += ';';
        }
    });

    return actual;
}

static void iterateTiles(const KaraGame& game, const std::function<void(const Tile&)>& lambda) {
    auto& tiles = game.getWorld()->getInternalWorld()->getTiles();
    auto upperLeftTile = collectionhelpers::get_at(tiles, 0).value();
    auto firstOfRowTile = upperLeftTile;

    std::shared_ptr<const Tile> currentTile = upperLeftTile;

    while (currentTile != nullptr) {
        lambda(*currentTile);

        if (currentTile->getEast() == nullptr) {
            firstOfRowTile = firstOfRowTile->getSouth();
            currentTile = firstOfRowTile;
        } else {
            currentTile = currentTile->getEast();
        }
    }
}

}
