/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_CONCRETEWORLD_H
#define DE_UNISTUTTGART_KARA_CONCRETEWORLD_H

#include <memory>
#include <string>
#include "Stage.h"
#include "GameWorld.h"
#include "EditorWorld.h"
#include "Size.h"
#include "Location.h"
#include "Direction.h"

#include "AddLeafToTileCommandParameters.h"
#include "AddMushroomToTileCommandParameters.h"
#include "AddTreeToTileCommandParameters.h"
#include "ClearTileCommandParameters.h"
#include "InitKaraCommandParameters.h"
#include "InitWorldCommandParameters.h"

namespace kara {
class ConcreteKara;
}
namespace mpw {
class Tile;
}
namespace mpw {
class TileContent;
}
namespace kara {
class Leaf;
}
namespace kara {
class Mushroom;
}
namespace kara {
class Tree;
}
namespace mpw {
class Stage;
}
namespace kara {
class ReadOnlyKara;
}
namespace kara {
class GameKara;
}
namespace kara {
class EditorKara;
}

namespace kara {

class ConcreteWorld: public mpw::Stage,
		public virtual kara::GameWorld,
		public virtual kara::EditorWorld {

private:

	using inherited = Stage;

	std::shared_ptr<kara::ConcreteKara> kara;

public:

	ConcreteWorld();

	/// \brief returns a shared_ptr of type ConcreteWorld which shares ownership of *this
	std::shared_ptr<ConcreteWorld> shared_from_this() {
		return std::dynamic_pointer_cast<ConcreteWorld>(
				inherited::shared_from_this());
	}
	/// \brief returns a shared_ptr of const type ConcreteWorld which shares ownership of *this
	std::shared_ptr<const ConcreteWorld> shared_from_this() const {
		return std::dynamic_pointer_cast<const ConcreteWorld>(
				inherited::shared_from_this());
	}

	std::shared_ptr<const mpw::Tile> getTileAt(
			mpw::Location location) const noexcept override;

	bool isOnlyKaraAtLocation(mpw::Location location) const noexcept override;

private:

	int helper_IsOnlyKaraAtLocation_kara_currentTile_result0_contents_size(
			mpw::Location location) const noexcept;

	mpw::Location helper_IsOnlyKaraAtLocation_kara_currentTile_result0_location(
			mpw::Location location) const noexcept;

public:

	mpw::Size getWorldSize() const noexcept override;

	bool isLocationInWorld(mpw::Location location) const noexcept override;

	void addLeafToTile(commands::AddLeafToTileCommandParameters &parameters)
			override;

	void addMushroomToTile(
			commands::AddMushroomToTileCommandParameters &parameters) override;

	void addTreeToTile(commands::AddTreeToTileCommandParameters &parameters)
			override;

	void clearTile(commands::ClearTileCommandParameters &parameters) override;

	void initKara(commands::InitKaraCommandParameters &parameters) override;

	void initWorld(commands::InitWorldCommandParameters &parameters) override;

	virtual std::shared_ptr<kara::ConcreteKara> getKara() noexcept;
	virtual std::shared_ptr<const kara::ConcreteKara> getKara() const noexcept;

	framework::ObservableListProperty<mpw::Tile>& tilesProperty() noexcept
			override {
		return inherited::tilesProperty();
	}
	const framework::ObservableListProperty<mpw::Tile>& tilesProperty() const noexcept
			override {
		return inherited::tilesProperty();
	}

	framework::ObjectListView<mpw::Tile>& getTiles() noexcept override {
		return inherited::getTiles();
	}
	const framework::ObjectListView<mpw::Tile>& getTiles() const noexcept
			override {
		return inherited::getTiles();
	}

	framework::ObservableListProperty<mpw::TileContent>& tileContentsProperty() noexcept
			override {
		return inherited::tileContentsProperty();
	}
	const framework::ObservableListProperty<mpw::TileContent>& tileContentsProperty() const noexcept
			override {
		return inherited::tileContentsProperty();
	}

	framework::ObjectListView<mpw::TileContent>& getTileContents() noexcept
			override {
		return inherited::getTileContents();
	}
	const framework::ObjectListView<mpw::TileContent>& getTileContents() const noexcept
			override {
		return inherited::getTileContents();
	}

	framework::ObservablePrimitiveProperty<mpw::Size>& stageSizeProperty() noexcept
			override {
		return inherited::stageSizeProperty();
	}
	const framework::ObservablePrimitiveProperty<mpw::Size>& stageSizeProperty() const noexcept
			override {
		return inherited::stageSizeProperty();
	}

	mpw::Size getStageSize() noexcept override {
		return inherited::getStageSize();
	}
	mpw::Size getStageSize() const noexcept override {
		return inherited::getStageSize();
	}

public:

	virtual ~ConcreteWorld() = default;

	std::shared_ptr<kara::ReadOnlyKara> getReadOnlyKara() noexcept override;
	std::shared_ptr<const kara::ReadOnlyKara> getReadOnlyKara() const noexcept
			override;
	std::shared_ptr<kara::GameKara> getGameKara() noexcept override;
	std::shared_ptr<const kara::GameKara> getGameKara() const noexcept override;
	std::shared_ptr<kara::EditorKara> getEditorKara() noexcept override;
	std::shared_ptr<const kara::EditorKara> getEditorKara() const noexcept
			override;

	static constexpr unsigned cFeatureKeyKara = 4;
	using Stage::cFeatureKeyTiles;
	using Stage::cFeatureKeyTileContents;
	using Stage::cFeatureKeyStageSize;

	void setProperty(unsigned featureKey, Any value) override;
	void addToCollection(unsigned featureKey, EntityReference reference)
			override;
	void removeFromCollection(unsigned featureKey, EntityReference reference)
			override;

};

}

#endif //DE_UNISTUTTGART_KARA_CONCRETEWORLD_H

