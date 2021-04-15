/*
 * This file is generated. Do not change it manually.
 */

#include "InitWorldCommand.h"

#include "FrameworkAssert.h"
#include "CommandConstraintException.h"
#include "ConcreteWorld.h"
#include "GameLog.h"
#include <stdexcept>

using namespace framework;

namespace commands {

void InitWorldCommand::execute() {

	/*
	 * size must be > 0
	 */

	if ((columns > 0 && rows > 0) == false) {
		throw CommandConstraintException(
				"Violation of Precondition: size must be > 0");
	}

	if (!internalMainUnit()) {
		throw std::runtime_error(
				"Transformation was not successfully executed: initWorld");
	}

	/*
	 * size of world is set
	 */

	if ((self->getStageSize().getColumnCount() == columns
			&& self->getStageSize().getRowCount() == rows) == false) {
		throw CommandConstraintException(
				"Violation of Postcondition: size of world is set");
	}

	/*
	 * the world tiles must not be empty
	 */

	if ((self->getTiles().size() > 0) == false) {
		throw CommandConstraintException(
				"Violation of ClassInvariant: the world tiles must not be empty");
	}

}
bool InitWorldCommand::internalMainUnit() {

	// new variable firstInRow: Tile
	std::shared_ptr < mpw::Tile > firstInRow;

	if (!clearWorld()) {
		return false;
	}
	if (!setSize(columns, rows)) {
		return false;
	}
	if (!createInitialTile(firstInRow)) {
		return false;
	}
	if (!createFirstRow(columns, firstInRow)) {
		return false;
	}
	if (!createFurtherRows(firstInRow, columns, rows)) {
		return false;
	}
	return true;

}

bool InitWorldCommand::createFirstRowTile(std::shared_ptr<mpw::Tile> &next) {

	// new variable x: EInt
	int x;

	// new instance: next_forOutParameter:Tile
	std::shared_ptr < mpw::Tile > next_forOutParameter = std::make_shared<
			mpw::Tile>();

	// new instance: newLocation:Location
	mpw::Location newLocation;

	if (!self->getTiles().contains(next)) {
		return false;
	}

	// new variable from reference: next:Tile -> location -> o0:Location

	mpw::Location o0 = next->getLocation();

	x = o0.getColumn();

	// set attribute condition newLocation.column := x+1
	newLocation.setColumn(x + 1);

	// create reference: CREATE next:Tile -> east -> next_forOutParameter:Tile
	executeSetProperty(next, mpw::Tile::cFeatureKeyEast, next->getEast(),
			next_forOutParameter);

	// create reference: CREATE next_forOutParameter:Tile -> location -> newLocation:Location
	executeSetValueProperty(next_forOutParameter,
			mpw::Tile::cFeatureKeyLocation, next_forOutParameter->getLocation(),
			newLocation);

	// create reference: CREATE self:EditorWorld -> tiles -> next_forOutParameter:Tile
	executeAddReference(self, kara::ConcreteWorld::cFeatureKeyTiles,
			next_forOutParameter);

	next = next_forOutParameter;

	return true;

}

bool InitWorldCommand::createInitialTile(
		std::shared_ptr<mpw::Tile> &firstInRow) {

	// new instance: firstInRow_forOutParameter:Tile
	std::shared_ptr < mpw::Tile > firstInRow_forOutParameter = std::make_shared<
			mpw::Tile>();

	// new instance: o0:Location
	mpw::Location o0;

	// create reference: CREATE firstInRow_forOutParameter:Tile -> location -> o0:Location
	executeSetValueProperty(firstInRow_forOutParameter,
			mpw::Tile::cFeatureKeyLocation,
			firstInRow_forOutParameter->getLocation(), o0);

	// create reference: CREATE self:EditorWorld -> tiles -> firstInRow_forOutParameter:Tile
	executeAddReference(self, kara::ConcreteWorld::cFeatureKeyTiles,
			firstInRow_forOutParameter);

	firstInRow = firstInRow_forOutParameter;

	return true;

}

bool InitWorldCommand::createFirstTileForNextRow(
		std::shared_ptr<mpw::Tile> &firstInRow) {

	// new variable y: EInt
	int y;

	// new instance: firstInRow_forOutParameter:Tile
	std::shared_ptr < mpw::Tile > firstInRow_forOutParameter = std::make_shared<
			mpw::Tile>();

	// new instance: newLocation:Location
	mpw::Location newLocation;

	if (!self->getTiles().contains(firstInRow)) {
		return false;
	}

	// new variable from reference: firstInRow:Tile -> location -> o0:Location

	mpw::Location o0 = firstInRow->getLocation();

	y = o0.getRow();

	// assert condition: o0.column == 0
	if (o0.getColumn() != 0) {
		return false;
	}

	// set attribute condition newLocation.row := y+1
	newLocation.setRow(y + 1);

	// create reference: CREATE firstInRow_forOutParameter:Tile -> location -> newLocation:Location
	executeSetValueProperty(firstInRow_forOutParameter,
			mpw::Tile::cFeatureKeyLocation,
			firstInRow_forOutParameter->getLocation(), newLocation);

	// create reference: CREATE firstInRow:Tile -> south -> firstInRow_forOutParameter:Tile
	executeSetProperty(firstInRow, mpw::Tile::cFeatureKeySouth,
			firstInRow->getSouth(), firstInRow_forOutParameter);

	// create reference: CREATE self:EditorWorld -> tiles -> firstInRow_forOutParameter:Tile
	executeAddReference(self, kara::ConcreteWorld::cFeatureKeyTiles,
			firstInRow_forOutParameter);

	firstInRow = firstInRow_forOutParameter;

	return true;

}

bool InitWorldCommand::createFurtherRowTile(std::shared_ptr<mpw::Tile> &next) {

	// new variable x: EInt
	int x;

	// new variable y: EInt
	int y;

	// new instance: next_forOutParameter:Tile
	std::shared_ptr < mpw::Tile > next_forOutParameter = std::make_shared<
			mpw::Tile>();

	// new instance: newLocation:Location
	mpw::Location newLocation;

	if (!self->getTiles().contains(next)) {
		return false;
	}

	// new variable from reference: next:Tile -> location -> o0:Location

	mpw::Location o0 = next->getLocation();

	// new variable from reference: next:Tile -> north -> north:Tile

	std::shared_ptr < mpw::Tile > north = next->getNorth();
	if (north.get() == nullptr) {
		return false;
	}

	// new variable from reference: north:Tile -> east -> northEast:Tile

	std::shared_ptr < mpw::Tile > northEast = north->getEast();
	if (northEast.get() == nullptr) {
		return false;
	}

	x = o0.getColumn();

	y = o0.getRow();

	// set attribute condition newLocation.column := x+1
	newLocation.setColumn(x + 1);

	// set attribute condition newLocation.row := y
	newLocation.setRow(y);

	// create reference: CREATE northEast:Tile -> south -> next_forOutParameter:Tile
	executeSetProperty(northEast, mpw::Tile::cFeatureKeySouth,
			northEast->getSouth(), next_forOutParameter);

	// create reference: CREATE next:Tile -> east -> next_forOutParameter:Tile
	executeSetProperty(next, mpw::Tile::cFeatureKeyEast, next->getEast(),
			next_forOutParameter);

	// create reference: CREATE next_forOutParameter:Tile -> location -> newLocation:Location
	executeSetValueProperty(next_forOutParameter,
			mpw::Tile::cFeatureKeyLocation, next_forOutParameter->getLocation(),
			newLocation);

	// create reference: CREATE self:EditorWorld -> tiles -> next_forOutParameter:Tile
	executeAddReference(self, kara::ConcreteWorld::cFeatureKeyTiles,
			next_forOutParameter);

	next = next_forOutParameter;

	return true;

}

bool InitWorldCommand::createFirstRow(int columns,
		std::shared_ptr<mpw::Tile> next) {

	for (int i = 0; i < static_cast<int>(columns - 1); i++) {
		if (!createFirstRowTile(next)) {
			return false;
		}
	}
	return true;

}

bool InitWorldCommand::createFurtherRows(std::shared_ptr<mpw::Tile> &firstInRow,
		int columns, int rows) {

	for (int i = 0; i < static_cast<int>(rows - 1); i++) {
		if (!createFurtherRow(firstInRow, columns)) {
			return false;
		}
	}
	return true;

}

bool InitWorldCommand::createFurtherRow(std::shared_ptr<mpw::Tile> &firstInRow,
		int columns) {

	if (!createFirstTileForNextRow(firstInRow)) {
		return false;
	}
	if (!createFurtherRowTiles(columns, firstInRow)) {
		return false;
	}
	return true;

}

bool InitWorldCommand::createFurtherRowTiles(int columns,
		std::shared_ptr<mpw::Tile> next) {

	for (int i = 0; i < static_cast<int>(columns - 1); i++) {
		if (!createFurtherRowTile(next)) {
			return false;
		}
	}
	return true;

}

bool InitWorldCommand::setSize(int columns, int rows) {

	// new instance: o0:Size
	mpw::Size o0;

	// set attribute condition o0.columnCount := columns
	o0.setColumnCount(columns);

	// set attribute condition o0.rowCount := rows
	o0.setRowCount(rows);

	// create reference: CREATE self:EditorWorld -> stageSize -> o0:Size
	executeSetValueProperty(self, kara::ConcreteWorld::cFeatureKeyStageSize,
			self->getStageSize(), o0);

	return true;

}

bool InitWorldCommand::clearTiles() {

	// clear references: self:EditorWorld -> tileContents -> o0:TileContent
	while (self->getTileContents().size() > 0) {
		executeRemoveReference(self,
				kara::ConcreteWorld::cFeatureKeyTileContents,
				self->getTileContents().front());
	}

	// clear references: self:EditorWorld -> tiles -> o1:Tile
	while (self->getTiles().size() > 0) {
		executeRemoveReference(self, kara::ConcreteWorld::cFeatureKeyTiles,
				self->getTiles().front());
	}

	return true;

}

bool InitWorldCommand::clearWorld() {

	if (karaIsOnTile()) {
		return clearKaraAndTiles();
	}
	return clearTiles();

}

bool InitWorldCommand::karaIsOnTile() {

	// new variable from reference: self:EditorWorld -> kara -> o0:EditorKara

	std::shared_ptr < kara::EditorKara > o0 = std::dynamic_pointer_cast
			< kara::EditorKara > (self->getKara());
	if (o0.get() == nullptr) {
		return false;
	}

	// new variable from reference: o0:EditorKara -> currentTile -> o1:Tile

	std::shared_ptr < mpw::Tile > o1 = o0->getCurrentTile();
	if (o1.get() == nullptr) {
		return false;
	}

	return true;

}

bool InitWorldCommand::clearKaraAndTiles() {

	if (!resetKaraTile()) {
		return false;
	}
	if (!clearTiles()) {
		return false;
	}
	return true;

}

bool InitWorldCommand::resetKaraTile() {

	// new variable from reference: self:EditorWorld -> kara -> o0:EditorKara

	std::shared_ptr < kara::EditorKara > o0 = std::dynamic_pointer_cast
			< kara::EditorKara > (self->getKara());
	if (o0.get() == nullptr) {
		return false;
	}

	// new variable from reference: o0:EditorKara -> currentTile -> o1:Tile

	std::shared_ptr < mpw::Tile > o1 = o0->getCurrentTile();
	if (o1.get() == nullptr) {
		return false;
	}

	// remove reference: DELETE o0:EditorKara -> currentTile -> o1:Tile

	executeSetProperty(o0, kara::ConcreteKara::cFeatureKeyCurrentTile,
			o0->getCurrentTile(), nullptr);

	return true;

}

}

