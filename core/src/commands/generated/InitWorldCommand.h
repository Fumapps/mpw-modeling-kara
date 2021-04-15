/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_COMMANDSINITWORLD_H
#define DE_UNISTUTTGART_KARA_COMMANDSINITWORLD_H

#include "CompositeCommandBase.h"
#include "InitWorldCommandParameters.h"

#include "TileContent.h"
#include "ConcreteWorld.h"
#include "Location.h"
#include "Tile.h"
#include "ConcreteKara.h"
#include "Size.h"

namespace commands {

/**
 * Defines a new world by creating a new, empty world of the given size.<br/>
 * <br/>
 * <b>requires / ensures:</b> the world tiles must not be empty<br/>
 * <b>requires:</b> size must be > 0<br/>
 * <b>ensures:</b> size of world is set
 * 
 */

class InitWorldCommand final : public CompositeCommandBase {
private:
	std::shared_ptr<kara::ConcreteWorld> self;
	commands::CommandStack &commandStack;

	int columns;

	int rows;

public:

	InitWorldCommand(InitWorldCommandParameters parameters) : self(
			parameters.self), commandStack(parameters.commandStack), columns(
			parameters.columns), rows(parameters.rows)

	{
	}

	void execute() override;

private:

	bool internalMainUnit();

	bool createFirstRowTile(std::shared_ptr<mpw::Tile> &next);

	bool createInitialTile(std::shared_ptr<mpw::Tile> &firstInRow);

	bool createFirstTileForNextRow(std::shared_ptr<mpw::Tile> &firstInRow);

	bool createFurtherRowTile(std::shared_ptr<mpw::Tile> &next);

	bool createFirstRow(int columns, std::shared_ptr<mpw::Tile> next);

	bool createFurtherRows(std::shared_ptr<mpw::Tile> &firstInRow, int columns,
			int rows);

	bool createFurtherRow(std::shared_ptr<mpw::Tile> &firstInRow, int columns);

	bool createFurtherRowTiles(int columns, std::shared_ptr<mpw::Tile> next);

	bool setSize(int columns, int rows);

	bool clearTiles();

	bool clearWorld();

	bool karaIsOnTile();

	bool clearKaraAndTiles();

	bool resetKaraTile();

};

}

#endif //DE_UNISTUTTGART_KARA_COMMANDSINITWORLD_H

