/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_COMMANDSTURNRIGHT_H
#define DE_UNISTUTTGART_KARA_COMMANDSTURNRIGHT_H

#include "CompositeCommandBase.h"
#include "TurnRightCommandParameters.h"

#include "GameLog.h"
#include "ConcreteKara.h"
#include "LogEntry.h"
#include "Tile.h"
#include "Direction.h"
#include "Stage.h"

namespace commands {

/**
 * Changes the looking direction 90 degrees to the right, e.g., when looking north the kara will look towards east afterwards.<br/>
 * <br/>
 * <b>requires / ensures:</b> Kara is placed on a tile.
 * 
 */

class TurnRightCommand final : public CompositeCommandBase {
private:
	std::shared_ptr<kara::ConcreteKara> self;
	commands::CommandStack &commandStack;
	std::shared_ptr<mpw::GameLog> gameLog;

public:

	TurnRightCommand(TurnRightCommandParameters parameters) : self(
			parameters.self), commandStack(parameters.commandStack), gameLog(
			parameters.gameLog)

	{
	}

	void execute() override;

private:

	bool internalMainUnit();

	bool turnRightNorth();

	bool turnRightSouth();

	bool turnRightWest();

	bool turnRightEast();

	bool addGameLog();

};

}

#endif //DE_UNISTUTTGART_KARA_COMMANDSTURNRIGHT_H

