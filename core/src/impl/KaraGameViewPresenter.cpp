#include "KaraGameViewPresenter.h"

#include "World.h"
#include "GameWorld.h"
#include "GameLog.h"
#include "CommandStack.h"
#include "GamePerformance.h"
#include "ReadOnlyKara.h"
#include "Actor.h"

#include "ViewModelCellLayer.h"

#include "CollectionHelpers.hpp"
#include <utility>

using namespace mpw;
using namespace kara;
using namespace collectionhelpers;
using namespace framework;

namespace viewmodel {

KaraGameViewPresenter::KaraGameViewPresenter(std::shared_ptr<kara::KaraGame> game)
        : inherited(game), game(std::move(game)) {
}

const ObservablePrimitiveProperty<mpw::Size>& KaraGameViewPresenter::getStageSizeFromConcreteStage() {
    return this->game->getWorld()->getInternalWorld()->stageSizeProperty();
}

const framework::ObservableListProperty<mpw::Tile>& KaraGameViewPresenter::getTilesPropertyFromConcreteStage() {
    return game->getWorld()->getInternalWorld()->tilesProperty();
}

void KaraGameViewPresenter::onSetTileNodeAtForCell(ViewModelCell& cell, const mpw::Tile& tile) {
    configureTreeImageView(cell, tile);
    configureMushroomImageView(cell, tile);
    configureLeafImageView(cell, tile);
    auto karaOptional = findKaraOnTile(tile);
    if (karaOptional.has_value()) {
        configureKaraImageView(cell, *karaOptional.value());
    }
}

std::optional<std::shared_ptr<const kara::ReadOnlyKara>> KaraGameViewPresenter::findKaraOnTile(const Tile& tile) {
    const auto listOfKaras = type_select<kara::ReadOnlyKara>(tile.getContents());
    if (listOfKaras.empty()) {
        return std::nullopt;
    }
    return listOfKaras.front();
}

void KaraGameViewPresenter::configureTreeImageView(ViewModelCell& cell, const Tile& tile) {
    auto layer = std::make_shared<ViewModelCellLayer>();
    layer->setImageName("Tree");
    refreshTreeLayer(*layer, tile);

    cell.addToLayers(layer);
}

void KaraGameViewPresenter::refreshTreeLayer(ViewModelCellLayer& layer, const Tile& tile) {
    layer.setVisible(!getTreesOfTile(tile).empty());
}

void KaraGameViewPresenter::configureLeafImageView(ViewModelCell& cell, const Tile& tile) {
    auto layer = std::make_shared<ViewModelCellLayer>();
    layer->setImageName("Leaf");
    refreshLeafLayer(*layer, tile);

    cell.addToLayers(layer);
}

void KaraGameViewPresenter::refreshLeafLayer(ViewModelCellLayer& layer, const Tile& tile) {
    layer.setVisible(!getLeafsOfTile(tile).empty());
}

void KaraGameViewPresenter::configureMushroomImageView(ViewModelCell& cell, const Tile& tile) {
    auto layer = std::make_shared<ViewModelCellLayer>();
    layer->setImageName("Mushroom");
    refreshMushroomLayer(*layer, tile);

    cell.addToLayers(layer);
}

void KaraGameViewPresenter::refreshMushroomLayer(ViewModelCellLayer& layer, const Tile& tile) {
    layer.setVisible(!getMushroomsOfTile(tile).empty());
}

void KaraGameViewPresenter::configureKaraImageView(ViewModelCell& cell, const ReadOnlyKara& kara) {
    auto layer = std::make_shared<ViewModelCellLayer>();
    layer->setImageName("Kara");

    addKaraDirectionListener(layer, kara);
    refreshKaraLayer(*layer, kara);

    cell.addToLayers(layer);
}

/*
 * Adds a listener for the change of the direction, to also update the layers if Kara turns left.
 * Note: Since onSetTileNodeAtForCell() is called every time the contents of a tile changes, Kara might
 * be configured multiple times. Avoid, that multiple direction listeners are attached.
 */
void KaraGameViewPresenter::addKaraDirectionListener(std::shared_ptr<ViewModelCellLayer> karaLayer, const ReadOnlyKara& kara) {
    if (karaDirectionChangeListenerId.has_value()) {
        kara.directionProperty().removeListener(karaDirectionChangeListenerId.value());
    }
    karaDirectionChangeListenerId = kara.directionProperty().addListener(
            [this, &kara, karaLayer](Direction oldValue, Direction newValue) {
                auto lock = getSemaphore().lock();
                refreshKaraLayer(*karaLayer, kara);
            });
}

void KaraGameViewPresenter::refreshKaraLayer(ViewModelCellLayer& layer, const kara::ReadOnlyKara& kara) {
    layer.setVisible(kara.getCurrentTile() != nullptr);
    if (kara.getCurrentTile() == nullptr) {
        return;
    }
    layer.setRotation(getRotationForDirection(kara.getDirection()));
}

std::list<std::shared_ptr<const kara::Tree>> KaraGameViewPresenter::getTreesOfTile(const Tile& tile) {
    return type_select<kara::Tree>(tile.getContents());
}

std::list<std::shared_ptr<const kara::Leaf>> KaraGameViewPresenter::getLeafsOfTile(const Tile& tile) {
    return type_select<kara::Leaf>(tile.getContents());
}

std::list<std::shared_ptr<const kara::Mushroom>> KaraGameViewPresenter::getMushroomsOfTile(const Tile& tile) {
    return type_select<kara::Mushroom>(tile.getContents());
}

}
