/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_COMMANDSADDLEAFTOTILEPARAMETERS_H
#define DE_UNISTUTTGART_KARA_COMMANDSADDLEAFTOTILEPARAMETERS_H

#include <memory>

#include "Location.h"

namespace kara {
class ConcreteWorld;
}
namespace commands {
class CommandStack;
}

namespace commands {

struct AddLeafToTileCommandParameters final {
	std::shared_ptr<kara::ConcreteWorld> self;
	commands::CommandStack &commandStack;

	mpw::Location location;

	AddLeafToTileCommandParameters(std::shared_ptr<kara::ConcreteWorld> self,
			commands::CommandStack &commandStack, mpw::Location location) : self(
			self), commandStack(commandStack), location(location) {
	}
};

}

#endif //DE_UNISTUTTGART_KARA_COMMANDSADDLEAFTOTILEPARAMETERS_H

