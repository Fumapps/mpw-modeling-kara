/*
 * This file is generated. Do not change it manually.
 */

#include "RemoveLeafCommand.h"

#include "FrameworkAssert.h"
#include "CommandConstraintException.h"
#include "ConcreteKara.h"
#include "GameLog.h"
#include "CollectionHelpers.hpp"
#include <stdexcept>

using namespace framework;

namespace commands {

void RemoveLeafCommand::execute() {

	/*
	 * there has to be a leaf available on the kara's tile
	 */

	if ((self->onLeaf()) == false) {
		throw CommandConstraintException(
				"Violation of Precondition: there has to be a leaf available on the kara's tile");
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
				"Transformation was not successfully executed: removeLeaf");
	}
	addGameLog();

	/*
	 * the kara must not be on any leaf
	 */

	if ((!(self->onLeaf())) == false) {
		throw CommandConstraintException(
				"Violation of Postcondition: the kara must not be on any leaf");
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
bool RemoveLeafCommand::internalMainUnit() {

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

	// find new variable from many-reference: position:Tile -> contents -> leaf:Leaf

	std::shared_ptr < kara::Leaf > leaf = execute_findLeaf(*position);
	if (leaf == nullptr) {
		return false;
	}

	if (stage != (leaf->getStage())) {
		return false;
	}

	// remove reference: DELETE position:Tile -> contents -> leaf:Leaf

	executeRemoveReference(position, mpw::Tile::cFeatureKeyContents, leaf);

	// remove reference: DELETE leaf:Leaf -> stage -> stage:Stage

	executeSetProperty(leaf, kara::Leaf::cFeatureKeyStage, leaf->getStage(),
			nullptr);

	return true;

}

std::shared_ptr<kara::Leaf> RemoveLeafCommand::execute_findLeaf(
		mpw::Tile &source) {
	std::shared_ptr < kara::Leaf > result = nullptr;

	for (auto &leafTileContent : source.getContents().sharedPointerView()) {

		std::shared_ptr < kara::Leaf > leaf = std::dynamic_pointer_cast
				< kara::Leaf > (leafTileContent);
		if (leaf == nullptr) {
			continue;
		}

		// reference check: leaf: stage
		std::shared_ptr < mpw::Stage > stage = leaf->getStage();
		if (stage == nullptr) {
			continue;
		}

		result = leaf;
		break;
	}
	return result;
}

bool RemoveLeafCommand::addGameLog() {

	// new instance: entry:LogEntry
	std::shared_ptr < mpw::LogEntry > entry = std::make_shared<mpw::LogEntry>();

	// set value type field entry.message := 
	executeSetStringProperty(entry, mpw::LogEntry::cFeatureKeyMessage,
			entry->getMessage(), "Remove Leaf");

	// create reference: CREATE entry:LogEntry -> actor -> self:GameKara
	executeSetProperty(entry, mpw::LogEntry::cFeatureKeyActor,
			entry->getActor(), self);

	// create reference: CREATE gameLog:GameLog -> logEntries -> entry:LogEntry
	executeAddReference(gameLog, mpw::GameLog::cFeatureKeyLogEntries, entry);

	return true;

}

}

