/*
 * This file is generated. Do not change it manually.
 */

#include "WriteCommand.h"

#include "FrameworkAssert.h"
#include "CommandConstraintException.h"
#include "ConcreteKara.h"
#include "GameLog.h"
#include <stdexcept>

using namespace framework;

namespace commands {

void WriteCommand::execute() {

	if (!internalMainUnit()) {
		throw std::runtime_error(
				"Transformation was not successfully executed: write");
	}

}
bool WriteCommand::internalMainUnit() {

	// new instance: entry:LogEntry
	std::shared_ptr < mpw::LogEntry > entry = std::make_shared<mpw::LogEntry>();

	// set value type field entry.message := 
	executeSetStringProperty(entry, mpw::LogEntry::cFeatureKeyMessage,
			entry->getMessage(), message);

	// create reference: CREATE entry:LogEntry -> actor -> self:GameKara
	executeSetProperty(entry, mpw::LogEntry::cFeatureKeyActor,
			entry->getActor(), self);

	// create reference: CREATE gameLog:GameLog -> logEntries -> entry:LogEntry
	executeAddReference(gameLog, mpw::GameLog::cFeatureKeyLogEntries, entry);

	return true;

}

}

