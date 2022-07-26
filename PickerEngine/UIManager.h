#pragma once

#ifndef _UI_MANAGER_H
#define _UI_MANAGER_H

#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "GameManager.h"

class GameManager;

class UIManager {
public:
	UIManager(GameManager* gameManager);
	~UIManager();

	void Init();
	void Update();
	void Render(sf::RenderWindow* window);

	void InitText(sf::Text* text, sf::Vector2f position);
	void UpdateTexts();

private:
	sf::Text* mPickText;
	sf::Text* mScoreText;
	sf::Font* mFont;

	GameManager* mGameManager;
};

#endif // !_UI_MANAGER_H
