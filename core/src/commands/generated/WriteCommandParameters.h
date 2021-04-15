/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_COMMANDSWRITEPARAMETERS_H
#define DE_UNISTUTTGART_KARA_COMMANDSWRITEPARAMETERS_H

#include <memory>

namespace kara {
class ConcreteKara;
}
namespace commands {
class CommandStack;
}
namespace mpw {
class GameLog;
}

namespace commands {

struct WriteCommandParameters final {
	std::shared_ptr<kara::ConcreteKara> self;
	commands::CommandStack &commandStack;
	std::shared_ptr<mpw::GameLog> gameLog;

	std::string message;

	WriteCommandParameters(std::shared_ptr<kara::ConcreteKara> self,
			commands::CommandStack &commandStack,
			std::shared_ptr<mpw::GameLog> gameLog, std::string message) : self(
			self), commandStack(commandStack), gameLog(gameLog), message(
			message) {
	}
};

}

#endif //DE_UNISTUTTGART_KARA_COMMANDSWRITEPARAMETERS_H

