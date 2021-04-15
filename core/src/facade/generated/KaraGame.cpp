/*
 * This file is generated. Do not change it manually.
 */

#include "KaraGame.h"

#include <stdexcept>

#include "World.h"
#include "GamePerformance.h"
#include "UserInputInterface.h"
#include "CommandStack.h"

namespace kara {

std::shared_ptr<KaraGame> KaraGame::create() {
	auto instance = std::shared_ptr < KaraGame > (new KaraGame);
	instance->init();
	return instance;
}

void KaraGame::init() {

	this->world = std::make_shared < kara::World > (this->shared_from_this());
}

std::shared_ptr<kara::World> KaraGame::getWorld() noexcept {
	return this->world;
}

std::shared_ptr<const kara::World> KaraGame::getWorld() const noexcept {
	return this->world;
}

void KaraGame::startGame() {
	auto performance = getPerformance();
	performance->startGame();
}

void KaraGame::startGamePaused() {
	auto performance = getPerformance();
	performance->startGamePaused();
}

void KaraGame::hardReset() {
	auto performance = getPerformance();
	performance->hardReset();
}

void KaraGame::stopGame() {
	auto performance = getPerformance();
	performance->stopGame();
}

void KaraGame::pauseGame() {
	auto performance = getPerformance();
	performance->pauseGame();
}

void KaraGame::resumeGame() {
	auto performance = getPerformance();
	performance->resumeGame();
}

void KaraGame::confirmAlert(const std::exception &t) {
	auto userInputInterface = getUserInputInterface();
	userInputInterface->confirmAlert(t);
}

std::shared_ptr<commands::CommandStack> KaraGame::getGameCommandStack() {
	auto performance = getPerformance();
	return performance->getGameCommandStack();
}

}
