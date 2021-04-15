/*
 * This file is generated. Do not change it manually.
 */

#include "ConcreteWorld.h"

#include <stdexcept>

#include "CollectionHelpers.hpp"
#include "CommandStack.h"
#include "ConcreteKara.h"
#include "Tile.h"
#include "TileContent.h"
#include "Leaf.h"
#include "Mushroom.h"
#include "Tree.h"
#include "Stage.h"

#include "AddLeafToTileCommand.h"
#include "AddMushroomToTileCommand.h"
#include "AddTreeToTileCommand.h"
#include "ClearTileCommand.h"
#include "InitKaraCommand.h"
#include "InitWorldCommand.h"

namespace kara {

ConcreteWorld::ConcreteWorld() {

	this->kara = std::make_shared<kara::ConcreteKara>();
}

std::shared_ptr<const mpw::Tile> ConcreteWorld::getTileAt(
		mpw::Location location) const noexcept {
	try {
		return collectionhelpers::get_at(this->getTiles(),
				location.getRow() * this->getStageSize().getColumnCount()
						+ location.getColumn()).value();
	} catch (...) {
		return nullptr;
	}
}

bool ConcreteWorld::isOnlyKaraAtLocation(mpw::Location location) const noexcept {
	try {
		return (helper_IsOnlyKaraAtLocation_kara_currentTile_result0_location(
				location) == location) ? (helper_IsOnlyKaraAtLocation_kara_currentTile_result0_contents_size(
				location) == 1) :
				true;
	} catch (...) {
		return false;
	}
}

int ConcreteWorld::helper_IsOnlyKaraAtLocation_kara_currentTile_result0_contents_size(
		mpw::Location location) const noexcept {
	std::shared_ptr<const mpw::Tile> result0 =
			this->getKara()->getCurrentTile();
	if (result0 == nullptr) {
		return 0;
	}
	int result1 = result0->getContents().size();
	return result1;
}

mpw::Location ConcreteWorld::helper_IsOnlyKaraAtLocation_kara_currentTile_result0_location(
		mpw::Location location) const noexcept {
	std::shared_ptr<const mpw::Tile> result0 =
			this->getKara()->getCurrentTile();
	if (result0 == nullptr) {
		return {};
	}
	mpw::Location result1 = result0->getLocation();
	return result1;
}

mpw::Size ConcreteWorld::getWorldSize() const noexcept {
	try {
		return this->getStageSize();
	} catch (...) {
		return {};
	}
}

bool ConcreteWorld::isLocationInWorld(mpw::Location location) const noexcept {
	try {
		return location.getColumn() >= 0
				&& location.getColumn() < this->getStageSize().getColumnCount()
				&& location.getRow() >= 0
				&& location.getRow() < this->getStageSize().getRowCount();
	} catch (...) {
		return false;
	}
}

void ConcreteWorld::addLeafToTile(
		commands::AddLeafToTileCommandParameters &parameters) {
	parameters.self = this->shared_from_this();
	auto command = std::make_shared < commands::AddLeafToTileCommand
			> (parameters);
	parameters.commandStack.execute(command);
}

void ConcreteWorld::addMushroomToTile(
		commands::AddMushroomToTileCommandParameters &parameters) {
	parameters.self = this->shared_from_this();
	auto command = std::make_shared < commands::AddMushroomToTileCommand
			> (parameters);
	parameters.commandStack.execute(command);
}

void ConcreteWorld::addTreeToTile(
		commands::AddTreeToTileCommandParameters &parameters) {
	parameters.self = this->shared_from_this();
	auto command = std::make_shared < commands::AddTreeToTileCommand
			> (parameters);
	parameters.commandStack.execute(command);
}

void ConcreteWorld::clearTile(
		commands::ClearTileCommandParameters &parameters) {
	parameters.self = this->shared_from_this();
	auto command = std::make_shared < commands::ClearTileCommand > (parameters);
	parameters.commandStack.execute(command);
}

void ConcreteWorld::initKara(commands::InitKaraCommandParameters &parameters) {
	parameters.self = this->shared_from_this();
	auto command = std::make_shared < commands::InitKaraCommand > (parameters);
	parameters.commandStack.execute(command);
}

void ConcreteWorld::initWorld(
		commands::InitWorldCommandParameters &parameters) {
	parameters.self = this->shared_from_this();
	auto command = std::make_shared < commands::InitWorldCommand > (parameters);
	parameters.commandStack.execute(command);
}

std::shared_ptr<kara::ConcreteKara> ConcreteWorld::getKara() noexcept {
	return this->kara;
}

std::shared_ptr<const kara::ConcreteKara> ConcreteWorld::getKara() const noexcept {
	return this->kara;
}

std::shared_ptr<kara::ReadOnlyKara> ConcreteWorld::getReadOnlyKara() noexcept {
	return this->kara;
}
std::shared_ptr<const kara::ReadOnlyKara> ConcreteWorld::getReadOnlyKara() const noexcept {
	return this->kara;
}

std::shared_ptr<kara::GameKara> ConcreteWorld::getGameKara() noexcept {
	return this->kara;
}
std::shared_ptr<const kara::GameKara> ConcreteWorld::getGameKara() const noexcept {
	return this->kara;
}

std::shared_ptr<kara::EditorKara> ConcreteWorld::getEditorKara() noexcept {
	return this->kara;
}
std::shared_ptr<const kara::EditorKara> ConcreteWorld::getEditorKara() const noexcept {
	return this->kara;
}

void ConcreteWorld::setProperty(unsigned featureKey, Any value) {
	switch (featureKey) {
	}

	inherited::setProperty(featureKey, value);
}

void ConcreteWorld::addToCollection(unsigned featureKey,
		EntityReference reference) {
	switch (featureKey) {
	}

	inherited::addToCollection(featureKey, reference);
}

void ConcreteWorld::removeFromCollection(unsigned featureKey,
		EntityReference reference) {
	switch (featureKey) {
	}

	inherited::removeFromCollection(featureKey, reference);
}

}
