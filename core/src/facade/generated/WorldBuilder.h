/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_WORLDBUILDER_H
#define DE_UNISTUTTGART_KARA_WORLDBUILDER_H

#include <memory>
#include <string>
#include "ObservableProperties.h"
#include "Location.h"
#include "Direction.h"

namespace kara {
class EditorWorld;
}
namespace kara {
class KaraGame;
}
namespace kara {
class World;
}

namespace kara {

class WorldBuilder: public std::enable_shared_from_this<WorldBuilder> {
private:

	std::shared_ptr<kara::EditorWorld> world;
	std::weak_ptr<kara::KaraGame> game;

public:

	/**
	 * Creates a new WorldBuilder object which then can be used to defined the given World.
	 */
	WorldBuilder(std::shared_ptr<kara::KaraGame> game);
	/**
	 * Place a leaf at the given location. The location has to be empty before a leaf can be placed.<br/>
	 * <br/>
	 * <b>requires / ensures:</b> the world tiles must not be empty<br/>
	 * <b>ensures:</b> a leaf has to be placed on the tile's location<br/>
	 * <b>requires:</b> the tile at the given location has to be empty<br/>
	 * <b>requires:</b> location has to be on the world
	 * 
	 */
	WorldBuilder& addLeafToTile(mpw::Location location);
	/**
	 * Place a mushroom at the given location. The location has to be empty before a mushroom can be placed.<br/>
	 * <br/>
	 * <b>requires / ensures:</b> the world tiles must not be empty<br/>
	 * <b>ensures:</b> a mushroom has to be placed on the tile's location<br/>
	 * <b>requires:</b> location has to be on the world<br/>
	 * <b>requires:</b> the tile at the given location has to be empty
	 * 
	 */
	WorldBuilder& addMushroomToTile(mpw::Location location);
	/**
	 * Place a tree at the given location. The location has to be empty before a tree can be placed.<br/>
	 * <br/>
	 * <b>requires / ensures:</b> the world tiles must not be empty<br/>
	 * <b>ensures:</b> a tree has to be placed on the tile's location<br/>
	 * <b>requires:</b> location has to be on the world<br/>
	 * <b>requires:</b> the tile at the given location has to be empty
	 * 
	 */
	WorldBuilder& addTreeToTile(mpw::Location location);
	/**
	 * Clears all contents of the tile identified by the given location.<br/>
	 * <br/>
	 * <b>requires / ensures:</b> the world tiles must not be empty<br/>
	 * <b>requires:</b> location has to be on the world<br/>
	 * <b>ensures:</b> the tile's contents have to be empty
	 * 
	 */
	WorldBuilder& clearTile(mpw::Location location);
	/**
	 * Initialize a kara object with the given parameters. Once a kara is initialized, the method must not be called again.<br/>
	 * <br/>
	 * <b>requires / ensures:</b> the world tiles must not be empty<br/>
	 * <b>requires:</b> kara must not be already initialized<br/>
	 * <b>requires:</b> location has to be on the world<br/>
	 * <b>ensures:</b> Kara has to be placed on the tile's location
	 * 
	 */
	WorldBuilder& initKara(mpw::Location location, mpw::Direction direction);
	/**
	 * Defines a new world by creating a new, empty world of the given size.<br/>
	 * <br/>
	 * <b>requires / ensures:</b> the world tiles must not be empty<br/>
	 * <b>requires:</b> size must be > 0<br/>
	 * <b>ensures:</b> size of world is set
	 * 
	 */
	WorldBuilder& initWorld(int columns, int rows);
	/**
	 * Place a leaf at the given location. The location has to be empty before a leaf can be placed.<br/>
	 * <br/>
	 * <b>requires / ensures:</b> the world tiles must not be empty<br/>
	 * <b>ensures:</b> a leaf has to be placed on the tile's location<br/>
	 * <b>requires:</b> the tile at the given location has to be empty<br/>
	 * <b>requires:</b> location has to be on the world
	 * 
	 */
	WorldBuilder& addLeafToTile(int locationX, int locationY);
	/**
	 * Place a mushroom at the given location. The location has to be empty before a mushroom can be placed.<br/>
	 * <br/>
	 * <b>requires / ensures:</b> the world tiles must not be empty<br/>
	 * <b>ensures:</b> a mushroom has to be placed on the tile's location<br/>
	 * <b>requires:</b> location has to be on the world<br/>
	 * <b>requires:</b> the tile at the given location has to be empty
	 * 
	 */
	WorldBuilder& addMushroomToTile(int locationX, int locationY);
	/**
	 * Place a tree at the given location. The location has to be empty before a tree can be placed.<br/>
	 * <br/>
	 * <b>requires / ensures:</b> the world tiles must not be empty<br/>
	 * <b>ensures:</b> a tree has to be placed on the tile's location<br/>
	 * <b>requires:</b> location has to be on the world<br/>
	 * <b>requires:</b> the tile at the given location has to be empty
	 * 
	 */
	WorldBuilder& addTreeToTile(int locationX, int locationY);
	/**
	 * Clears all contents of the tile identified by the given location.<br/>
	 * <br/>
	 * <b>requires / ensures:</b> the world tiles must not be empty<br/>
	 * <b>requires:</b> location has to be on the world<br/>
	 * <b>ensures:</b> the tile's contents have to be empty
	 * 
	 */
	WorldBuilder& clearTile(int locationX, int locationY);
	/**
	 * Initialize a kara object with the given parameters. Once a kara is initialized, the method must not be called again.<br/>
	 * <br/>
	 * <b>requires / ensures:</b> the world tiles must not be empty<br/>
	 * <b>requires:</b> kara must not be already initialized<br/>
	 * <b>requires:</b> location has to be on the world<br/>
	 * <b>ensures:</b> Kara has to be placed on the tile's location
	 * 
	 */
	WorldBuilder& initKara(int locationX, int locationY,
			mpw::Direction direction);

	/**
	 * Virtual desctructor to support inheritance.
	 */
	virtual ~WorldBuilder() = default;

};

}

#endif //DE_UNISTUTTGART_KARA_WORLDBUILDER_H
