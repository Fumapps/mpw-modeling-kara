/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_COMMANDSTURNLEFT_H
#define DE_UNISTUTTGART_KARA_COMMANDSTURNLEFT_H

#include "CompositeCommandBase.h"
#include "TurnLeftCommandParameters.h"

#include "GameLog.h"
#include "LogEntry.h"
#include "ConcreteKara.h"
#include "Direction.h"
#include "Stage.h"
#include "Tile.h"

namespace commands {

/**
 * Changes the looking direction 90 degrees to the left, e.g., when looking north the kara will look towards west afterwards.<br/>
 * <br/>
 * <b>requires / ensures:</b> Kara is placed on a tile.
 * 
 */

class TurnLeftCommand final : public CompositeCommandBase {
private:
	std::shared_ptr<kara::ConcreteKara> self;
	commands::CommandStack &commandStack;
	std::shared_ptr<mpw::GameLog> gameLog;

public:

	TurnLeftCommand(TurnLeftCommandParameters parameters) : self(
			parameters.self), commandStack(parameters.commandStack), gameLog(
			parameters.gameLog)

	{
	}

	void execute() override;

private:

	bool internalMainUnit();

	bool turnLeftNorth();

	bool turnLeftSouth();

	bool turnLeftWest();

	bool turnLeftEast();

	bool addGameLog();

};

}

#endif //DE_UNISTUTTGART_KARA_COMMANDSTURNLEFT_H

