#pragma once

#ifndef _UI_MANAGER_H
#define _UI_MANAGER_H

#include <SFML/Graphics.hpp>
#include <math.h>
#include "Constants.h"
#include "GameManager.h"
#include "ItemManager.h"
#include "DataManager.h"

class GameManager;
class ItemManager;
class DataManager;

class UIManager {
public:
	UIManager(GameManager* gameManager, ItemManager* itemManager, DataManager* dataManager);
	~UIManager();

	void Init();
	void Update();
	void Render(sf::RenderWindow* window);

	void InitText(sf::Text* text, sf::Vector2f position);
	void UpdateTexts();
	void FitWindow(sf::RenderWindow* window);

private:
	sf::Text* mPickText;
	sf::Text* mScoreText;
	sf::Text* mGuideText;
	sf::Font* mFont;

	sf::Vector2f itemDisplaySize;

	GameManager* mGameManager;
	ItemManager* mItemManager;
	DataManager* mDataManager;
};

#endif // !_UI_MANAGER_H
