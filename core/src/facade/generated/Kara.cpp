/*
 * This file is generated. Do not change it manually.
 */

#include "Kara.h"

#include <stdexcept>

#include "CommandStack.h"
#include "GamePerformance.h"
#include "KaraGame.h"
#include "ConcreteKara.h"
#include "UserInputInterface.h"

namespace kara {

Kara::Kara() {
	this->internalKara = std::make_shared<ConcreteKara>();
}

Kara::Kara(std::shared_ptr<kara::KaraGame> game,
		std::shared_ptr<kara::ConcreteKara> internalKara) {
	this->internalKara = internalKara;
	this->game = game;
}

void Kara::move() {
	commands::MoveCommandParameters parameters(
	/*self*/nullptr, *game.lock()->getGameCommandStack(),
			game.lock()->getGameLog());
	game.lock()->getPerformance()->preExecuteGameCommand();
	try {
		internalKara->move(parameters);
		game.lock()->getPerformance()->delayControlFlow();
	} catch (std::exception &e) {
		// Stop the game to prevent execution of further commands!
		game.lock()->getPerformance()->setMode(mpw::Mode::STOPPED);
		throw; // rethrow
	}
}

void Kara::putLeaf() {
	commands::PutLeafCommandParameters parameters(
	/*self*/nullptr, *game.lock()->getGameCommandStack(),
			game.lock()->getGameLog());
	game.lock()->getPerformance()->preExecuteGameCommand();
	try {
		internalKara->putLeaf(parameters);
		game.lock()->getPerformance()->delayControlFlow();
	} catch (std::exception &e) {
		// Stop the game to prevent execution of further commands!
		game.lock()->getPerformance()->setMode(mpw::Mode::STOPPED);
		throw; // rethrow
	}
}

void Kara::removeLeaf() {
	commands::RemoveLeafCommandParameters parameters(
	/*self*/nullptr, *game.lock()->getGameCommandStack(),
			game.lock()->getGameLog());
	game.lock()->getPerformance()->preExecuteGameCommand();
	try {
		internalKara->removeLeaf(parameters);
		game.lock()->getPerformance()->delayControlFlow();
	} catch (std::exception &e) {
		// Stop the game to prevent execution of further commands!
		game.lock()->getPerformance()->setMode(mpw::Mode::STOPPED);
		throw; // rethrow
	}
}

void Kara::turnLeft() {
	commands::TurnLeftCommandParameters parameters(
	/*self*/nullptr, *game.lock()->getGameCommandStack(),
			game.lock()->getGameLog());
	game.lock()->getPerformance()->preExecuteGameCommand();
	try {
		internalKara->turnLeft(parameters);
		game.lock()->getPerformance()->delayControlFlow();
	} catch (std::exception &e) {
		// Stop the game to prevent execution of further commands!
		game.lock()->getPerformance()->setMode(mpw::Mode::STOPPED);
		throw; // rethrow
	}
}

void Kara::turnRight() {
	commands::TurnRightCommandParameters parameters(
	/*self*/nullptr, *game.lock()->getGameCommandStack(),
			game.lock()->getGameLog());
	game.lock()->getPerformance()->preExecuteGameCommand();
	try {
		internalKara->turnRight(parameters);
		game.lock()->getPerformance()->delayControlFlow();
	} catch (std::exception &e) {
		// Stop the game to prevent execution of further commands!
		game.lock()->getPerformance()->setMode(mpw::Mode::STOPPED);
		throw; // rethrow
	}
}

void Kara::write(std::string message) {
	commands::WriteCommandParameters parameters(
	/*self*/nullptr, *game.lock()->getGameCommandStack(),
			game.lock()->getGameLog(), message);
	game.lock()->getPerformance()->preExecuteGameCommand();
	try {
		internalKara->write(parameters);
		game.lock()->getPerformance()->delayControlFlow();
	} catch (std::exception &e) {
		// Stop the game to prevent execution of further commands!
		game.lock()->getPerformance()->setMode(mpw::Mode::STOPPED);
		throw; // rethrow
	}
}

mpw::Direction Kara::getDirection() const noexcept {
	return internalKara->getDirection();
}

bool Kara::onLeaf() const noexcept {
	return internalKara->onLeaf();
}

bool Kara::treeLeft() const noexcept {
	return internalKara->treeLeft();
}

bool Kara::mushroomFront() const noexcept {
	return internalKara->mushroomFront();
}

mpw::Location Kara::getLocation() const noexcept {
	return internalKara->getLocation();
}

bool Kara::treeRight() const noexcept {
	return internalKara->treeRight();
}

bool Kara::treeFront() const noexcept {
	return internalKara->treeFront();
}

int Kara::readNumber(std::string message) {
	auto gameInterface = game.lock()->getUserInputInterface();
	auto result = gameInterface->readInteger(message);
	return result;
}

std::string Kara::readString(std::string message) {
	auto gameInterface = game.lock()->getUserInputInterface();
	auto result = gameInterface->readString(message);
	return result;
}

std::shared_ptr<kara::GameKara> Kara::getInternalKara() noexcept {
	return this->internalKara;
}
std::shared_ptr<const kara::GameKara> Kara::getInternalKara() const noexcept {
	return this->internalKara;
}

std::shared_ptr<kara::EditorKara> Kara::getInternalEditorKara() noexcept {
	return this->internalKara;
}
std::shared_ptr<const kara::EditorKara> Kara::getInternalEditorKara() const noexcept {
	return this->internalKara;
}

}

