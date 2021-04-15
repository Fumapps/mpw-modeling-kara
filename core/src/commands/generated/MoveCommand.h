/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_COMMANDSMOVE_H
#define DE_UNISTUTTGART_KARA_COMMANDSMOVE_H

#include "CompositeCommandBase.h"
#include "MoveCommandParameters.h"

#include "ConcreteKara.h"
#include "Tile.h"
#include "Mushroom.h"
#include "LogEntry.h"
#include "GameLog.h"
#include "Direction.h"
#include "TileContent.h"
#include "Tree.h"
#include "Stage.h"

namespace commands {

/**
 * Move the kara one step towards its looking direction.<br/>
 * <br/>
 * <b>requires / ensures:</b> Kara is placed on a tile.<br/>
 * <b>requires:</b> Kara's front must not be blocked or outside world<br/>
 * <b>requires:</b> A front mushroom has to be movable
 * 
 */

class MoveCommand final : public CompositeCommandBase {
private:
	std::shared_ptr<kara::ConcreteKara> self;
	commands::CommandStack &commandStack;
	std::shared_ptr<mpw::GameLog> gameLog;

public:

	MoveCommand(MoveCommandParameters parameters) : self(parameters.self), commandStack(
			parameters.commandStack), gameLog(parameters.gameLog)

	{
	}

	void execute() override;

private:

	bool internalMainUnit();

	bool moveNorth();

	bool moveSouth();

	bool moveWest();

	bool moveEast();

	bool moveKara();

	bool moveMushroom();

	bool moveMushroomNorth();

	std::shared_ptr<kara::Mushroom> moveMushroomNorth_findO0(mpw::Tile &source);

	bool dummy();

	bool moveMushroomWest();

	std::shared_ptr<kara::Mushroom> moveMushroomWest_findO0(mpw::Tile &source);

	bool moveMushroomSouth();

	std::shared_ptr<kara::Mushroom> moveMushroomSouth_findO0(mpw::Tile &source);

	bool moveMushroomEast();

	std::shared_ptr<kara::Mushroom> moveMushroomEast_findO0(mpw::Tile &source);

	bool addGameLog();

	bool helper_Precondition2_currentTile_result0_west_result1_west_result2_contents_is_empty() const noexcept;

	bool helper_Precondition2_currentTile_result0_north_result1_north_result2_contents_is_empty() const noexcept;

	bool helper_Precondition2_currentTile_result0_south_result1_south_result2_contents_is_empty() const noexcept;

	bool helper_Precondition2_currentTile_result0_east_result1_east_result2_contents_is_empty() const noexcept;
};

}

#endif //DE_UNISTUTTGART_KARA_COMMANDSMOVE_H

