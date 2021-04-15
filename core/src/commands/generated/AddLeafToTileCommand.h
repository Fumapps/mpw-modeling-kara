/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_COMMANDSADDLEAFTOTILE_H
#define DE_UNISTUTTGART_KARA_COMMANDSADDLEAFTOTILE_H

#include "CompositeCommandBase.h"
#include "AddLeafToTileCommandParameters.h"

#include "Location.h"
#include "Leaf.h"
#include "ConcreteWorld.h"
#include "Tile.h"
#include "TileContent.h"
#include "Size.h"
#include "ConcreteKara.h"

namespace commands {

/**
 * Place a leaf at the given location. The location has to be empty before a leaf can be placed.<br/>
 * <br/>
 * <b>requires / ensures:</b> the world tiles must not be empty<br/>
 * <b>ensures:</b> a leaf has to be placed on the tile's location<br/>
 * <b>requires:</b> the tile at the given location has to be empty<br/>
 * <b>requires:</b> location has to be on the world
 * 
 */

class AddLeafToTileCommand final : public CompositeCommandBase {
private:
	std::shared_ptr<kara::ConcreteWorld> self;
	commands::CommandStack &commandStack;

	mpw::Location location;

public:

	AddLeafToTileCommand(AddLeafToTileCommandParameters parameters) : self(
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

#endif //DE_UNISTUTTGART_KARA_COMMANDSADDLEAFTOTILE_H

