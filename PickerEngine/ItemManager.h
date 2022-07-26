#pragma once

#ifndef _ITEM_MANAGER_H
#define _ITEM_MANAGER_H

#include <SFML/Graphics.hpp>
#include "nlohmann/json.hpp"
#include "Item.h"
#include <vector>
#include "GameManager.h"
#include <random>

class GameManager;
class Item;

class ItemManager {
public:
	ItemManager(int itemAmount, GameManager* gameManager);
	~ItemManager();

	void Init(nlohmann::json data);
	void Update();
	void Render(sf::RenderWindow* window);

	void LoadItems(nlohmann::json itemData);
	void GenerateItems();
	void ClearItems();

	Item PickItem(int index);

private:
	std::vector<Item> mItemArray;
	std::vector<float> mWeightArray;
	std::vector<Item> mGeneratedItems;
	int mItemAmount;
	GameManager* mGameManager;
};

#endif // !_ITEM_MANAGER_H
