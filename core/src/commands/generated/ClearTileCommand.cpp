/*
 * This file is generated. Do not change it manually.
 */

#include "ClearTileCommand.h"

#include "FrameworkAssert.h"
#include "CommandConstraintException.h"
#include "ConcreteWorld.h"
#include "GameLog.h"
#include "CollectionHelpers.hpp"
#include <stdexcept>

using namespace framework;

namespace commands {

void ClearTileCommand::execute() {

	/*
	 * location has to be on the world
	 */

	if ((self->isLocationInWorld(location)) == false) {
		throw CommandConstraintException(
				"Violation of Precondition: location has to be on the world");
	}

	/*
	 * the world tiles must not be empty
	 */

	if ((self->getTiles().size() > 0) == false) {
		throw CommandConstraintException(
				"Violation of ClassInvariant: the world tiles must not be empty");
	}

	if (!internalMainUnit()) {
		throw std::runtime_error(
				"Transformation was not successfully executed: clearTile");
	}

	/*
	 * the tile's contents have to be empty
	 */

	if ((self->getTileAt(location)->getContents().empty()) == false) {
		throw CommandConstraintException(
				"Violation of Postcondition: the tile's contents have to be empty");
	}

	/*
	 * the world tiles must not be empty
	 */

	if ((self->getTiles().size() > 0) == false) {
		throw CommandConstraintException(
				"Violation of ClassInvariant: the world tiles must not be empty");
	}

}
bool ClearTileCommand::internalMainUnit() {

	// find new variable from many-reference: self:EditorWorld -> tiles -> o0:Tile

	std::shared_ptr < mpw::Tile > o0 = execute_findO0(*self);
	if (o0 == nullptr) {
		return false;
	}

	// new variable from reference: o0:Tile -> location -> o1:Location

	mpw::Location o1 = o0->getLocation();

	// assert condition: o1.column == location.column
	if (o1.getColumn() != location.getColumn()) {
		return false;
	}

	// assert condition: o1.row == location.row
	if (o1.getRow() != location.getRow()) {
		return false;
	}

	// clear references: self:EditorWorld -> tileContents -> o2:TileContent
	while (self->getTileContents().size() > 0) {
		executeRemoveReference(self,
				kara::ConcreteWorld::cFeatureKeyTileContents,
				self->getTileContents().front());
	}

	// clear references: o0:Tile -> contents -> o2:TileContent
	while (o0->getContents().size() > 0) {
		executeRemoveReference(o0, mpw::Tile::cFeatureKeyContents,
				o0->getContents().front());
	}

	return true;

}

std::shared_ptr<mpw::Tile> ClearTileCommand::execute_findO0(
		kara::EditorWorld &source) {
	std::shared_ptr < mpw::Tile > result = nullptr;

	for (auto &o0 : source.getTiles().sharedPointerView()) {

		// reference check: o0: location
		mpw::Location o1 = o0->getLocation();

		// attribute check: o1: column
		if (o1.getColumn() != location.getColumn()) {
			continue;
		}

		// attribute check: o1: row
		if (o1.getRow() != location.getRow()) {
			continue;
		}

		result = o0;
		break;
	}
	return result;
}

}

