#pragma once

#ifndef _DATA_MANAGER_H
#define _DATA_MANAGER_H

#include <fstream>
#include "Constants.h"
#include "nlohmann/json.hpp"

class DataManager {
public:
	DataManager();
	~DataManager();
	nlohmann::json GetItemData() { return mItemData; }

private:
	nlohmann::json LoadItemData(std::string path);
	nlohmann::json mItemData;
};

#endif // !_DATA_MANAGER_H
