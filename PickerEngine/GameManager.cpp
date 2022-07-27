#include "GameManager.h"

/// <summary>
/// Construct the manager responsible for handling statistics and game states.
/// </summary>
/// <param name="pickCount"></param>
GameManager::GameManager(int pickCount) {
	mGameState = IN_PROGRESS;
	mInitPickCount = pickCount;
	mPickCount = pickCount;
	mCurrentScore = 0;
}

GameManager::~GameManager() {}

void GameManager::Update() {
	CheckState();
}

/// <summary>
/// Modify the current pick count.
/// </summary>
/// <param name="count"></param>
/// <returns>New pick count.</returns>
int GameManager::ModifyCount(int count) {
	mPickCount += count;
	return mPickCount;
}

/// <summary>
/// 
/// </summary>
/// <param name="score"></param>
/// <returns></returns>
int GameManager::ModifyScore(int score) {
	mCurrentScore += score;
	return mCurrentScore;
}

/// <summary>
/// Update the game state based on the remaining pick count.
/// </summary>
void GameManager::CheckState() {
	mGameState = mPickCount == 0 ? FINISHED : IN_PROGRESS;
}

/// <summary>
/// Reset the play session and generate a new board.
/// </summary>
void GameManager::ResetSession() {
	mPickCount = mInitPickCount;
	mCurrentScore = 0;
	mGameState = IN_PROGRESS;
	if (mItemManager != nullptr) {
		mItemManager->ResetItems();
	}
}