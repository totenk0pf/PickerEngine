#include "UIManager.h"

UIManager::UIManager(GameManager* gameManager) {
	//mPickText.set
	mFont = new sf::Font;
	if (!mFont->loadFromFile(FONT_PATH)) return;
	mPickText = new sf::Text();
	InitText(mPickText, sf::Vector2f(20.0f, 310.0f));

	mScoreText = new sf::Text();
	InitText(mScoreText, sf::Vector2f(20.0f, 350.0f));

	mGameManager = gameManager;
	UpdateTexts();
}

UIManager::~UIManager() {}

void UIManager::InitText(sf::Text* text, sf::Vector2f position) {
	text->setFont(*mFont);
	text->setCharacterSize(FONT_SIZE);
	text->setFillColor(FONT_COLOR);
	text->setPosition(position);
}

void UIManager::Update() {
	UpdateTexts();
}

void UIManager::UpdateTexts() {
	mPickText->setString("Picks left: " + std::to_string(mGameManager->GetPickCount()));
	mScoreText->setString("Score: " + std::to_string(mGameManager->GetCurrentScore()));
}

void UIManager::Render(sf::RenderWindow* window) {
	window->draw(*mPickText);
	window->draw(*mScoreText);
}