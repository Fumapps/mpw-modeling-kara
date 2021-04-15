/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_CONCRETEKARA_H
#define DE_UNISTUTTGART_KARA_CONCRETEKARA_H

#include <memory>
#include <string>
#include "Actor.h"
#include "GameKara.h"
#include "EditorKara.h"
#include "Direction.h"
#include "Location.h"

#include "MoveCommandParameters.h"
#include "PutLeafCommandParameters.h"
#include "RemoveLeafCommandParameters.h"
#include "TurnLeftCommandParameters.h"
#include "TurnRightCommandParameters.h"
#include "WriteCommandParameters.h"

namespace mpw {
class Tile;
}
namespace mpw {
class Stage;
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

class ConcreteKara: public mpw::Actor,
		public virtual kara::GameKara,
		public virtual kara::EditorKara {

private:

	using inherited = Actor;

public:

	ConcreteKara();

	/// \brief returns a shared_ptr of type ConcreteKara which shares ownership of *this
	std::shared_ptr<ConcreteKara> shared_from_this() {
		return std::dynamic_pointer_cast < ConcreteKara
				> (inherited::shared_from_this());
	}
	/// \brief returns a shared_ptr of const type ConcreteKara which shares ownership of *this
	std::shared_ptr<const ConcreteKara> shared_from_this() const {
		return std::dynamic_pointer_cast<const ConcreteKara>(
				inherited::shared_from_this());
	}

	bool onLeaf() const noexcept override;

private:

	bool helper_OnLeaf_currentTile_result0_contents_type_selectLeaf_not_empty() const noexcept;

public:

	bool treeLeft() const noexcept override;

private:

	bool helper_TreeLeft_currentTile_result0_east_result1_contents_type_selectTree_not_empty() const noexcept;

	bool helper_TreeLeft_currentTile_result0_north_result1_contents_type_selectTree_not_empty() const noexcept;

	bool helper_TreeLeft_currentTile_result0_south_result1_contents_type_selectTree_not_empty() const noexcept;

	bool helper_TreeLeft_currentTile_result0_west_result1_contents_type_selectTree_not_empty() const noexcept;

public:

	bool mushroomFront() const noexcept override;

private:

	bool helper_MushroomFront_currentTile_result0_east_result1_contents_type_selectMushroom_not_empty() const noexcept;

	bool helper_MushroomFront_currentTile_result0_west_result1_contents_type_selectMushroom_not_empty() const noexcept;

	bool helper_MushroomFront_currentTile_result0_north_result1_contents_type_selectMushroom_not_empty() const noexcept;

	bool helper_MushroomFront_currentTile_result0_south_result1_contents_type_selectMushroom_not_empty() const noexcept;

public:

	mpw::Location getLocation() const noexcept override;

private:

	mpw::Location helper_GetLocation_currentTile_result0_location() const noexcept;

public:

	bool treeRight() const noexcept override;

private:

	bool helper_TreeRight_currentTile_result0_west_result1_contents_type_selectTree_not_empty() const noexcept;

	bool helper_TreeRight_currentTile_result0_south_result1_contents_type_selectTree_not_empty() const noexcept;

	bool helper_TreeRight_currentTile_result0_north_result1_contents_type_selectTree_not_empty() const noexcept;

	bool helper_TreeRight_currentTile_result0_east_result1_contents_type_selectTree_not_empty() const noexcept;

public:

	bool treeFront() const noexcept override;

private:

	bool helper_TreeFront_currentTile_result0_north_result1_contents_type_selectTree_not_empty() const noexcept;

	bool helper_TreeFront_currentTile_result0_south_result1_contents_type_selectTree_not_empty() const noexcept;

	bool helper_TreeFront_currentTile_result0_west_result1_contents_type_selectTree_not_empty() const noexcept;

	bool helper_TreeFront_currentTile_result0_east_result1_contents_type_selectTree_not_empty() const noexcept;

public:

	void move(commands::MoveCommandParameters &parameters) override;

	void putLeaf(commands::PutLeafCommandParameters &parameters) override;

	void removeLeaf(commands::RemoveLeafCommandParameters &parameters) override;

	void turnLeft(commands::TurnLeftCommandParameters &parameters) override;

	void turnRight(commands::TurnRightCommandParameters &parameters) override;

	void write(commands::WriteCommandParameters &parameters) override;

	framework::ObservableObjectProperty<mpw::Tile>& currentTileProperty() noexcept
			override {
		return inherited::currentTileProperty();
	}
	const framework::ObservableObjectProperty<mpw::Tile>& currentTileProperty() const noexcept
			override {
		return inherited::currentTileProperty();
	}

	std::shared_ptr<mpw::Tile> getCurrentTile() noexcept override {
		return inherited::getCurrentTile();
	}
	std::shared_ptr<const mpw::Tile> getCurrentTile() const noexcept override {
		return inherited::getCurrentTile();
	}

	framework::ObservableObjectProperty<mpw::Stage>& stageProperty() noexcept
			override {
		return inherited::stageProperty();
	}
	const framework::ObservableObjectProperty<mpw::Stage>& stageProperty() const noexcept
			override {
		return inherited::stageProperty();
	}

	std::shared_ptr<mpw::Stage> getStage() noexcept override {
		return inherited::getStage();
	}
	std::shared_ptr<const mpw::Stage> getStage() const noexcept override {
		return inherited::getStage();
	}

	framework::ObservablePrimitiveProperty<mpw::Direction>& directionProperty() noexcept
			override {
		return inherited::directionProperty();
	}
	const framework::ObservablePrimitiveProperty<mpw::Direction>& directionProperty() const noexcept
			override {
		return inherited::directionProperty();
	}

	mpw::Direction getDirection() noexcept override {
		return inherited::getDirection();
	}
	mpw::Direction getDirection() const noexcept override {
		return inherited::getDirection();
	}

public:

	virtual ~ConcreteKara() = default;

	using Actor::cFeatureKeyCurrentTile;
	using Actor::cFeatureKeyStage;
	using Actor::cFeatureKeyDirection;

	void setProperty(unsigned featureKey, Any value) override;
	void addToCollection(unsigned featureKey, EntityReference reference)
			override;
	void removeFromCollection(unsigned featureKey, EntityReference reference)
			override;

};

}

#endif //DE_UNISTUTTGART_KARA_CONCRETEKARA_H

