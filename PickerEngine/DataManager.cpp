#include "DataManager.h"

DataManager::DataManager() {
	mItemData = LoadItemData(DATA_PATH);
}

DataManager::~DataManager() {
	mItemData = nullptr;
}

nlohmann::json DataManager::LoadItemData(std::string path) {
	std::ifstream file(path);
	return nlohmann::json::parse(file);
}