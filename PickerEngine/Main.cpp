#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Item.h"
#include "DataManager.h"
#include "GameManager.h"
#include "ItemManager.h"
#include "UIManager.h"

// Forward declaration of loop methods.
void Init();
void Update();
void Render();
void HandleInput(sf::Event* event);

sf::RenderWindow gWindow(VIDEO_MODE, "Picker Engine", sf::Style::Titlebar | sf::Style::Close);

// Declaring global variables.
DataManager* gDataManager = nullptr;
GameManager* gGameManager = nullptr;
ItemManager* gItemManager = nullptr;
UIManager* gUIManager = nullptr;
sf::Event* event = new sf::Event;

// Initialization of manager objects.
void Init() {
    srand((unsigned) (time(0)));
    gDataManager = new DataManager();

    nlohmann::json settings = gDataManager->GetSettingsData();

    gGameManager = new GameManager(settings["pickCount"]);
    gItemManager = new ItemManager(settings["itemCount"], gGameManager, gDataManager->GetSettingsData());
    gGameManager->mItemManager = gItemManager;
    gUIManager = new UIManager(gGameManager, gItemManager, gDataManager);

    gItemManager->Init(gDataManager->GetItemData());
    gUIManager->FitWindow(&gWindow);
}

// Handles input-related events.
void HandleInput(sf::Event* event) {
    while (gWindow.pollEvent(*event)) {
        switch (event->type) {
        case sf::Event::Closed:
            gWindow.close();
            break;
        case sf::Event::KeyPressed:
            if (!gWindow.hasFocus()) break;
            switch (event->key.code) {
                case sf::Keyboard::H:
                    gGameManager->ResetSession();
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
        case sf::Event::Resized:
            sf::FloatRect visibleArea(0, 0, event->size.width, event->size.height);
            gWindow.setView(sf::View(visibleArea));
            break;
        }
    }
}

// Execute the main game loop.
void Update() {
    gGameManager->Update();
    gItemManager->Update(&gWindow, event, gGameManager->GetCurrentState());
    HandleInput(event);
    gUIManager->Update();
}

// Render graphical elements.
void Render() {
    gWindow.clear(BG_COLOR);
    gItemManager->Render(&gWindow);
    gUIManager->Render(&gWindow);
    gWindow.display();
}

int main(int argc, char* args[]) {
    Init();
    // Not opting for a proper loop here since this is a prototype.
    while (gWindow.isOpen()) {
        Update();
        Render();
    }
	return 0;
}