#include "Item.h"

/// <summary>
/// Construct an item.
/// </summary>
/// <param name="id">Item ID.</param>
/// <param name="name">Name of the item.</param>
/// <param name="weight">Distribution weight of the item.</param>
/// <param name="score">Payout value of the item.</param>
/// <param name="managerRef">Reference to the item manager.</param>
Item::Item(std::string id, std::string name, float weight, int score, ItemManager* managerRef = nullptr) {
	mID = id;
	mName = name;
	mWeight = weight;
	mFlipped = false;
	mScore = score;
	mItemManager = managerRef;

	mShape = new sf::RectangleShape(ITEM_SIZE);
	mShape->setFillColor(ITEM_COLOR);
	mShape->setOutlineThickness(OUTLINE_THICKNESS);
	mShape->setOutlineColor(STROKE_COLOR);

	mFont = new sf::Font;
	if (!mFont->loadFromFile(FONT_PATH)) return;
	mText = new sf::Text;
	mText->setFont(*mFont);
	mText->setCharacterSize(ITEM_DEFAULT_FONT_SIZE);
	mText->setFillColor(ITEM_TEXT_COLOR);
}

Item::~Item() {
}

void Item::Update(sf::RenderWindow* window, sf::Event* event, GameState state) {
	if (mFlipped || state == FINISHED) return;
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
	sf::Vector2f shapePos = mShape->getPosition();
	// Check if the mouse is currently within bounds of the item.
	isMouseOver =	mousePosition.x >= shapePos.x && 
					mousePosition.x <= shapePos.x + ITEM_SIZE.x &&
					mousePosition.y >= shapePos.y &&
					mousePosition.y <= shapePos.y + ITEM_SIZE.y;
	if (!isMouseOver) return;
	switch (event->type) {
		case sf::Event::MouseButtonPressed:
			switch (event->mouseButton.button) {
				case sf::Mouse::Left:
					// Pick the item if the player left clicks on it.
					mItemManager->PickItem(this);
					break;
			}
			break;
		default:
			break;
	}
}

/// <summary>
/// Update the text content within the item.
/// </summary>
/// <param name="str">String to be displayed.</param>
/// <param name="newSize">Optional new size for the text.</param>
void Item::UpdateText(std::string str, int newSize) {
	mText->setString(str);
	mText->setCharacterSize(newSize);
	sf::FloatRect bounds = mText->getLocalBounds();
	mText->setOrigin(sf::Vector2f(bounds.width, bounds.height) * 0.5f);
	mText->setPosition(GetPosition() + ITEM_SIZE * 0.5f);
}

void Item::Render(sf::RenderWindow* window) {
	window->draw(*mShape);
	window->draw(*mText);
}

/// <summary>
/// Flip the item.
/// </summary>
void Item::Flip() {
	mFlipped = true;
	UpdateText(mName + "\nScore: " + std::to_string(mScore), ITEM_CLICKED_FONT_SIZE);
}