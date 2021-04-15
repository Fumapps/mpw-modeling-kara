/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_COMMANDSINITKARAPARAMETERS_H
#define DE_UNISTUTTGART_KARA_COMMANDSINITKARAPARAMETERS_H

#include <memory>

#include "Location.h"
#include "Direction.h"

namespace kara {
class ConcreteWorld;
}
namespace commands {
class CommandStack;
}

namespace commands {

struct InitKaraCommandParameters final {
	std::shared_ptr<kara::ConcreteWorld> self;
	commands::CommandStack &commandStack;

	mpw::Location location;

	mpw::Direction direction;

	InitKaraCommandParameters(std::shared_ptr<kara::ConcreteWorld> self,
			commands::CommandStack &commandStack, mpw::Location location,
			mpw::Direction direction) : self(self), commandStack(commandStack), location(
			location), direction(direction) {
	}
};

}

#endif //DE_UNISTUTTGART_KARA_COMMANDSINITKARAPARAMETERS_H

