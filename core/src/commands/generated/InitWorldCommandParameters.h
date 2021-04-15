/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_COMMANDSINITWORLDPARAMETERS_H
#define DE_UNISTUTTGART_KARA_COMMANDSINITWORLDPARAMETERS_H

#include <memory>

namespace kara {
class ConcreteWorld;
}
namespace commands {
class CommandStack;
}

namespace commands {

struct InitWorldCommandParameters final {
	std::shared_ptr<kara::ConcreteWorld> self;
	commands::CommandStack &commandStack;

	int columns;

	int rows;

	InitWorldCommandParameters(std::shared_ptr<kara::ConcreteWorld> self,
			commands::CommandStack &commandStack, int columns, int rows) : self(
			self), commandStack(commandStack), columns(columns), rows(rows) {
	}
};

}

#endif //DE_UNISTUTTGART_KARA_COMMANDSINITWORLDPARAMETERS_H

