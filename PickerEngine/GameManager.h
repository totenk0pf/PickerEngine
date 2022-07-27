#pragma once

#ifndef _GAME_MANAGER_H
#define _GAME_MANAGER_H

#include "Commons.h"
#include "ItemManager.h"

class ItemManager;

class GameManager {
public:
	GameManager(int pickCount);
	~GameManager();

	void Update();

	void ResetSession();
	int ModifyCount(int count);
	int ModifyScore(int score);
	void CheckState();

	int GetPickCount() { return mPickCount; }
	int GetCurrentScore() { return mCurrentScore; }
	GameState GetCurrentState() { return mGameState; }

	ItemManager* mItemManager;

private:
	int mInitPickCount;
	int mPickCount;
	int mCurrentScore;
	GameState mGameState;
};

#endif