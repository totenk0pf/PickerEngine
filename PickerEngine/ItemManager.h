#pragma once

#ifndef _ITEM_MANAGER_H
#define _ITEM_MANAGER_H

#include <SFML/Graphics.hpp>
#include "nlohmann/json.hpp"
#include "Item.h"
#include <vector>
#include "GameManager.h"
#include "Commons.h"
#include <random>

class GameManager;
class Item;

class ItemManager {
public:
	ItemManager(int itemAmount, GameManager* gameManager, std::map<std::string, int> settingsData);
	~ItemManager();

	void Init(nlohmann::json data);
	void Update(sf::RenderWindow* window, sf::Event* event, GameState state);
	void Render(sf::RenderWindow* window);

	void LoadItems(std::vector<nlohmann::json> itemData);
	void GenerateItems();
	void ResetItems();

	Item* PickItem(Item* item);

private:
	std::vector<Item> mItemArray;
	std::vector<float> mWeightArray;
	std::vector<Item> mGeneratedItems;
	int mItemAmount;
	GameManager* mGameManager;
	std::map<std::string, int> mSettings;
};

#endif // !_ITEM_MANAGER_H
