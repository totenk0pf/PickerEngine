#include "ItemManager.h"

/// <summary>
/// Construct the manager object handling item spawning and picking.
/// </summary>
/// <param name="itemAmount">Amount of items to be spawned.</param>
/// <param name="gameManager">Reference to the game manager.</param>
/// <param name="settingsData">Distribution settings for the items.</param>
ItemManager::ItemManager(int itemAmount, GameManager* gameManager, std::map<std::string, int> settingsData) {
	mItemAmount = itemAmount;
	mGameManager = gameManager;
	mSettings = settingsData;
}

ItemManager::~ItemManager() {

}

/// <summary>
/// Load and generate items based on parsed JSON data.
/// </summary>
/// <param name="data"></param>
void ItemManager::Init(nlohmann::json data) {
	LoadItems(data);
	GenerateItems();
}

void ItemManager::Update(sf::RenderWindow* window, sf::Event* event, GameState state) {
	for (int i = 0; i < mGeneratedItems.size(); i++) {
		mGeneratedItems[i].Update(window, event, state);
	}
}

void ItemManager::Render(sf::RenderWindow* window) {
	for (int i = 0; i < mGeneratedItems.size(); i++) {
		mGeneratedItems[i].Render(window);
	}
}

/// <summary>
/// Load items based on the JSON item data.
/// </summary>
/// <param name="itemData">Item data read by the data manager.</param>
void ItemManager::LoadItems(std::vector<nlohmann::json> itemData) {
	std::vector<Item> items = {};
	std::vector<float> weights = {};
	for (int i = 0; i < itemData.size(); i++) {
		auto entry = itemData[i];
		Item currentItem = Item(entry["id"], entry["name"], entry["weight"], entry["score"], this);
		items.push_back(currentItem);
		weights.push_back(currentItem.GetWeight());
	}
	mItemArray = items;
	mWeightArray = weights;
}

/// <summary>
/// Generate items onto the board with each item being distributed by weight.
/// </summary>
void ItemManager::GenerateItems() {
	std::mt19937 rnd(std::random_device{}());
	std::vector<Item> items = {};
	std::discrete_distribution<std::size_t> index{ mWeightArray.begin(), mWeightArray.end() };
	int currentX = 0;
	int currentY = 0;
	for (int i = 0; i < mItemAmount; i++) {
		if ((i != 0) && (i % mSettings["itemPerRow"] == 0)) {
			currentX = 0;
			currentY++; 
		}
		sf::Vector2f drawPos = INIT_ITEM_POS + sf::Vector2f((ITEM_SIZE.x + ITEM_DISTANCE.x) * currentX, (ITEM_SIZE.y + ITEM_DISTANCE.y) * currentY);
		Item rndItem = mItemArray[index(rnd)];
		Item addItem = Item(rndItem.GetID(), rndItem.GetName(), rndItem.GetWeight(), rndItem.GetScore(), this);
		addItem.SetPosition(drawPos);
		addItem.UpdateText("?");
		items.push_back(addItem);
		currentX++;
	}
	mGeneratedItems = items;
}

/// <summary>
/// Reset the generated board.
/// </summary>
void ItemManager::ResetItems() {
	mGeneratedItems.clear();
	GenerateItems();
}

/// <summary>
/// Pick an item by reference.
/// </summary>
/// <param name="item">Item to be picked.</param>
/// <returns>Picked item.</returns>
Item* ItemManager::PickItem(Item* item) {
	item->Flip();
	mGameManager->ModifyCount(-1);
	mGameManager->ModifyScore(item->GetScore());
	return item;
}
