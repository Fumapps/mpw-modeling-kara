/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_GAMEKARA_H
#define DE_UNISTUTTGART_KARA_GAMEKARA_H

#include <memory>
#include <string>
#include "ReadOnlyKara.h"
#include "Direction.h"

#include "MoveCommandParameters.h"
#include "PutLeafCommandParameters.h"
#include "RemoveLeafCommandParameters.h"
#include "TurnLeftCommandParameters.h"
#include "TurnRightCommandParameters.h"
#include "WriteCommandParameters.h"

namespace kara {
class ConcreteKara;
}
namespace kara {
class Tree;
}
namespace mpw {
class TileContent;
}
namespace mpw {
class Tile;
}
namespace kara {
class Mushroom;
}
namespace mpw {
class Stage;
}
namespace kara {
class Leaf;
}

namespace kara {

class GameKara: public virtual kara::ReadOnlyKara {

public:

	virtual ~GameKara() = default;

	/// \brief returns a shared_ptr of type GameKara which shares ownership of *this
	std::shared_ptr<GameKara> shared_from_this() {
		return std::dynamic_pointer_cast < GameKara
				> (basetypes::Entity::shared_from_this());
	}
	/// \brief returns a shared_ptr of const type GameKara which shares ownership of *this
	std::shared_ptr<const GameKara> shared_from_this() const {
		return std::dynamic_pointer_cast<const GameKara>(
				basetypes::Entity::shared_from_this());
	}

	virtual void move(commands::MoveCommandParameters &parameters) = 0;

	virtual void putLeaf(commands::PutLeafCommandParameters &parameters) = 0;

	virtual void removeLeaf(
			commands::RemoveLeafCommandParameters &parameters) = 0;

	virtual void turnLeft(commands::TurnLeftCommandParameters &parameters) = 0;

	virtual void turnRight(
			commands::TurnRightCommandParameters &parameters) = 0;

	virtual void write(commands::WriteCommandParameters &parameters) = 0;

};

}

#endif //DE_UNISTUTTGART_KARA_GAMEKARA_H

