/*
 * This file is generated. Do not change it manually.
 */

#include "AddLeafToTileCommand.h"

#include "FrameworkAssert.h"
#include "CommandConstraintException.h"
#include "ConcreteWorld.h"
#include "GameLog.h"
#include "CollectionHelpers.hpp"
#include <stdexcept>

using namespace framework;

namespace commands {

void AddLeafToTileCommand::execute() {

	/*
	 * the tile at the given location has to be empty
	 */

	if ((self->getTileAt(location)->getContents().empty()
			|| self->isOnlyKaraAtLocation(location)) == false) {
		throw CommandConstraintException(
				"Violation of Precondition: the tile at the given location has to be empty");
	}

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
				"Transformation was not successfully executed: addLeafToTile");
	}

	/*
	 * a leaf has to be placed on the tile's location
	 */

	if ((collectionhelpers::type_select < kara::Leaf
			> (self->getTileAt(location)->getContents()).size() == 1)
			== false) {
		throw CommandConstraintException(
				"Violation of Postcondition: a leaf has to be placed on the tile's location");
	}

	/*
	 * the world tiles must not be empty
	 */

	if ((self->getTiles().size() > 0) == false) {
		throw CommandConstraintException(
				"Violation of ClassInvariant: the world tiles must not be empty");
	}

}
bool AddLeafToTileCommand::internalMainUnit() {

	// new instance: o2:Leaf
	std::shared_ptr < kara::Leaf > o2 = std::make_shared<kara::Leaf>();

	// find new variable from many-reference: self:EditorWorld -> tiles -> o1:Tile

	std::shared_ptr < mpw::Tile > o1 = execute_findO1(*self);
	if (o1 == nullptr) {
		return false;
	}

	// new variable from reference: o1:Tile -> location -> o0:Location

	mpw::Location o0 = o1->getLocation();

	// assert condition: o0.column == location.column
	if (o0.getColumn() != location.getColumn()) {
		return false;
	}

	// assert condition: o0.row == location.row
	if (o0.getRow() != location.getRow()) {
		return false;
	}

	// create reference: CREATE o1:Tile -> contents -> o2:Leaf
	executeAddReference(o1, mpw::Tile::cFeatureKeyContents, o2);

	// create reference: CREATE self:EditorWorld -> tileContents -> o2:Leaf
	executeAddReference(self, kara::ConcreteWorld::cFeatureKeyTileContents, o2);

	return true;

}

std::shared_ptr<mpw::Tile> AddLeafToTileCommand::execute_findO1(
		kara::EditorWorld &source) {
	std::shared_ptr < mpw::Tile > result = nullptr;

	for (auto &o1 : source.getTiles().sharedPointerView()) {

		// reference check: o1: location
		mpw::Location o0 = o1->getLocation();

		// attribute check: o0: column
		if (o0.getColumn() != location.getColumn()) {
			continue;
		}

		// attribute check: o0: row
		if (o0.getRow() != location.getRow()) {
			continue;
		}

		result = o1;
		break;
	}
	return result;
}

}

