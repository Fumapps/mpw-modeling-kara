/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_GAMEWORLD_H
#define DE_UNISTUTTGART_KARA_GAMEWORLD_H

#include <memory>
#include <string>
#include "ReadOnlyWorld.h"

namespace kara {
class GameKara;
}

namespace kara {

class GameWorld: public virtual kara::ReadOnlyWorld {

public:

	virtual ~GameWorld() = default;

	/// \brief returns a shared_ptr of type GameWorld which shares ownership of *this
	std::shared_ptr<GameWorld> shared_from_this() {
		return std::dynamic_pointer_cast < GameWorld
				> (basetypes::Entity::shared_from_this());
	}
	/// \brief returns a shared_ptr of const type GameWorld which shares ownership of *this
	std::shared_ptr<const GameWorld> shared_from_this() const {
		return std::dynamic_pointer_cast<const GameWorld>(
				basetypes::Entity::shared_from_this());
	}

	virtual std::shared_ptr<kara::GameKara> getGameKara() noexcept = 0;
	virtual std::shared_ptr<const kara::GameKara> getGameKara() const noexcept = 0;

};

}

#endif //DE_UNISTUTTGART_KARA_GAMEWORLD_H

