/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_KARA_H
#define DE_UNISTUTTGART_KARA_KARA_H

#include <memory>
#include <string>
#include "ObservableProperties.h"
#include "Direction.h"
#include "Location.h"

namespace kara {
class KaraGame;
}
namespace kara {
class ConcreteKara;
}
namespace mpw {
class UserInputInterface;
}
namespace kara {
class GameKara;
}
namespace kara {
class EditorKara;
}

namespace kara {

class Kara: public std::enable_shared_from_this<Kara> {
private:

	std::weak_ptr<kara::KaraGame> game;
	std::shared_ptr<kara::ConcreteKara> internalKara;

public:

	/**
	 * Create a new Kara object without initializing it.
	 */
	Kara();
	/**
	 * Internal constructor.
	 */
	Kara(std::shared_ptr<kara::KaraGame> game,
			std::shared_ptr<kara::ConcreteKara> internalKara);
	/**
	 * Move the kara one step towards its looking direction.<br/>
	 * <br/>
	 * <b>requires / ensures:</b> Kara is placed on a tile.<br/>
	 * <b>requires:</b> Kara's front must not be blocked or outside world<br/>
	 * <b>requires:</b> A front mushroom has to be movable
	 * 
	 */
	void move();
	/**
	 * Drop a leaf to the tile on which the kara is currently.<br/>
	 * <br/>
	 * <b>requires / ensures:</b> Kara is placed on a tile.<br/>
	 * <b>requires:</b> the kara must not be on any leaf<br/>
	 * <b>ensures:</b> there has to be a leaf available on the kara's tile
	 * 
	 */
	void putLeaf();
	/**
	 * Pick up a leaf from the tile on which the kara is currently.<br/>
	 * <br/>
	 * <b>requires / ensures:</b> Kara is placed on a tile.<br/>
	 * <b>requires:</b> there has to be a leaf available on the kara's tile<br/>
	 * <b>ensures:</b> the kara must not be on any leaf
	 * 
	 */
	void removeLeaf();
	/**
	 * Changes the looking direction 90 degrees to the left, e.g., when looking north the kara will look towards west afterwards.<br/>
	 * <br/>
	 * <b>requires / ensures:</b> Kara is placed on a tile.
	 * 
	 */
	void turnLeft();
	/**
	 * Changes the looking direction 90 degrees to the right, e.g., when looking north the kara will look towards east afterwards.<br/>
	 * <br/>
	 * <b>requires / ensures:</b> Kara is placed on a tile.
	 * 
	 */
	void turnRight();
	/**
	 * Writes a new string for this actor to the game log. The message
	 * will be displayed in a way that it can be associated to this object.
	 */
	void write(std::string message);
	/**
	 * Get the current kara looking direction.
	 */
	mpw::Direction getDirection() const noexcept;
	/**
	 * Checks the kara's current tile for leaf.
	 */
	bool onLeaf() const noexcept;
	/**
	 * Checks if a tree is at the left of the kara.
	 */
	bool treeLeft() const noexcept;
	/**
	 * Checks if a mushroom is at the front of the kara.
	 */
	bool mushroomFront() const noexcept;
	/**
	 * Get the current kara's location.
	 */
	mpw::Location getLocation() const noexcept;
	/**
	 * Checks if a tree is at the right of the kara.
	 */
	bool treeRight() const noexcept;
	/**
	 * Checks if a tree is at the front of the kara.
	 */
	bool treeFront() const noexcept;
	/**
	 * Read a number from the simulator UI for further use.
	 */
	int readNumber(std::string message);
	/**
	 * Read a string from the simulator UI for further use.
	 */
	std::string readString(std::string message);

	/**
	 * Virtual desctructor to support inheritance.
	 */
	virtual ~Kara() = default;

	/**
	 * Get the internal game representation of the Kara.
	 */
	std::shared_ptr<kara::GameKara> getInternalKara() noexcept;
	/**
	 * Get the internal game representation of the Kara.
	 */
	std::shared_ptr<const kara::GameKara> getInternalKara() const noexcept;
	/**
	 * Get the internal editor representation of the Kara.
	 */
	std::shared_ptr<kara::EditorKara> getInternalEditorKara() noexcept;
	/**
	 * Get the internal editor representation of the Kara.
	 */
	std::shared_ptr<const kara::EditorKara> getInternalEditorKara() const noexcept;

};

}

#endif //DE_UNISTUTTGART_KARA_KARA_H
