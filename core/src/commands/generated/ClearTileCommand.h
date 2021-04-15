/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_COMMANDSCLEARTILE_H
#define DE_UNISTUTTGART_KARA_COMMANDSCLEARTILE_H

#include "CompositeCommandBase.h"
#include "ClearTileCommandParameters.h"

#include "Location.h"
#include "TileContent.h"
#include "ConcreteWorld.h"
#include "Tile.h"
#include "Size.h"

namespace commands {

/**
 * Clears all contents of the tile identified by the given location.<br/>
 * <br/>
 * <b>requires / ensures:</b> the world tiles must not be empty<br/>
 * <b>requires:</b> location has to be on the world<br/>
 * <b>ensures:</b> the tile's contents have to be empty
 * 
 */

class ClearTileCommand final : public CompositeCommandBase {
private:
	std::shared_ptr<kara::ConcreteWorld> self;
	commands::CommandStack &commandStack;

	mpw::Location location;

public:

	ClearTileCommand(ClearTileCommandParameters parameters) : self(
			parameters.self), commandStack(parameters.commandStack), location(
			parameters.location)

	{
	}

	void execute() override;

private:

	bool internalMainUnit();

	std::shared_ptr<mpw::Tile> execute_findO0(kara::EditorWorld &source);

};

}

#endif //DE_UNISTUTTGART_KARA_COMMANDSCLEARTILE_H

