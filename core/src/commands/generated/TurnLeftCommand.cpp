/*
 * This file is generated. Do not change it manually.
 */

#include "TurnLeftCommand.h"

#include "FrameworkAssert.h"
#include "CommandConstraintException.h"
#include "ConcreteKara.h"
#include "GameLog.h"
#include <stdexcept>

using namespace framework;

namespace commands {

void TurnLeftCommand::execute() {

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
				"Transformation was not successfully executed: turnLeft");
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
bool TurnLeftCommand::internalMainUnit() {

	if (turnLeftNorth()) {
		return true;
	} else if (turnLeftSouth()) {
		return true;
	} else if (turnLeftWest()) {
		return true;
	} else if (turnLeftEast()) {
		return true;
	}

	return false;

}

bool TurnLeftCommand::turnLeftNorth() {

	// assert condition: self.direction == NORTH
	if (self->getDirection() != mpw::Direction::NORTH) {
		return false;
	}

	// set attribute: self.direction := WEST
	executeSetEnumProperty(self, kara::ConcreteKara::cFeatureKeyDirection,
			self->getDirection(), mpw::Direction::WEST);

	return true;

}

bool TurnLeftCommand::turnLeftSouth() {

	// assert condition: self.direction == SOUTH
	if (self->getDirection() != mpw::Direction::SOUTH) {
		return false;
	}

	// set attribute: self.direction := EAST
	executeSetEnumProperty(self, kara::ConcreteKara::cFeatureKeyDirection,
			self->getDirection(), mpw::Direction::EAST);

	return true;

}

bool TurnLeftCommand::turnLeftWest() {

	// assert condition: self.direction == WEST
	if (self->getDirection() != mpw::Direction::WEST) {
		return false;
	}

	// set attribute: self.direction := SOUTH
	executeSetEnumProperty(self, kara::ConcreteKara::cFeatureKeyDirection,
			self->getDirection(), mpw::Direction::SOUTH);

	return true;

}

bool TurnLeftCommand::turnLeftEast() {

	// assert condition: self.direction == EAST
	if (self->getDirection() != mpw::Direction::EAST) {
		return false;
	}

	// set attribute: self.direction := NORTH
	executeSetEnumProperty(self, kara::ConcreteKara::cFeatureKeyDirection,
			self->getDirection(), mpw::Direction::NORTH);

	return true;

}

bool TurnLeftCommand::addGameLog() {

	// new instance: entry:LogEntry
	std::shared_ptr < mpw::LogEntry > entry = std::make_shared<mpw::LogEntry>();

	// set value type field entry.message := 
	executeSetStringProperty(entry, mpw::LogEntry::cFeatureKeyMessage,
			entry->getMessage(), "Turn Left");

	// create reference: CREATE entry:LogEntry -> actor -> self:GameKara
	executeSetProperty(entry, mpw::LogEntry::cFeatureKeyActor,
			entry->getActor(), self);

	// create reference: CREATE gameLog:GameLog -> logEntries -> entry:LogEntry
	executeAddReference(gameLog, mpw::GameLog::cFeatureKeyLogEntries, entry);

	return true;

}

}

