/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_COMMANDSADDMUSHROOMTOTILEPARAMETERS_H
#define DE_UNISTUTTGART_KARA_COMMANDSADDMUSHROOMTOTILEPARAMETERS_H

#include <memory>

#include "Location.h"

namespace kara {
class ConcreteWorld;
}
namespace commands {
class CommandStack;
}

namespace commands {

struct AddMushroomToTileCommandParameters final {
	std::shared_ptr<kara::ConcreteWorld> self;
	commands::CommandStack &commandStack;

	mpw::Location location;

	AddMushroomToTileCommandParameters(
			std::shared_ptr<kara::ConcreteWorld> self,
			commands::CommandStack &commandStack, mpw::Location location) : self(
			self), commandStack(commandStack), location(location) {
	}
};

}

#endif //DE_UNISTUTTGART_KARA_COMMANDSADDMUSHROOMTOTILEPARAMETERS_H

