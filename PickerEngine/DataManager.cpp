#include "DataManager.h"

/// <summary>
/// Constructs the data manager and loads the JSON file from a pre-determined path.
/// </summary>
DataManager::DataManager() {
	nlohmann::json data = LoadData(DATA_PATH);
	// Fills a vector with items parsed from the JSON file.
	for (auto& i: data["items"].items()) {
		nlohmann::json item = i.value();
		mItemData.push_back(item);
	}

	// Perform a null check on JSON elements, use default values in the header if not found.
	nlohmann::json settings = data["settings"];
	mSettingsData["pickCount"] = settings.contains("pickCount") ? (int) settings["pickCount"] : PICK_COUNT;
	mSettingsData["itemCount"] = settings.contains("itemCount") ? (int) settings["itemCount"] : ITEM_COUNT;
	mSettingsData["itemPerRow"] = settings.contains("itemPerRow") ? (int) settings["itemPerRow"] : ITEM_PER_ROW;
}

DataManager::~DataManager() {
}

/// <summary>
/// Read a JSON file based on a given path.
/// </summary>
/// <param name="path">Path to file.</param>
/// <returns>Parsed JSON data.</returns>
nlohmann::json DataManager::LoadData(std::string path) {
	std::ifstream file(path);
	return nlohmann::json::parse(file);
}