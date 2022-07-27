#pragma once

#ifndef _ITEM_H
#define _ITEM_H

#include <iostream>
#include "Constants.h"
#include "Commons.h"
#include "ItemManager.h"
#include <SFML/Graphics.hpp>

class ItemManager;
class sf::RectangleShape;

class Item {
public:
	Item(std::string id, std::string name, float weight, int score, ItemManager* managerRef);
	~Item();

	void Update(sf::RenderWindow* window, sf::Event* event, GameState state);
	void Render(sf::RenderWindow* window);
	
	void Flip();
	void SetPosition(sf::Vector2f pos) { mShape->setPosition(pos); }
	sf::Vector2f GetPosition() { return mShape->getPosition(); }
	void UpdateText(std::string str, int newSize = ITEM_DEFAULT_FONT_SIZE);


	std::string GetID() { return mID; }
	std::string GetName() { return mName; }
	float GetWeight() { return mWeight; }
	int GetScore() { return mScore; }
	bool GetFlip() { return mFlipped; }

protected:
	std::string mID;
	std::string mName;
	float mWeight;
	int mScore;
	bool mFlipped;
	bool isMouseOver;

	sf::RectangleShape* mShape;
	sf::Text* mText;
	sf::Font* mFont;

private:
	ItemManager* mItemManager;
};

#endif