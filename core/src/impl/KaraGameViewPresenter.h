#ifndef DE_UNISTUTTGART_KARA_KaraGameViewPresenter_H
#define DE_UNISTUTTGART_KARA_KaraGameViewPresenter_H

#include "GameViewPresenterBase.h"

#include "KaraGame.h"
#include "Tile.h"
#include "Tree.h"
#include "Leaf.h"
#include "Mushroom.h"
#include "ReadOnlyKara.h"

#include <unordered_map>

namespace viewmodel {

class KaraGameViewPresenter : public GameViewPresenterBase {
private:
    using inherited = GameViewPresenterBase;

    const std::shared_ptr<kara::KaraGame> game;

    std::optional<unsigned int> karaDirectionChangeListenerId;

public:

    explicit KaraGameViewPresenter(std::shared_ptr<kara::KaraGame> game);

protected:

    const framework::ObservablePrimitiveProperty<mpw::Size>& getStageSizeFromConcreteStage() override;

    const framework::ObservableListProperty<mpw::Tile>& getTilesPropertyFromConcreteStage() override;

    void onSetTileNodeAtForCell(ViewModelCell& cell, const mpw::Tile& tile) override;

private:

    void configureTreeImageView(ViewModelCell& cell, const mpw::Tile& tile);
    void refreshTreeLayer(ViewModelCellLayer& layer, const mpw::Tile& tile);

    void configureLeafImageView(ViewModelCell& cell, const mpw::Tile& tile);
    void refreshLeafLayer(ViewModelCellLayer& layer, const mpw::Tile& tile);

    void configureMushroomImageView(ViewModelCell& cell, const mpw::Tile& tile);
    void refreshMushroomLayer(ViewModelCellLayer& layer, const mpw::Tile& tile);

    void configureKaraImageView(ViewModelCell& cell, const kara::ReadOnlyKara& kara);
    void addKaraDirectionListener(std::shared_ptr<ViewModelCellLayer> karaLayer, const kara::ReadOnlyKara& kara);
    void refreshKaraLayer(ViewModelCellLayer& layer, const kara::ReadOnlyKara& kara);

    static std::optional<std::shared_ptr<const kara::ReadOnlyKara>> findKaraOnTile(const mpw::Tile& tile);
    static std::list<std::shared_ptr<const kara::Tree>> getTreesOfTile(const mpw::Tile& tile);
    static std::list<std::shared_ptr<const kara::Leaf>> getLeafsOfTile(const mpw::Tile& tile);
    static std::list<std::shared_ptr<const kara::Mushroom>> getMushroomsOfTile(const mpw::Tile& tile);
};

}

#endif //DE_UNISTUTTGART_KARA_KaraGameViewPresenter_H
