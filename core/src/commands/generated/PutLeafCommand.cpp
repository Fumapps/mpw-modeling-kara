/*
 * This file is generated. Do not change it manually.
 */

#include "PutLeafCommand.h"

#include "FrameworkAssert.h"
#include "CommandConstraintException.h"
#include "ConcreteKara.h"
#include "GameLog.h"
#include "CollectionHelpers.hpp"
#include <stdexcept>

using namespace framework;

namespace commands {

void PutLeafCommand::execute() {

	/*
	 * the kara must not be on any leaf
	 */

	if ((!(self->onLeaf())) == false) {
		throw CommandConstraintException(
				"Violation of Precondition: the kara must not be on any leaf");
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
				"Transformation was not successfully executed: putLeaf");
	}
	addGameLog();

	/*
	 * there has to be a leaf available on the kara's tile
	 */

	if ((self->onLeaf()) == false) {
		throw CommandConstraintException(
				"Violation of Postcondition: there has to be a leaf available on the kara's tile");
	}

	/*
	 * Kara is placed on a tile.
	 */

	if ((self->getStage() != nullptr && self->getCurrentTile() != nullptr)
			== false) {
		throw CommandConstraintException(
				"Violation of ClassInvariant: Kara is placed on a tile.");
	}

}
bool PutLeafCommand::internalMainUnit() {

	// new instance: leaf:Leaf
	std::shared_ptr < kara::Leaf > leaf = std::make_shared<kara::Leaf>();

	// new variable from reference: self:GameKara -> currentTile -> position:Tile

	std::shared_ptr < mpw::Tile > position = self->getCurrentTile();
	if (position.get() == nullptr) {
		return false;
	}

	// new variable from reference: self:GameKara -> stage -> stage:Stage

	std::shared_ptr < mpw::Stage > stage = self->getStage();
	if (stage.get() == nullptr) {
		return false;
	}

	if (!stage->getTileContents().contains(self)) {
		return false;
	}

	// create reference: CREATE position:Tile -> contents -> leaf:Leaf
	executeAddReference(position, mpw::Tile::cFeatureKeyContents, leaf);

	// create reference: CREATE stage:Stage -> tileContents -> leaf:Leaf
	executeAddReference(stage, mpw::Stage::cFeatureKeyTileContents, leaf);

	return true;

}

bool PutLeafCommand::addGameLog() {

	// new instance: entry:LogEntry
	std::shared_ptr < mpw::LogEntry > entry = std::make_shared<mpw::LogEntry>();

	// set value type field entry.message := 
	executeSetStringProperty(entry, mpw::LogEntry::cFeatureKeyMessage,
			entry->getMessage(), "Put Leaf");

	// create reference: CREATE entry:LogEntry -> actor -> self:GameKara
	executeSetProperty(entry, mpw::LogEntry::cFeatureKeyActor,
			entry->getActor(), self);

	// create reference: CREATE gameLog:GameLog -> logEntries -> entry:LogEntry
	executeAddReference(gameLog, mpw::GameLog::cFeatureKeyLogEntries, entry);

	return true;

}

}

