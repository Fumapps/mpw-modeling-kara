/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_READONLYWORLD_H
#define DE_UNISTUTTGART_KARA_READONLYWORLD_H

#include <memory>
#include <string>
#include <list>
#include <unordered_set>
#include "ObservableProperties.h"
#include "ObservableListProperties.h"
#include "SimpleListProperties.h"
#include "Entity.h"
#include "Size.h"
#include "Location.h"

namespace mpw {
class Tile;
}
namespace mpw {
class TileContent;
}
namespace kara {
class ConcreteWorld;
}
namespace kara {
class ConcreteKara;
}
namespace kara {
class ReadOnlyKara;
}

namespace kara {

class ReadOnlyWorld: public virtual basetypes::Entity {

public:

	virtual ~ReadOnlyWorld() = default;

	/// \brief returns a shared_ptr of type ReadOnlyWorld which shares ownership of *this
	std::shared_ptr<ReadOnlyWorld> shared_from_this() {
		return std::dynamic_pointer_cast < ReadOnlyWorld
				> (basetypes::Entity::shared_from_this());
	}
	/// \brief returns a shared_ptr of const type ReadOnlyWorld which shares ownership of *this
	std::shared_ptr<const ReadOnlyWorld> shared_from_this() const {
		return std::dynamic_pointer_cast<const ReadOnlyWorld>(
				basetypes::Entity::shared_from_this());
	}

	virtual framework::ObjectListView<mpw::Tile>& getTiles() noexcept = 0;
	virtual const framework::ObjectListView<mpw::Tile>& getTiles() const noexcept = 0;
	virtual framework::ObservableListProperty<mpw::Tile>& tilesProperty() noexcept = 0;
	virtual const framework::ObservableListProperty<mpw::Tile>& tilesProperty() const noexcept = 0;

	virtual framework::ObjectListView<mpw::TileContent>& getTileContents() noexcept = 0;
	virtual const framework::ObjectListView<mpw::TileContent>& getTileContents() const noexcept = 0;
	virtual framework::ObservableListProperty<mpw::TileContent>& tileContentsProperty() noexcept = 0;
	virtual const framework::ObservableListProperty<mpw::TileContent>& tileContentsProperty() const noexcept = 0;

	virtual mpw::Size getStageSize() noexcept = 0;
	virtual mpw::Size getStageSize() const noexcept = 0;
	virtual framework::ObservablePrimitiveProperty<mpw::Size>& stageSizeProperty() noexcept = 0;
	virtual const framework::ObservablePrimitiveProperty<mpw::Size>& stageSizeProperty() const noexcept = 0;

	/**
	 * For a given location, return the internal tile object.
	 */
	virtual std::shared_ptr<const mpw::Tile> getTileAt(
			mpw::Location location) const noexcept = 0;

	/**
	 * For a given location, check whether only Kara is placed on the tile.
	 */
	virtual bool isOnlyKaraAtLocation(mpw::Location location) const noexcept = 0;

	/**
	 * Return the size of the current world. From the size you can retrieve the number of rows and colums.
	 */
	virtual mpw::Size getWorldSize() const noexcept = 0;

	/**
	 * For a given location, tests whether the location is inside the bound of the world.
	 */
	virtual bool isLocationInWorld(mpw::Location location) const noexcept = 0;

	virtual std::shared_ptr<kara::ReadOnlyKara> getReadOnlyKara() noexcept = 0;
	virtual std::shared_ptr<const kara::ReadOnlyKara> getReadOnlyKara() const noexcept = 0;

};

}

#endif //DE_UNISTUTTGART_KARA_READONLYWORLD_H

