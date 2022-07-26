#pragma once

#ifndef _CONSTANTS_H
#define _CONSTANTS_H

#define VIDEO_MODE sf::VideoMode(800, 600)

#define ITEM_COUNT 8
#define PICK_COUNT 2

#define ITEM_PER_ROW 4
#define ITEM_DISTANCE sf::Vector2f(20.0f, 20.0f)
#define ITEM_SIZE sf::Vector2f(120.0f, 120.0f)
#define INIT_ITEM_POS sf::Vector2f(20.0f, 20.0f)

#define BG_COLOR sf::Color(40, 40, 40, 255)
#define ITEM_COLOR sf::Color(245, 195, 125, 255)
#define STROKE_COLOR sf::Color(195, 155, 95, 255)
#define OUTLINE_THICKNESS -6.0f

#define FONT_COLOR sf::Color(240,240,240,255)
#define FONT_SIZE 20

#define DATA_PATH "picker-test-data.json"
#define FONT_PATH "wolf-sans.ttf"

#endif // !_CONSTANTS_H
