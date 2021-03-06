//
//  ViewLevel.cpp
//  ZombyMaze2
//
//  Created by Raphael Thibierge on 25/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "ViewLevel.h"
using namespace std;
using namespace sf;

ViewLevel::ViewLevel() : View(), _levelMenu(Menu(800, 500))
{
    _levelMenu.createMosaic(LEVEL_MAX, 4);
    _levelMenu.setPosition(200, 200);
    _levelMenu.update(0, 0);

    _buttonQuit = false;
}


const int ViewLevel::treatEventSFML()
{
    int returnValue = 1;
    Event event;
    while (_window->pollEvent(event)) {
        if (event.type == Event::MouseMoved)
        {
            _levelMenu.update(event.mouseMove.x, event.mouseMove.y);
            _buttonQuit = mouseOnButton(event.mouseMove.x, event.mouseMove.y, 440, 600, BUTTON_WIDTH, BUTTON_HEIGHT);
        }
        
        if (event.type == Event::MouseButtonPressed)
        {
            
            Button * button = _levelMenu.getButtonClicked();
            
            if (button != nullptr)
            {
                string level = button->getText();
                unsigned int number = atoi(&level[0]);
                if (number <= LEVEL_MAX && _modele->newGame(number))
                    returnValue = -2;
            }
            
            if (_buttonQuit)
            {
                return 0;
            }
        }
        if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
        {
            returnValue = 0;
        }
    }
    return returnValue;
}

void ViewLevel::showViewSFML()
{
    displayTitle("Choose your Level", 340, 100);
    _window->draw(_levelMenu.getSprite());
    displayStandartButton("quit", 440, 600, _buttonQuit);
}

const bool ViewLevel::initSFML()
{
    return true;
}

const bool ViewLevel::initButtons()
{
    string name = "button_";
    if (!initSprite(name+"quit", BUTTON_QUIT, 2, BUTTON_WIDTH, BUTTON_HEIGHT))
        return false;
    return true;
}