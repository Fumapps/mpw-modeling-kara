/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_COMMANDSREMOVELEAF_H
#define DE_UNISTUTTGART_KARA_COMMANDSREMOVELEAF_H

#include "CompositeCommandBase.h"
#include "RemoveLeafCommandParameters.h"

#include "GameLog.h"
#include "ConcreteKara.h"
#include "Tile.h"
#include "Stage.h"
#include "Leaf.h"
#include "LogEntry.h"
#include "TileContent.h"

namespace commands {

/**
 * Pick up a leaf from the tile on which the kara is currently.<br/>
 * <br/>
 * <b>requires / ensures:</b> Kara is placed on a tile.<br/>
 * <b>requires:</b> there has to be a leaf available on the kara's tile<br/>
 * <b>ensures:</b> the kara must not be on any leaf
 * 
 */

class RemoveLeafCommand final : public CompositeCommandBase {
private:
	std::shared_ptr<kara::ConcreteKara> self;
	commands::CommandStack &commandStack;
	std::shared_ptr<mpw::GameLog> gameLog;

public:

	RemoveLeafCommand(RemoveLeafCommandParameters parameters) : self(
			parameters.self), commandStack(parameters.commandStack), gameLog(
			parameters.gameLog)

	{
	}

	void execute() override;

private:

	bool internalMainUnit();

	std::shared_ptr<kara::Leaf> execute_findLeaf(mpw::Tile &source);

	bool addGameLog();

};

}

#endif //DE_UNISTUTTGART_KARA_COMMANDSREMOVELEAF_H

