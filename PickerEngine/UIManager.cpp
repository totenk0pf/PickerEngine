#include "UIManager.h"

/// <summary>
/// Construct the manager responsible for handling UI elements.
/// </summary>
/// <param name="gameManager">Reference to the game manager.</param>
/// <param name="itemManager">Reference to the item manager.</param>
/// <param name="dataManager">Reference to the data manager.</param>
UIManager::UIManager(GameManager* gameManager, ItemManager* itemManager, DataManager* dataManager) {
	mGameManager = gameManager;
	mItemManager = itemManager;
	mDataManager = dataManager;

	mFont = new sf::Font;
	if (!mFont->loadFromFile(FONT_PATH)) return;

	std::map<std::string, int> settings = mDataManager->GetSettingsData();
	
	int amountOfRows = ceil(settings["itemCount"] / (float) settings["itemPerRow"]);

	// Calculates the total area of all the generated items.
	itemDisplaySize = sf::Vector2f((ITEM_SIZE.x + ITEM_DISTANCE.x) * settings["itemPerRow"] - ITEM_DISTANCE.x,
									INIT_ITEM_POS.y + (ITEM_SIZE.y + ITEM_DISTANCE.y) * amountOfRows - ITEM_DISTANCE.y);

	mPickText = new sf::Text();
	InitText(mPickText, sf::Vector2f(20.0f, itemDisplaySize.y + ITEM_DISTANCE.y));

	mScoreText = new sf::Text();
	InitText(mScoreText, sf::Vector2f(20.0f, itemDisplaySize.y + ITEM_DISTANCE.y + 30.0f));

	mGuideText = new sf::Text();
	InitText(mGuideText, sf::Vector2f(20.0f, itemDisplaySize.y + ITEM_DISTANCE.y + 60.0f));
	mGuideText->setString("Press H to reset the game.");

	UpdateTexts();
}

UIManager::~UIManager() {}

/// <summary>
/// Initialize a text object.
/// </summary>
/// <param name="text"></param>
/// <param name="position"></param>
void UIManager::InitText(sf::Text* text, sf::Vector2f position) {
	text->setFont(*mFont);
	text->setCharacterSize(FONT_SIZE);
	text->setFillColor(FONT_COLOR);
	text->setPosition(position);
}

void UIManager::Update() {
	UpdateTexts(); // Updates all text objects.
}

void UIManager::UpdateTexts() {
	mPickText->setString("Picks left: " + std::to_string(mGameManager->GetPickCount()));
	mScoreText->setString("Score: " + std::to_string(mGameManager->GetCurrentScore()));
}

/// <summary>
/// Resize the render window to fit UI elements.
/// </summary>
/// <param name="window"></param>
void UIManager::FitWindow(sf::RenderWindow* window) {
	window->setSize(sf::Vector2u(itemDisplaySize.x + INIT_ITEM_POS.x * 2, 
								INIT_ITEM_POS.y * 2 + itemDisplaySize.y + 90.0f));
}

void UIManager::Render(sf::RenderWindow* window) {
	window->draw(*mPickText);
	window->draw(*mScoreText);
	window->draw(*mGuideText);
}