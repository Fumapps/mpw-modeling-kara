#ifndef DE_UNISTUTTGART_KARA_GAMEPERFORMANCEIMPL_H
#define DE_UNISTUTTGART_KARA_GAMEPERFORMANCEIMPL_H

#include "GamePerformance.h"
#include "Semaphore.h"

namespace mpw {

class GamePerformanceImpl: public GamePerformance {
private:
	using inherited = GamePerformance;

public:

	GamePerformanceImpl(framework::Semaphore semaphore);

	void startGame() override;

	void startGamePaused() override;

	void pauseGame() override;

	void resumeGame() override;

	void stopGame() override;

	void reset() override;

	void hardReset() override;

	void abortOrStopGame() override;

	void holdControlFlowIfPaused() override;

	void delayControlFlow() override;

};

}

#endif //DE_UNISTUTTGART_KARA_GAMEPERFORMANCEIMPL_H
