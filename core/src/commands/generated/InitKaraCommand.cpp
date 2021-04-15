/*
 * This file is generated. Do not change it manually.
 */

#include "InitKaraCommand.h"

#include "FrameworkAssert.h"
#include "CommandConstraintException.h"
#include "ConcreteWorld.h"
#include "GameLog.h"
#include "CollectionHelpers.hpp"
#include <stdexcept>

using namespace framework;

namespace commands {

void InitKaraCommand::execute() {

	/*
	 * kara must not be already initialized
	 */

	if ((self->getKara()->getStage() == nullptr) == false) {
		throw CommandConstraintException(
				"Violation of Precondition: kara must not be already initialized");
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
				"Transformation was not successfully executed: initKara");
	}

	/*
	 * Kara has to be placed on the tile's location
	 */

	if ((collectionhelpers::get_at(
			collectionhelpers::type_select < kara::ConcreteKara
					> (self->getTileAt(location)->getContents()), 0).value()
			== self->getKara()) == false) {
		throw CommandConstraintException(
				"Violation of Postcondition: Kara has to be placed on the tile's location");
	}

	/*
	 * the world tiles must not be empty
	 */

	if ((self->getTiles().size() > 0) == false) {
		throw CommandConstraintException(
				"Violation of ClassInvariant: the world tiles must not be empty");
	}

}
bool InitKaraCommand::internalMainUnit() {

	if (!addToWorld(location)) {
		return false;
	}
	if (!setProperties(direction)) {
		return false;
	}
	return true;

}

bool InitKaraCommand::setProperties(mpw::Direction initialDirection) {

	// new variable from reference: self:EditorWorld -> kara -> kara:EditorKara

	std::shared_ptr < kara::EditorKara > kara = std::dynamic_pointer_cast
			< kara::EditorKara > (self->getKara());
	if (kara.get() == nullptr) {
		return false;
	}

	// set value type field kara.direction := initialDirection
	executeSetEnumProperty(kara, kara::ConcreteKara::cFeatureKeyDirection,
			kara->getDirection(), initialDirection);

	return true;

}

bool InitKaraCommand::addToWorld(mpw::Location location) {

	// new variable from reference: self:EditorWorld -> kara -> kara:EditorKara

	std::shared_ptr < kara::EditorKara > kara = std::dynamic_pointer_cast
			< kara::EditorKara > (self->getKara());
	if (kara.get() == nullptr) {
		return false;
	}

	// find new variable from many-reference: self:EditorWorld -> tiles -> o0:Tile

	std::shared_ptr < mpw::Tile > o0 = addToWorld_findO0(*self);
	if (o0 == nullptr) {
		return false;
	}

	// new variable from reference: o0:Tile -> location -> o1:Location

	mpw::Location o1 = o0->getLocation();

	// assert condition: o1.row == location.row
	if (o1.getRow() != location.getRow()) {
		return false;
	}

	// assert condition: o1.column == location.column
	if (o1.getColumn() != location.getColumn()) {
		return false;
	}

	// create reference: CREATE self:EditorWorld -> tileContents -> kara:EditorKara
	executeAddReference(self, kara::ConcreteWorld::cFeatureKeyTileContents,
			kara);

	// create reference: CREATE kara:EditorKara -> currentTile -> o0:Tile
	executeSetProperty(kara, kara::ConcreteKara::cFeatureKeyCurrentTile,
			kara->getCurrentTile(), o0);

	return true;

}

std::shared_ptr<mpw::Tile> InitKaraCommand::addToWorld_findO0(
		kara::EditorWorld &source) {
	std::shared_ptr < mpw::Tile > result = nullptr;

	for (auto &o0 : source.getTiles().sharedPointerView()) {

		// reference check: o0: location
		mpw::Location o1 = o0->getLocation();

		// attribute check: o1: row
		if (o1.getRow() != location.getRow()) {
			continue;
		}

		// attribute check: o1: column
		if (o1.getColumn() != location.getColumn()) {
			continue;
		}

		result = o0;
		break;
	}
	return result;
}

}

