#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Item.h"
#include "DataManager.h"
#include "GameManager.h"
#include "ItemManager.h"
#include "UIManager.h"

void Init();
void Update();
void Render();
void HandleInput();

sf::RenderWindow gWindow(VIDEO_MODE, "Picker Engine");

DataManager* gDataManager = nullptr;
GameManager* gGameManager = nullptr;
ItemManager* gItemManager = nullptr;
UIManager* gUIManager = nullptr;

void Init() {
    srand((unsigned) (time(0)));

    gDataManager = new DataManager();
    gGameManager = new GameManager(PICK_COUNT);
    gItemManager = new ItemManager(ITEM_COUNT, gGameManager);
    gUIManager = new UIManager(gGameManager);

    gItemManager->Init(gDataManager->GetItemData());
}

void HandleInput() {
    sf::Event event;
    while (gWindow.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            gWindow.close();
            break;
        case sf::Event::KeyPressed:
            if (!gWindow.hasFocus()) break;
            switch (event.key.code) {
            case sf::Keyboard::H:
                gGameManager->ModifyScore(200);
                gGameManager->ModifyCount(-1);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

void Update() {
    gGameManager->Update();
    gItemManager->Update();
    HandleInput();
    gUIManager->Update();
}

void Render() {
    gWindow.clear(BG_COLOR);
    gItemManager->Render(&gWindow);
    gUIManager->Render(&gWindow);
    gWindow.display();
}

int main(int argc, char* args[]) {
    Init();
    while (gWindow.isOpen()) {
        Update();
        Render();
    }
	return 0;
}