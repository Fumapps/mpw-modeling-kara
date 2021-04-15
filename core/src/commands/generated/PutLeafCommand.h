/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_COMMANDSPUTLEAF_H
#define DE_UNISTUTTGART_KARA_COMMANDSPUTLEAF_H

#include "CompositeCommandBase.h"
#include "PutLeafCommandParameters.h"

#include "Leaf.h"
#include "LogEntry.h"
#include "GameLog.h"
#include "Stage.h"
#include "Tile.h"
#include "ConcreteKara.h"
#include "TileContent.h"

namespace commands {

/**
 * Drop a leaf to the tile on which the kara is currently.<br/>
 * <br/>
 * <b>requires / ensures:</b> Kara is placed on a tile.<br/>
 * <b>requires:</b> the kara must not be on any leaf<br/>
 * <b>ensures:</b> there has to be a leaf available on the kara's tile
 * 
 */

class PutLeafCommand final : public CompositeCommandBase {
private:
	std::shared_ptr<kara::ConcreteKara> self;
	commands::CommandStack &commandStack;
	std::shared_ptr<mpw::GameLog> gameLog;

public:

	PutLeafCommand(PutLeafCommandParameters parameters) : self(parameters.self), commandStack(
			parameters.commandStack), gameLog(parameters.gameLog)

	{
	}

	void execute() override;

private:

	bool internalMainUnit();

	bool addGameLog();

};

}

#endif //DE_UNISTUTTGART_KARA_COMMANDSPUTLEAF_H

