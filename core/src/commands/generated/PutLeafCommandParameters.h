/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_COMMANDSPUTLEAFPARAMETERS_H
#define DE_UNISTUTTGART_KARA_COMMANDSPUTLEAFPARAMETERS_H

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

struct PutLeafCommandParameters final {
	std::shared_ptr<kara::ConcreteKara> self;
	commands::CommandStack &commandStack;
	std::shared_ptr<mpw::GameLog> gameLog;

	PutLeafCommandParameters(std::shared_ptr<kara::ConcreteKara> self,
			commands::CommandStack &commandStack,
			std::shared_ptr<mpw::GameLog> gameLog) : self(self), commandStack(
			commandStack), gameLog(gameLog) {
	}
};

}

#endif //DE_UNISTUTTGART_KARA_COMMANDSPUTLEAFPARAMETERS_H

