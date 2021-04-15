/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_EDITORWORLD_H
#define DE_UNISTUTTGART_KARA_EDITORWORLD_H

#include <memory>
#include <string>
#include "ReadOnlyWorld.h"
#include "Size.h"
#include "Location.h"
#include "Direction.h"

#include "AddLeafToTileCommandParameters.h"
#include "AddMushroomToTileCommandParameters.h"
#include "AddTreeToTileCommandParameters.h"
#include "ClearTileCommandParameters.h"
#include "InitKaraCommandParameters.h"
#include "InitWorldCommandParameters.h"

namespace kara {
class ConcreteWorld;
}
namespace mpw {
class Tile;
}
namespace mpw {
class TileContent;
}
namespace kara {
class ConcreteKara;
}
namespace kara {
class Leaf;
}
namespace kara {
class Mushroom;
}
namespace kara {
class Tree;
}
namespace mpw {
class Stage;
}
namespace kara {
class EditorKara;
}

namespace kara {

class EditorWorld: public virtual kara::ReadOnlyWorld {

public:

	virtual ~EditorWorld() = default;

	/// \brief returns a shared_ptr of type EditorWorld which shares ownership of *this
	std::shared_ptr<EditorWorld> shared_from_this() {
		return std::dynamic_pointer_cast < EditorWorld
				> (basetypes::Entity::shared_from_this());
	}
	/// \brief returns a shared_ptr of const type EditorWorld which shares ownership of *this
	std::shared_ptr<const EditorWorld> shared_from_this() const {
		return std::dynamic_pointer_cast<const EditorWorld>(
				basetypes::Entity::shared_from_this());
	}

	virtual void addLeafToTile(
			commands::AddLeafToTileCommandParameters &parameters) = 0;

	virtual void addMushroomToTile(
			commands::AddMushroomToTileCommandParameters &parameters) = 0;

	virtual void addTreeToTile(
			commands::AddTreeToTileCommandParameters &parameters) = 0;

	virtual void clearTile(
			commands::ClearTileCommandParameters &parameters) = 0;

	virtual void initKara(commands::InitKaraCommandParameters &parameters) = 0;

	virtual void initWorld(
			commands::InitWorldCommandParameters &parameters) = 0;

	virtual std::shared_ptr<kara::EditorKara> getEditorKara() noexcept = 0;
	virtual std::shared_ptr<const kara::EditorKara> getEditorKara() const noexcept = 0;

};

}

#endif //DE_UNISTUTTGART_KARA_EDITORWORLD_H

