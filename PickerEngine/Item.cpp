#include "Item.h"

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
	mText->setCharacterSize(24);
	UpdateText("?");
}

Item::~Item() {
}

void Item::Update() {

}

void Item::UpdateText(std::string str) {
	mText->setString(str);
	//sf::FloatRect bounds = mText->getLocalBounds();
	//mText->setOrigin(sf::Vector2f(bounds.height, bounds.width) * 0.5f);
	mText->setPosition(mShape->getPosition() + ITEM_SIZE * 0.5f);	
}

void Item::Render(sf::RenderWindow* window) {
	window->draw(*mShape);
	window->draw(*mText);
}