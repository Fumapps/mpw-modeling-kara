/*
 * This file is generated. Do not change it manually.
 */

#include "TurnRightCommand.h"

#include "FrameworkAssert.h"
#include "CommandConstraintException.h"
#include "ConcreteKara.h"
#include "GameLog.h"
#include <stdexcept>

using namespace framework;

namespace commands {

void TurnRightCommand::execute() {

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
				"Transformation was not successfully executed: turnRight");
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
bool TurnRightCommand::internalMainUnit() {

	if (turnRightNorth()) {
		return true;
	} else if (turnRightSouth()) {
		return true;
	} else if (turnRightWest()) {
		return true;
	} else if (turnRightEast()) {
		return true;
	}

	return false;

}

bool TurnRightCommand::turnRightNorth() {

	// assert condition: self.direction == NORTH
	if (self->getDirection() != mpw::Direction::NORTH) {
		return false;
	}

	// set attribute: self.direction := EAST
	executeSetEnumProperty(self, kara::ConcreteKara::cFeatureKeyDirection,
			self->getDirection(), mpw::Direction::EAST);

	return true;

}

bool TurnRightCommand::turnRightSouth() {

	// assert condition: self.direction == SOUTH
	if (self->getDirection() != mpw::Direction::SOUTH) {
		return false;
	}

	// set attribute: self.direction := WEST
	executeSetEnumProperty(self, kara::ConcreteKara::cFeatureKeyDirection,
			self->getDirection(), mpw::Direction::WEST);

	return true;

}

bool TurnRightCommand::turnRightWest() {

	// assert condition: self.direction == WEST
	if (self->getDirection() != mpw::Direction::WEST) {
		return false;
	}

	// set attribute: self.direction := NORTH
	executeSetEnumProperty(self, kara::ConcreteKara::cFeatureKeyDirection,
			self->getDirection(), mpw::Direction::NORTH);

	return true;

}

bool TurnRightCommand::turnRightEast() {

	// assert condition: self.direction == EAST
	if (self->getDirection() != mpw::Direction::EAST) {
		return false;
	}

	// set attribute: self.direction := SOUTH
	executeSetEnumProperty(self, kara::ConcreteKara::cFeatureKeyDirection,
			self->getDirection(), mpw::Direction::SOUTH);

	return true;

}

bool TurnRightCommand::addGameLog() {

	// new instance: entry:LogEntry
	std::shared_ptr < mpw::LogEntry > entry = std::make_shared<mpw::LogEntry>();

	// set value type field entry.message := 
	executeSetStringProperty(entry, mpw::LogEntry::cFeatureKeyMessage,
			entry->getMessage(), "Turn Right");

	// create reference: CREATE entry:LogEntry -> actor -> self:GameKara
	executeSetProperty(entry, mpw::LogEntry::cFeatureKeyActor,
			entry->getActor(), self);

	// create reference: CREATE gameLog:GameLog -> logEntries -> entry:LogEntry
	executeAddReference(gameLog, mpw::GameLog::cFeatureKeyLogEntries, entry);

	return true;

}

}

