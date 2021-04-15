/*
 * This file is generated. Do not change it manually.
 */

#include "World.h"

#include <stdexcept>

#include "KaraGame.h"
#include "ConcreteWorld.h"
#include "Kara.h"
#include "ConcreteKara.h"
#include "MiniProgrammingWorld.h"

namespace kara {

World::World(std::shared_ptr<kara::KaraGame> game) {
	this->internalWorld = std::make_shared<ConcreteWorld>();
	this->game = game;
	this->kara = std::make_shared < Kara > (game, internalWorld->getKara());
}

mpw::Size World::getWorldSize() const noexcept {
	return internalWorld->getWorldSize();
}

bool World::isLocationInWorld(mpw::Location location) const noexcept {
	return internalWorld->isLocationInWorld(location);
}

std::shared_ptr<kara::GameWorld> World::getInternalWorld() noexcept {
	return this->internalWorld;
}
std::shared_ptr<const kara::GameWorld> World::getInternalWorld() const noexcept {
	return this->internalWorld;
}

std::shared_ptr<kara::EditorWorld> World::getInternalEditorWorld() noexcept {
	return this->internalWorld;
}
std::shared_ptr<const kara::EditorWorld> World::getInternalEditorWorld() const noexcept {
	return this->internalWorld;
}

std::shared_ptr<kara::Kara> World::getKara() noexcept {
	return this->kara;
}
std::shared_ptr<const kara::Kara> World::getKara() const noexcept {
	return this->kara;
}

std::shared_ptr<kara::KaraGame> World::getGame() noexcept {
	return this->game.lock();
}
std::shared_ptr<const kara::KaraGame> World::getGame() const noexcept {
	return this->game.lock();
}

}

