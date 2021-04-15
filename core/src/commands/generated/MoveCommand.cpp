/*
 * This file is generated. Do not change it manually.
 */

#include "MoveCommand.h"

#include "FrameworkAssert.h"
#include "CommandConstraintException.h"
#include "ConcreteKara.h"
#include "GameLog.h"
#include "CollectionHelpers.hpp"
#include <stdexcept>

using namespace framework;

namespace commands {

void MoveCommand::execute() {

	/*
	 * Kara's front must not be blocked or outside world
	 */

	if ((!(self->treeFront())) == false) {
		throw CommandConstraintException(
				"Violation of Precondition: Kara's front must not be blocked or outside world");
	}

	/*
	 * A front mushroom has to be movable
	 */

	if (((self->mushroomFront()) ? (
			(self->getDirection() == mpw::Direction::WEST) ? (helper_Precondition2_currentTile_result0_west_result1_west_result2_contents_is_empty()) :
			true && (self->getDirection() == mpw::Direction::EAST) ? (helper_Precondition2_currentTile_result0_east_result1_east_result2_contents_is_empty()) :
			true && (self->getDirection() == mpw::Direction::NORTH) ? (helper_Precondition2_currentTile_result0_north_result1_north_result2_contents_is_empty()) :
			true && (self->getDirection() == mpw::Direction::SOUTH) ? (helper_Precondition2_currentTile_result0_south_result1_south_result2_contents_is_empty()) :
					true) :
			true) == false) {
		throw CommandConstraintException(
				"Violation of Precondition: A front mushroom has to be movable");
	}

	/*
	 * Kara is placed on a tile.
	 */

	if ((self->getStage() != nullptr && self->getCurrentTile() != nullptr)
			== false) {
		throw CommandConstraintException(
				"Violation of ClassInvariant: Kara is placed on a tile.");
	}

	if (!internalMainUnit()) {
		throw std::runtime_error(
				"Transformation was not successfully executed: move");
	}
	addGameLog();

	/*
	 * Kara is placed on a tile.
	 */

	if ((self->getStage() != nullptr && self->getCurrentTile() != nullptr)
			== false) {
		throw CommandConstraintException(
				"Violation of ClassInvariant: Kara is placed on a tile.");
	}

}
bool MoveCommand::internalMainUnit() {

	if (!moveMushroom()) {
		return false;
	}
	if (!moveKara()) {
		return false;
	}
	return true;

}

bool MoveCommand::moveNorth() {

	// new variable from reference: self:GameKara -> currentTile -> current:Tile

	std::shared_ptr < mpw::Tile > current = self->getCurrentTile();
	if (current.get() == nullptr) {
		return false;
	}

	// new variable from reference: current:Tile -> north -> front:Tile

	std::shared_ptr < mpw::Tile > front = current->getNorth();
	if (front.get() == nullptr) {
		return false;
	}

	// assert condition: self.direction == NORTH
	if (self->getDirection() != mpw::Direction::NORTH) {
		return false;
	}

	// remove reference: DELETE self:GameKara -> currentTile -> current:Tile

	executeSetProperty(self, kara::ConcreteKara::cFeatureKeyCurrentTile,
			self->getCurrentTile(), nullptr);

	// create reference: CREATE self:GameKara -> currentTile -> front:Tile
	executeSetProperty(self, kara::ConcreteKara::cFeatureKeyCurrentTile,
			self->getCurrentTile(), front);

	return true;

}

bool MoveCommand::moveSouth() {

	// new variable from reference: self:GameKara -> currentTile -> current:Tile

	std::shared_ptr < mpw::Tile > current = self->getCurrentTile();
	if (current.get() == nullptr) {
		return false;
	}

	// new variable from reference: current:Tile -> south -> front:Tile

	std::shared_ptr < mpw::Tile > front = current->getSouth();
	if (front.get() == nullptr) {
		return false;
	}

	// assert condition: self.direction == SOUTH
	if (self->getDirection() != mpw::Direction::SOUTH) {
		return false;
	}

	// remove reference: DELETE self:GameKara -> currentTile -> current:Tile

	executeSetProperty(self, kara::ConcreteKara::cFeatureKeyCurrentTile,
			self->getCurrentTile(), nullptr);

	// create reference: CREATE self:GameKara -> currentTile -> front:Tile
	executeSetProperty(self, kara::ConcreteKara::cFeatureKeyCurrentTile,
			self->getCurrentTile(), front);

	return true;

}

bool MoveCommand::moveWest() {

	// new variable from reference: self:GameKara -> currentTile -> current:Tile

	std::shared_ptr < mpw::Tile > current = self->getCurrentTile();
	if (current.get() == nullptr) {
		return false;
	}

	// new variable from reference: current:Tile -> west -> front:Tile

	std::shared_ptr < mpw::Tile > front = current->getWest();
	if (front.get() == nullptr) {
		return false;
	}

	// assert condition: self.direction == WEST
	if (self->getDirection() != mpw::Direction::WEST) {
		return false;
	}

	// remove reference: DELETE self:GameKara -> currentTile -> current:Tile

	executeSetProperty(self, kara::ConcreteKara::cFeatureKeyCurrentTile,
			self->getCurrentTile(), nullptr);

	// create reference: CREATE self:GameKara -> currentTile -> front:Tile
	executeSetProperty(self, kara::ConcreteKara::cFeatureKeyCurrentTile,
			self->getCurrentTile(), front);

	return true;

}

bool MoveCommand::moveEast() {

	// new variable from reference: self:GameKara -> currentTile -> current:Tile

	std::shared_ptr < mpw::Tile > current = self->getCurrentTile();
	if (current.get() == nullptr) {
		return false;
	}

	// new variable from reference: current:Tile -> east -> front:Tile

	std::shared_ptr < mpw::Tile > front = current->getEast();
	if (front.get() == nullptr) {
		return false;
	}

	// assert condition: self.direction == EAST
	if (self->getDirection() != mpw::Direction::EAST) {
		return false;
	}

	// remove reference: DELETE self:GameKara -> currentTile -> current:Tile

	executeSetProperty(self, kara::ConcreteKara::cFeatureKeyCurrentTile,
			self->getCurrentTile(), nullptr);

	// create reference: CREATE self:GameKara -> currentTile -> front:Tile
	executeSetProperty(self, kara::ConcreteKara::cFeatureKeyCurrentTile,
			self->getCurrentTile(), front);

	return true;

}

bool MoveCommand::moveKara() {

	if (moveEast()) {
		return true;
	} else if (moveNorth()) {
		return true;
	} else if (moveSouth()) {
		return true;
	} else if (moveWest()) {
		return true;
	}

	return false;

}

bool MoveCommand::moveMushroom() {

	if (moveMushroomEast()) {
		return true;
	} else if (moveMushroomNorth()) {
		return true;
	} else if (moveMushroomSouth()) {
		return true;
	} else if (moveMushroomWest()) {
		return true;
	} else if (dummy()) {
		return true;
	}

	return false;

}

bool MoveCommand::moveMushroomNorth() {

	// new variable from reference: self:GameKara -> currentTile -> current:Tile

	std::shared_ptr < mpw::Tile > current = self->getCurrentTile();
	if (current.get() == nullptr) {
		return false;
	}

	// new variable from reference: current:Tile -> north -> front:Tile

	std::shared_ptr < mpw::Tile > front = current->getNorth();
	if (front.get() == nullptr) {
		return false;
	}

	// new variable from reference: front:Tile -> north -> behind:Tile

	std::shared_ptr < mpw::Tile > behind = front->getNorth();
	if (behind.get() == nullptr) {
		return false;
	}

	// find new variable from many-reference: front:Tile -> contents -> o0:Mushroom

	std::shared_ptr < kara::Mushroom > o0 = moveMushroomNorth_findO0(*front);
	if (o0 == nullptr) {
		return false;
	}

	// assert condition: self.direction == NORTH
	if (self->getDirection() != mpw::Direction::NORTH) {
		return false;
	}

	// remove reference: DELETE front:Tile -> contents -> o0:Mushroom

	executeRemoveReference(front, mpw::Tile::cFeatureKeyContents, o0);

	// create reference: CREATE o0:Mushroom -> currentTile -> behind:Tile
	executeSetProperty(o0, kara::Mushroom::cFeatureKeyCurrentTile,
			o0->getCurrentTile(), behind);

	return true;

}

std::shared_ptr<kara::Mushroom> MoveCommand::moveMushroomNorth_findO0(
		mpw::Tile &source) {
	std::shared_ptr < kara::Mushroom > result = nullptr;

	for (auto &o0TileContent : source.getContents().sharedPointerView()) {

		std::shared_ptr < kara::Mushroom > o0 = std::dynamic_pointer_cast
				< kara::Mushroom > (o0TileContent);
		if (o0 == nullptr) {
			continue;
		}

		result = o0;
		break;
	}
	return result;
}

bool MoveCommand::dummy() {

	return true;

}

bool MoveCommand::moveMushroomWest() {

	// new variable from reference: self:GameKara -> currentTile -> current:Tile

	std::shared_ptr < mpw::Tile > current = self->getCurrentTile();
	if (current.get() == nullptr) {
		return false;
	}

	// new variable from reference: current:Tile -> west -> front:Tile

	std::shared_ptr < mpw::Tile > front = current->getWest();
	if (front.get() == nullptr) {
		return false;
	}

	// new variable from reference: front:Tile -> west -> behind:Tile

	std::shared_ptr < mpw::Tile > behind = front->getWest();
	if (behind.get() == nullptr) {
		return false;
	}

	// find new variable from many-reference: front:Tile -> contents -> o0:Mushroom

	std::shared_ptr < kara::Mushroom > o0 = moveMushroomWest_findO0(*front);
	if (o0 == nullptr) {
		return false;
	}

	// assert condition: self.direction == WEST
	if (self->getDirection() != mpw::Direction::WEST) {
		return false;
	}

	// remove reference: DELETE front:Tile -> contents -> o0:Mushroom

	executeRemoveReference(front, mpw::Tile::cFeatureKeyContents, o0);

	// create reference: CREATE o0:Mushroom -> currentTile -> behind:Tile
	executeSetProperty(o0, kara::Mushroom::cFeatureKeyCurrentTile,
			o0->getCurrentTile(), behind);

	return true;

}

std::shared_ptr<kara::Mushroom> MoveCommand::moveMushroomWest_findO0(
		mpw::Tile &source) {
	std::shared_ptr < kara::Mushroom > result = nullptr;

	for (auto &o0TileContent : source.getContents().sharedPointerView()) {

		std::shared_ptr < kara::Mushroom > o0 = std::dynamic_pointer_cast
				< kara::Mushroom > (o0TileContent);
		if (o0 == nullptr) {
			continue;
		}

		result = o0;
		break;
	}
	return result;
}

bool MoveCommand::moveMushroomSouth() {

	// new variable from reference: self:GameKara -> currentTile -> current:Tile

	std::shared_ptr < mpw::Tile > current = self->getCurrentTile();
	if (current.get() == nullptr) {
		return false;
	}

	// new variable from reference: current:Tile -> south -> front:Tile

	std::shared_ptr < mpw::Tile > front = current->getSouth();
	if (front.get() == nullptr) {
		return false;
	}

	// new variable from reference: front:Tile -> south -> behind:Tile

	std::shared_ptr < mpw::Tile > behind = front->getSouth();
	if (behind.get() == nullptr) {
		return false;
	}

	// find new variable from many-reference: front:Tile -> contents -> o0:Mushroom

	std::shared_ptr < kara::Mushroom > o0 = moveMushroomSouth_findO0(*front);
	if (o0 == nullptr) {
		return false;
	}

	// assert condition: self.direction == SOUTH
	if (self->getDirection() != mpw::Direction::SOUTH) {
		return false;
	}

	// remove reference: DELETE front:Tile -> contents -> o0:Mushroom

	executeRemoveReference(front, mpw::Tile::cFeatureKeyContents, o0);

	// create reference: CREATE o0:Mushroom -> currentTile -> behind:Tile
	executeSetProperty(o0, kara::Mushroom::cFeatureKeyCurrentTile,
			o0->getCurrentTile(), behind);

	return true;

}

std::shared_ptr<kara::Mushroom> MoveCommand::moveMushroomSouth_findO0(
		mpw::Tile &source) {
	std::shared_ptr < kara::Mushroom > result = nullptr;

	for (auto &o0TileContent : source.getContents().sharedPointerView()) {

		std::shared_ptr < kara::Mushroom > o0 = std::dynamic_pointer_cast
				< kara::Mushroom > (o0TileContent);
		if (o0 == nullptr) {
			continue;
		}

		result = o0;
		break;
	}
	return result;
}

bool MoveCommand::moveMushroomEast() {

	// new variable from reference: self:GameKara -> currentTile -> current:Tile

	std::shared_ptr < mpw::Tile > current = self->getCurrentTile();
	if (current.get() == nullptr) {
		return false;
	}

	// new variable from reference: current:Tile -> east -> front:Tile

	std::shared_ptr < mpw::Tile > front = current->getEast();
	if (front.get() == nullptr) {
		return false;
	}

	// new variable from reference: front:Tile -> east -> behind:Tile

	std::shared_ptr < mpw::Tile > behind = front->getEast();
	if (behind.get() == nullptr) {
		return false;
	}

	// find new variable from many-reference: front:Tile -> contents -> o0:Mushroom

	std::shared_ptr < kara::Mushroom > o0 = moveMushroomEast_findO0(*front);
	if (o0 == nullptr) {
		return false;
	}

	// assert condition: self.direction == EAST
	if (self->getDirection() != mpw::Direction::EAST) {
		return false;
	}

	// remove reference: DELETE front:Tile -> contents -> o0:Mushroom

	executeRemoveReference(front, mpw::Tile::cFeatureKeyContents, o0);

	// create reference: CREATE o0:Mushroom -> currentTile -> behind:Tile
	executeSetProperty(o0, kara::Mushroom::cFeatureKeyCurrentTile,
			o0->getCurrentTile(), behind);

	return true;

}

std::shared_ptr<kara::Mushroom> MoveCommand::moveMushroomEast_findO0(
		mpw::Tile &source) {
	std::shared_ptr < kara::Mushroom > result = nullptr;

	for (auto &o0TileContent : source.getContents().sharedPointerView()) {

		std::shared_ptr < kara::Mushroom > o0 = std::dynamic_pointer_cast
				< kara::Mushroom > (o0TileContent);
		if (o0 == nullptr) {
			continue;
		}

		result = o0;
		break;
	}
	return result;
}

bool MoveCommand::addGameLog() {

	// new instance: entry:LogEntry
	std::shared_ptr < mpw::LogEntry > entry = std::make_shared<mpw::LogEntry>();

	// set value type field entry.message := 
	executeSetStringProperty(entry, mpw::LogEntry::cFeatureKeyMessage,
			entry->getMessage(), "Move");

	// create reference: CREATE entry:LogEntry -> actor -> self:GameKara
	executeSetProperty(entry, mpw::LogEntry::cFeatureKeyActor,
			entry->getActor(), self);

	// create reference: CREATE gameLog:GameLog -> logEntries -> entry:LogEntry
	executeAddReference(gameLog, mpw::GameLog::cFeatureKeyLogEntries, entry);

	return true;

}

bool MoveCommand::helper_Precondition2_currentTile_result0_west_result1_west_result2_contents_is_empty() const noexcept {
	std::shared_ptr<const mpw::Tile> result0 = self->getCurrentTile();
	if (result0 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result1 = result0->getWest();
	if (result1 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result2 = result1->getWest();
	if (result2 == nullptr) {
		return false;
	}
	bool result3 = result2->getContents().empty();
	return result3;
}

bool MoveCommand::helper_Precondition2_currentTile_result0_north_result1_north_result2_contents_is_empty() const noexcept {
	std::shared_ptr<const mpw::Tile> result0 = self->getCurrentTile();
	if (result0 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result1 = result0->getNorth();
	if (result1 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result2 = result1->getNorth();
	if (result2 == nullptr) {
		return false;
	}
	bool result3 = result2->getContents().empty();
	return result3;
}

bool MoveCommand::helper_Precondition2_currentTile_result0_south_result1_south_result2_contents_is_empty() const noexcept {
	std::shared_ptr<const mpw::Tile> result0 = self->getCurrentTile();
	if (result0 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result1 = result0->getSouth();
	if (result1 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result2 = result1->getSouth();
	if (result2 == nullptr) {
		return false;
	}
	bool result3 = result2->getContents().empty();
	return result3;
}

bool MoveCommand::helper_Precondition2_currentTile_result0_east_result1_east_result2_contents_is_empty() const noexcept {
	std::shared_ptr<const mpw::Tile> result0 = self->getCurrentTile();
	if (result0 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result1 = result0->getEast();
	if (result1 == nullptr) {
		return false;
	}
	std::shared_ptr<const mpw::Tile> result2 = result1->getEast();
	if (result2 == nullptr) {
		return false;
	}
	bool result3 = result2->getContents().empty();
	return result3;
}
}

