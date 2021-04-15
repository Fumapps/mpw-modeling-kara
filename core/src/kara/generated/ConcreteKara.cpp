/*
 * This file is generated. Do not change it manually.
 */

#include "ConcreteKara.h"

#include <stdexcept>

#include "CollectionHelpers.hpp"
#include "CommandStack.h"
#include "Tile.h"
#include "Stage.h"
#include "TileContent.h"
#include "Leaf.h"
#include "Tree.h"
#include "Mushroom.h"

#include "MoveCommand.h"
#include "PutLeafCommand.h"
#include "RemoveLeafCommand.h"
#include "TurnLeftCommand.h"
#include "TurnRightCommand.h"
#include "WriteCommand.h"

namespace kara {

ConcreteKara::ConcreteKara() {

}

bool ConcreteKara::onLeaf() const noexcept {
	try {
		return helper_OnLeaf_currentTile_result0_contents_type_selectLeaf_not_empty();
	} catch (...) {
		return false;
	}
}

bool ConcreteKara::helper_OnLeaf_currentTile_result0_contents_type_selectLeaf_not_empty() const noexcept {
	std::shared_ptr<const mpw::Tile> result0 = this->getCurrentTile();
	if (result0 == nullptr) {
		return false;
	}
	bool result1 = collectionhelpers::type_select < kara::Leaf
			> (result0->getContents()).size() > 0;
	return result1;
}

bool ConcreteKara::treeLeft() const noexcept {
	try {
		return (this->getDirection() == mpw::Direction::WEST) ? (helper_TreeLeft_currentTile_result0_south_result1_contents_type_selectTree_not_empty()) :
				true && (this->getDirection() == mpw::Direction::EAST) ? (helper_TreeLeft_currentTile_result0_north_result1_contents_type_selectTree_not_empty()) :
				true && (this->getDirection() == mpw::Direction::NORTH) ? (helper_TreeLeft_currentTile_result0_west_result1_contents_type_selectTree_not_empty()) :
				true && (this->getDirection() == mpw::Direction::SOUTH) ? (helper_TreeLeft_currentTile_result0_east_result1_contents_type_selectTree_not_empty()) :
						true;
	} catch (...) {
		return false;
	}
}

bool ConcreteKara::helper_TreeLeft_currentTile_result0_east_result1_contents_type_selectTree_not_empty() const noexcept {
	std::shared_ptr<const mpw::Tile> result0 = this->getCurrentTile();
	if (result0 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result1 = result0->getEast();
	if (result1 == nullptr) {
		return false;
	}
	bool result2 = collectionhelpers::type_select < kara::Tree
			> (result1->getContents()).size() > 0;
	return result2;
}

bool ConcreteKara::helper_TreeLeft_currentTile_result0_north_result1_contents_type_selectTree_not_empty() const noexcept {
	std::shared_ptr<const mpw::Tile> result0 = this->getCurrentTile();
	if (result0 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result1 = result0->getNorth();
	if (result1 == nullptr) {
		return false;
	}
	bool result2 = collectionhelpers::type_select < kara::Tree
			> (result1->getContents()).size() > 0;
	return result2;
}

bool ConcreteKara::helper_TreeLeft_currentTile_result0_south_result1_contents_type_selectTree_not_empty() const noexcept {
	std::shared_ptr<const mpw::Tile> result0 = this->getCurrentTile();
	if (result0 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result1 = result0->getSouth();
	if (result1 == nullptr) {
		return false;
	}
	bool result2 = collectionhelpers::type_select < kara::Tree
			> (result1->getContents()).size() > 0;
	return result2;
}

bool ConcreteKara::helper_TreeLeft_currentTile_result0_west_result1_contents_type_selectTree_not_empty() const noexcept {
	std::shared_ptr<const mpw::Tile> result0 = this->getCurrentTile();
	if (result0 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result1 = result0->getWest();
	if (result1 == nullptr) {
		return false;
	}
	bool result2 = collectionhelpers::type_select < kara::Tree
			> (result1->getContents()).size() > 0;
	return result2;
}

bool ConcreteKara::mushroomFront() const noexcept {
	try {
		return (this->getDirection() == mpw::Direction::WEST) ? (helper_MushroomFront_currentTile_result0_west_result1_contents_type_selectMushroom_not_empty()) :
				true && (this->getDirection() == mpw::Direction::EAST) ? (helper_MushroomFront_currentTile_result0_east_result1_contents_type_selectMushroom_not_empty()) :
				true && (this->getDirection() == mpw::Direction::NORTH) ? (helper_MushroomFront_currentTile_result0_north_result1_contents_type_selectMushroom_not_empty()) :
				true && (this->getDirection() == mpw::Direction::SOUTH) ? (helper_MushroomFront_currentTile_result0_south_result1_contents_type_selectMushroom_not_empty()) :
						true;
	} catch (...) {
		return false;
	}
}

bool ConcreteKara::helper_MushroomFront_currentTile_result0_east_result1_contents_type_selectMushroom_not_empty() const noexcept {
	std::shared_ptr<const mpw::Tile> result0 = this->getCurrentTile();
	if (result0 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result1 = result0->getEast();
	if (result1 == nullptr) {
		return false;
	}
	bool result2 = collectionhelpers::type_select < kara::Mushroom
			> (result1->getContents()).size() > 0;
	return result2;
}

bool ConcreteKara::helper_MushroomFront_currentTile_result0_west_result1_contents_type_selectMushroom_not_empty() const noexcept {
	std::shared_ptr<const mpw::Tile> result0 = this->getCurrentTile();
	if (result0 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result1 = result0->getWest();
	if (result1 == nullptr) {
		return false;
	}
	bool result2 = collectionhelpers::type_select < kara::Mushroom
			> (result1->getContents()).size() > 0;
	return result2;
}

bool ConcreteKara::helper_MushroomFront_currentTile_result0_north_result1_contents_type_selectMushroom_not_empty() const noexcept {
	std::shared_ptr<const mpw::Tile> result0 = this->getCurrentTile();
	if (result0 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result1 = result0->getNorth();
	if (result1 == nullptr) {
		return false;
	}
	bool result2 = collectionhelpers::type_select < kara::Mushroom
			> (result1->getContents()).size() > 0;
	return result2;
}

bool ConcreteKara::helper_MushroomFront_currentTile_result0_south_result1_contents_type_selectMushroom_not_empty() const noexcept {
	std::shared_ptr<const mpw::Tile> result0 = this->getCurrentTile();
	if (result0 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result1 = result0->getSouth();
	if (result1 == nullptr) {
		return false;
	}
	bool result2 = collectionhelpers::type_select < kara::Mushroom
			> (result1->getContents()).size() > 0;
	return result2;
}

mpw::Location ConcreteKara::getLocation() const noexcept {
	try {
		return helper_GetLocation_currentTile_result0_location();
	} catch (...) {
		return {};
	}
}

mpw::Location ConcreteKara::helper_GetLocation_currentTile_result0_location() const noexcept {
	std::shared_ptr<const mpw::Tile> result0 = this->getCurrentTile();
	if (result0 == nullptr) {
		return {};
	}
	mpw::Location result1 = result0->getLocation();
	return result1;
}

bool ConcreteKara::treeRight() const noexcept {
	try {
		return (this->getDirection() == mpw::Direction::WEST) ? (helper_TreeRight_currentTile_result0_north_result1_contents_type_selectTree_not_empty()) :
				true && (this->getDirection() == mpw::Direction::EAST) ? (helper_TreeRight_currentTile_result0_south_result1_contents_type_selectTree_not_empty()) :
				true && (this->getDirection() == mpw::Direction::NORTH) ? (helper_TreeRight_currentTile_result0_east_result1_contents_type_selectTree_not_empty()) :
				true && (this->getDirection() == mpw::Direction::SOUTH) ? (helper_TreeRight_currentTile_result0_west_result1_contents_type_selectTree_not_empty()) :
						true;
	} catch (...) {
		return false;
	}
}

bool ConcreteKara::helper_TreeRight_currentTile_result0_west_result1_contents_type_selectTree_not_empty() const noexcept {
	std::shared_ptr<const mpw::Tile> result0 = this->getCurrentTile();
	if (result0 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result1 = result0->getWest();
	if (result1 == nullptr) {
		return false;
	}
	bool result2 = collectionhelpers::type_select < kara::Tree
			> (result1->getContents()).size() > 0;
	return result2;
}

bool ConcreteKara::helper_TreeRight_currentTile_result0_south_result1_contents_type_selectTree_not_empty() const noexcept {
	std::shared_ptr<const mpw::Tile> result0 = this->getCurrentTile();
	if (result0 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result1 = result0->getSouth();
	if (result1 == nullptr) {
		return false;
	}
	bool result2 = collectionhelpers::type_select < kara::Tree
			> (result1->getContents()).size() > 0;
	return result2;
}

bool ConcreteKara::helper_TreeRight_currentTile_result0_north_result1_contents_type_selectTree_not_empty() const noexcept {
	std::shared_ptr<const mpw::Tile> result0 = this->getCurrentTile();
	if (result0 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result1 = result0->getNorth();
	if (result1 == nullptr) {
		return false;
	}
	bool result2 = collectionhelpers::type_select < kara::Tree
			> (result1->getContents()).size() > 0;
	return result2;
}

bool ConcreteKara::helper_TreeRight_currentTile_result0_east_result1_contents_type_selectTree_not_empty() const noexcept {
	std::shared_ptr<const mpw::Tile> result0 = this->getCurrentTile();
	if (result0 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result1 = result0->getEast();
	if (result1 == nullptr) {
		return false;
	}
	bool result2 = collectionhelpers::type_select < kara::Tree
			> (result1->getContents()).size() > 0;
	return result2;
}

bool ConcreteKara::treeFront() const noexcept {
	try {
		return (this->getDirection() == mpw::Direction::WEST) ? (helper_TreeFront_currentTile_result0_west_result1_contents_type_selectTree_not_empty()) :
				true && (this->getDirection() == mpw::Direction::EAST) ? (helper_TreeFront_currentTile_result0_east_result1_contents_type_selectTree_not_empty()) :
				true && (this->getDirection() == mpw::Direction::NORTH) ? (helper_TreeFront_currentTile_result0_north_result1_contents_type_selectTree_not_empty()) :
				true && (this->getDirection() == mpw::Direction::SOUTH) ? (helper_TreeFront_currentTile_result0_south_result1_contents_type_selectTree_not_empty()) :
						true;
	} catch (...) {
		return false;
	}
}

bool ConcreteKara::helper_TreeFront_currentTile_result0_north_result1_contents_type_selectTree_not_empty() const noexcept {
	std::shared_ptr<const mpw::Tile> result0 = this->getCurrentTile();
	if (result0 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result1 = result0->getNorth();
	if (result1 == nullptr) {
		return false;
	}
	bool result2 = collectionhelpers::type_select < kara::Tree
			> (result1->getContents()).size() > 0;
	return result2;
}

bool ConcreteKara::helper_TreeFront_currentTile_result0_south_result1_contents_type_selectTree_not_empty() const noexcept {
	std::shared_ptr<const mpw::Tile> result0 = this->getCurrentTile();
	if (result0 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result1 = result0->getSouth();
	if (result1 == nullptr) {
		return false;
	}
	bool result2 = collectionhelpers::type_select < kara::Tree
			> (result1->getContents()).size() > 0;
	return result2;
}

bool ConcreteKara::helper_TreeFront_currentTile_result0_west_result1_contents_type_selectTree_not_empty() const noexcept {
	std::shared_ptr<const mpw::Tile> result0 = this->getCurrentTile();
	if (result0 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result1 = result0->getWest();
	if (result1 == nullptr) {
		return false;
	}
	bool result2 = collectionhelpers::type_select < kara::Tree
			> (result1->getContents()).size() > 0;
	return result2;
}

bool ConcreteKara::helper_TreeFront_currentTile_result0_east_result1_contents_type_selectTree_not_empty() const noexcept {
	std::shared_ptr<const mpw::Tile> result0 = this->getCurrentTile();
	if (result0 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result1 = result0->getEast();
	if (result1 == nullptr) {
		return false;
	}
	bool result2 = collectionhelpers::type_select < kara::Tree
			> (result1->getContents()).size() > 0;
	return result2;
}

void ConcreteKara::move(commands::MoveCommandParameters &parameters) {
	parameters.self = this->shared_from_this();
	auto command = std::make_shared < commands::MoveCommand > (parameters);
	parameters.commandStack.execute(command);
}

void ConcreteKara::putLeaf(commands::PutLeafCommandParameters &parameters) {
	parameters.self = this->shared_from_this();
	auto command = std::make_shared < commands::PutLeafCommand > (parameters);
	parameters.commandStack.execute(command);
}

void ConcreteKara::removeLeaf(
		commands::RemoveLeafCommandParameters &parameters) {
	parameters.self = this->shared_from_this();
	auto command = std::make_shared < commands::RemoveLeafCommand
			> (parameters);
	parameters.commandStack.execute(command);
}

void ConcreteKara::turnLeft(commands::TurnLeftCommandParameters &parameters) {
	parameters.self = this->shared_from_this();
	auto command = std::make_shared < commands::TurnLeftCommand > (parameters);
	parameters.commandStack.execute(command);
}

void ConcreteKara::turnRight(commands::TurnRightCommandParameters &parameters) {
	parameters.self = this->shared_from_this();
	auto command = std::make_shared < commands::TurnRightCommand > (parameters);
	parameters.commandStack.execute(command);
}

void ConcreteKara::write(commands::WriteCommandParameters &parameters) {
	parameters.self = this->shared_from_this();
	auto command = std::make_shared < commands::WriteCommand > (parameters);
	parameters.commandStack.execute(command);
}

void ConcreteKara::setProperty(unsigned featureKey, Any value) {
	switch (featureKey) {
	}

	inherited::setProperty(featureKey, value);
}

void ConcreteKara::addToCollection(unsigned featureKey,
		EntityReference reference) {
	switch (featureKey) {
	}

	inherited::addToCollection(featureKey, reference);
}

void ConcreteKara::removeFromCollection(unsigned featureKey,
		EntityReference reference) {
	switch (featureKey) {
	}

	inherited::removeFromCollection(featureKey, reference);
}

}
