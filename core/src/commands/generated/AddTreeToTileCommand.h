/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_COMMANDSADDTREETOTILE_H
#define DE_UNISTUTTGART_KARA_COMMANDSADDTREETOTILE_H

#include "CompositeCommandBase.h"
#include "AddTreeToTileCommandParameters.h"

#include "Location.h"
#include "ConcreteWorld.h"
#include "Tree.h"
#include "Tile.h"
#include "Size.h"
#include "TileContent.h"

namespace commands {

/**
 * Place a tree at the given location. The location has to be empty before a tree can be placed.<br/>
 * <br/>
 * <b>requires / ensures:</b> the world tiles must not be empty<br/>
 * <b>ensures:</b> a tree has to be placed on the tile's location<br/>
 * <b>requires:</b> location has to be on the world<br/>
 * <b>requires:</b> the tile at the given location has to be empty
 * 
 */

class AddTreeToTileCommand final : public CompositeCommandBase {
private:
	std::shared_ptr<kara::ConcreteWorld> self;
	commands::CommandStack &commandStack;

	mpw::Location location;

public:

	AddTreeToTileCommand(AddTreeToTileCommandParameters parameters) : self(
			parameters.self), commandStack(parameters.commandStack), location(
			parameters.location)

	{
	}

	void execute() override;

private:

	bool internalMainUnit();

	std::shared_ptr<mpw::Tile> execute_findO1(kara::EditorWorld &source);

};

}

#endif //DE_UNISTUTTGART_KARA_COMMANDSADDTREETOTILE_H

