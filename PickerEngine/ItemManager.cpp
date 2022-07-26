#include "ItemManager.h"

ItemManager::ItemManager(int itemAmount, GameManager* gameManager) {
	mItemAmount = itemAmount;
	mGameManager = gameManager;
}

ItemManager::~ItemManager() {

}

void ItemManager::Init(nlohmann::json data) {
	LoadItems(data);
	GenerateItems();
}

void ItemManager::Update() {
	for (int i = 0; i < mGeneratedItems.size(); i++) {
		mGeneratedItems[i].Update();
	}
}

void ItemManager::Render(sf::RenderWindow* window) {
	for (int i = 0; i < mGeneratedItems.size(); i++) {
		mGeneratedItems[i].Render(window);
	}
}

void ItemManager::LoadItems(nlohmann::json itemData) {
	std::vector<Item> items = {};
	std::vector<float> weights = {};
	for (int i = 0; i < itemData.size(); i++) {
		Item currentItem = Item(itemData[i]["id"], itemData[i]["name"], itemData[i]["weight"], itemData[i]["score"], this);
		items.push_back(currentItem);
		weights.push_back(currentItem.GetWeight());
	}
	mItemArray = items;
	mWeightArray = weights;
}

void ItemManager::GenerateItems() {
	std::mt19937 rnd(std::random_device{}());
	std::vector<Item> items = {};
	std::discrete_distribution<std::size_t> index{ mWeightArray.begin(), mWeightArray.end() };
	int currentX = 0;
	int currentY = 0;
	for (int i = 0; i < mItemAmount; i++) {
		if ((i != 0) && (i % ITEM_PER_ROW == 0)) {
			currentX = 0;
			currentY++; 
		}
		sf::Vector2f drawPos = INIT_ITEM_POS + sf::Vector2f((ITEM_SIZE.x + ITEM_DISTANCE.x) * currentX, (ITEM_SIZE.y + ITEM_DISTANCE.y) * currentY);
		Item rndItem = mItemArray[index(rnd)];
		Item addItem = Item(rndItem.GetID(), rndItem.GetName(), rndItem.GetWeight(), rndItem.GetScore(), this);
		addItem.SetPosition(drawPos);
		items.push_back(addItem);
		currentX++;
	}
	mGeneratedItems = items;
}

void ItemManager::ClearItems() {
	mGeneratedItems.clear();
}

Item ItemManager::PickItem(int index) {
	mGameManager->ModifyCount(-1);
	Item item = mGeneratedItems[index];
	item.Flip();
	return item;
}
