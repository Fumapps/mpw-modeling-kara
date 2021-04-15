/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_READONLYKARA_H
#define DE_UNISTUTTGART_KARA_READONLYKARA_H

#include <memory>
#include <string>
#include "ObservableProperties.h"
#include "ObservableListProperties.h"
#include "SimpleListProperties.h"
#include "Entity.h"
#include "Direction.h"
#include "Location.h"

namespace mpw {
class Tile;
}
namespace mpw {
class Stage;
}
namespace kara {
class ConcreteKara;
}
namespace mpw {
class TileContent;
}
namespace kara {
class Leaf;
}
namespace kara {
class Tree;
}
namespace kara {
class Mushroom;
}

namespace kara {

class ReadOnlyKara: public virtual basetypes::Entity {

public:

	virtual ~ReadOnlyKara() = default;

	/// \brief returns a shared_ptr of type ReadOnlyKara which shares ownership of *this
	std::shared_ptr<ReadOnlyKara> shared_from_this() {
		return std::dynamic_pointer_cast < ReadOnlyKara
				> (basetypes::Entity::shared_from_this());
	}
	/// \brief returns a shared_ptr of const type ReadOnlyKara which shares ownership of *this
	std::shared_ptr<const ReadOnlyKara> shared_from_this() const {
		return std::dynamic_pointer_cast<const ReadOnlyKara>(
				basetypes::Entity::shared_from_this());
	}

	virtual std::shared_ptr<mpw::Tile> getCurrentTile() noexcept = 0;
	virtual std::shared_ptr<const mpw::Tile> getCurrentTile() const noexcept = 0;
	virtual framework::ObservableObjectProperty<mpw::Tile>& currentTileProperty() noexcept = 0;
	virtual const framework::ObservableObjectProperty<mpw::Tile>& currentTileProperty() const noexcept = 0;

	virtual std::shared_ptr<mpw::Stage> getStage() noexcept = 0;
	virtual std::shared_ptr<const mpw::Stage> getStage() const noexcept = 0;
	virtual framework::ObservableObjectProperty<mpw::Stage>& stageProperty() noexcept = 0;
	virtual const framework::ObservableObjectProperty<mpw::Stage>& stageProperty() const noexcept = 0;

	/**
	 * Get the current kara looking direction.
	 */
	virtual mpw::Direction getDirection() noexcept = 0;
	/**
	 * Get the current kara looking direction.
	 */
	virtual mpw::Direction getDirection() const noexcept = 0;
	virtual framework::ObservablePrimitiveProperty<mpw::Direction>& directionProperty() noexcept = 0;
	virtual const framework::ObservablePrimitiveProperty<mpw::Direction>& directionProperty() const noexcept = 0;

	/**
	 * Checks the kara's current tile for leaf.
	 */
	virtual bool onLeaf() const noexcept = 0;

	/**
	 * Checks if a tree is at the left of the kara.
	 */
	virtual bool treeLeft() const noexcept = 0;

	/**
	 * Checks if a mushroom is at the front of the kara.
	 */
	virtual bool mushroomFront() const noexcept = 0;

	/**
	 * Get the current kara's location.
	 */
	virtual mpw::Location getLocation() const noexcept = 0;

	/**
	 * Checks if a tree is at the right of the kara.
	 */
	virtual bool treeRight() const noexcept = 0;

	/**
	 * Checks if a tree is at the front of the kara.
	 */
	virtual bool treeFront() const noexcept = 0;

};

}

#endif //DE_UNISTUTTGART_KARA_READONLYKARA_H

