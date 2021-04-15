/*
 * This file is generated. Do not change it manually.
 */

#include "WorldBuilder.h"

#include <stdexcept>

#include "CommandStack.h"
#include "GamePerformance.h"
#include "EditorWorld.h"
#include "KaraGame.h"
#include "World.h"

namespace kara {

WorldBuilder::WorldBuilder(std::shared_ptr<kara::KaraGame> game) {
	this->game = game;
	this->world = game->getWorld()->getInternalEditorWorld();
}

WorldBuilder& WorldBuilder::addLeafToTile(mpw::Location location) {
	commands::AddLeafToTileCommandParameters parameters(
	/*self*/nullptr, *game.lock()->getEditorCommandStack(), location);
	game.lock()->getPerformance()->preExecuteEditorCommand();
	world->addLeafToTile(parameters);
	return *this->shared_from_this();
}

WorldBuilder& WorldBuilder::addMushroomToTile(mpw::Location location) {
	commands::AddMushroomToTileCommandParameters parameters(
	/*self*/nullptr, *game.lock()->getEditorCommandStack(), location);
	game.lock()->getPerformance()->preExecuteEditorCommand();
	world->addMushroomToTile(parameters);
	return *this->shared_from_this();
}

WorldBuilder& WorldBuilder::addTreeToTile(mpw::Location location) {
	commands::AddTreeToTileCommandParameters parameters(
	/*self*/nullptr, *game.lock()->getEditorCommandStack(), location);
	game.lock()->getPerformance()->preExecuteEditorCommand();
	world->addTreeToTile(parameters);
	return *this->shared_from_this();
}

WorldBuilder& WorldBuilder::clearTile(mpw::Location location) {
	commands::ClearTileCommandParameters parameters(
	/*self*/nullptr, *game.lock()->getEditorCommandStack(), location);
	game.lock()->getPerformance()->preExecuteEditorCommand();
	world->clearTile(parameters);
	return *this->shared_from_this();
}

WorldBuilder& WorldBuilder::initKara(mpw::Location location,
		mpw::Direction direction) {
	commands::InitKaraCommandParameters parameters(
	/*self*/nullptr, *game.lock()->getEditorCommandStack(), location,
			direction);
	game.lock()->getPerformance()->preExecuteEditorCommand();
	world->initKara(parameters);
	return *this->shared_from_this();
}

WorldBuilder& WorldBuilder::initWorld(int columns, int rows) {
	commands::InitWorldCommandParameters parameters(
	/*self*/nullptr, *game.lock()->getEditorCommandStack(), columns, rows);
	game.lock()->getPerformance()->preExecuteEditorCommand();
	world->initWorld(parameters);
	return *this->shared_from_this();
}

WorldBuilder& WorldBuilder::addLeafToTile(int locationX, int locationY) {
	mpw::Location location(locationX, locationY);
	commands::AddLeafToTileCommandParameters parameters(
	/*self*/nullptr, *game.lock()->getEditorCommandStack(), location);
	game.lock()->getPerformance()->preExecuteEditorCommand();
	world->addLeafToTile(parameters);
	return *this->shared_from_this();
}

WorldBuilder& WorldBuilder::addMushroomToTile(int locationX, int locationY) {
	mpw::Location location(locationX, locationY);
	commands::AddMushroomToTileCommandParameters parameters(
	/*self*/nullptr, *game.lock()->getEditorCommandStack(), location);
	game.lock()->getPerformance()->preExecuteEditorCommand();
	world->addMushroomToTile(parameters);
	return *this->shared_from_this();
}

WorldBuilder& WorldBuilder::addTreeToTile(int locationX, int locationY) {
	mpw::Location location(locationX, locationY);
	commands::AddTreeToTileCommandParameters parameters(
	/*self*/nullptr, *game.lock()->getEditorCommandStack(), location);
	game.lock()->getPerformance()->preExecuteEditorCommand();
	world->addTreeToTile(parameters);
	return *this->shared_from_this();
}

WorldBuilder& WorldBuilder::clearTile(int locationX, int locationY) {
	mpw::Location location(locationX, locationY);
	commands::ClearTileCommandParameters parameters(
	/*self*/nullptr, *game.lock()->getEditorCommandStack(), location);
	game.lock()->getPerformance()->preExecuteEditorCommand();
	world->clearTile(parameters);
	return *this->shared_from_this();
}

WorldBuilder& WorldBuilder::initKara(int locationX, int locationY,
		mpw::Direction direction) {
	mpw::Location location(locationX, locationY);
	commands::InitKaraCommandParameters parameters(
	/*self*/nullptr, *game.lock()->getEditorCommandStack(), location,
			direction);
	game.lock()->getPerformance()->preExecuteEditorCommand();
	world->initKara(parameters);
	return *this->shared_from_this();
}

}

