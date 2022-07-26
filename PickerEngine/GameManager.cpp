#include "GameManager.h"

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

int GameManager::ModifyCount(int count) {
	mPickCount += count;
	return mPickCount;
}

int GameManager::ModifyScore(int score) {
	mCurrentScore += score;
	return mCurrentScore;
}

void GameManager::CheckState() {
	mGameState = mPickCount == -1 ? FINISHED : IN_PROGRESS;
	if (mGameState == FINISHED) ResetSession();
}

void GameManager::ResetSession() {
	mPickCount = mInitPickCount;
	mCurrentScore = 0;
	mGameState = IN_PROGRESS;
}