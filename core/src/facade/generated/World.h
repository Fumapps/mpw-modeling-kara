/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_WORLD_H
#define DE_UNISTUTTGART_KARA_WORLD_H

#include <memory>
#include <string>
#include "ObservableProperties.h"
#include "Size.h"
#include "Location.h"

namespace kara {
class KaraGame;
}
namespace kara {
class ConcreteWorld;
}
namespace kara {
class Kara;
}
namespace kara {
class ConcreteKara;
}
namespace mpw {
class MiniProgrammingWorld;
}
namespace kara {
class GameWorld;
}
namespace kara {
class EditorWorld;
}

namespace kara {

class World: public std::enable_shared_from_this<World> {
private:

	std::weak_ptr<kara::KaraGame> game;
	std::shared_ptr<kara::ConcreteWorld> internalWorld;
	std::shared_ptr<kara::Kara> kara;

public:

	/**
	 * Initialize a new World and link it to its game object.
	 */
	World(std::shared_ptr<kara::KaraGame> game);
	/**
	 * Return the size of the current world. From the size you can retrieve the number of rows and colums.
	 */
	mpw::Size getWorldSize() const noexcept;
	/**
	 * For a given location, tests whether the location is inside the bound of the world.
	 */
	bool isLocationInWorld(mpw::Location location) const noexcept;

	/**
	 * Virtual desctructor to support inheritance.
	 */
	virtual ~World() = default;

	/**
	 * Get the internal game representation of the World.
	 */
	std::shared_ptr<kara::GameWorld> getInternalWorld() noexcept;
	/**
	 * Get the internal game representation of the World.
	 */
	std::shared_ptr<const kara::GameWorld> getInternalWorld() const noexcept;
	/**
	 * Get the internal editor representation of the World.
	 */
	std::shared_ptr<kara::EditorWorld> getInternalEditorWorld() noexcept;
	/**
	 * Get the internal editor representation of the World.
	 */
	std::shared_ptr<const kara::EditorWorld> getInternalEditorWorld() const noexcept;
	std::shared_ptr<kara::Kara> getKara() noexcept;
	std::shared_ptr<const kara::Kara> getKara() const noexcept;
	/**
	 * Gets the game associated to this World object.
	 */
	std::shared_ptr<kara::KaraGame> getGame() noexcept;
	/**
	 * Gets the game associated to this World object.
	 */
	std::shared_ptr<const kara::KaraGame> getGame() const noexcept;

};

}

#endif //DE_UNISTUTTGART_KARA_WORLD_H
