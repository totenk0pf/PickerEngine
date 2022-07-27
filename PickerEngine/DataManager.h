#pragma once

#ifndef _DATA_MANAGER_H
#define _DATA_MANAGER_H

#include <fstream>
#include "Constants.h"
#include "nlohmann/json.hpp"
#include "Item.h"
#include <map>

class Item;

class DataManager {
public:
	DataManager();
	~DataManager();
	std::vector<nlohmann::json> GetItemData() { return mItemData; }
	std::map<std::string, int> GetSettingsData() { return mSettingsData; }

private:
	nlohmann::json LoadData(std::string path);
	std::vector<nlohmann::json> mItemData;
	std::map<std::string, int> mSettingsData; // Using a map so we don't end up with duplicates.
};

#endif // !_DATA_MANAGER_H
