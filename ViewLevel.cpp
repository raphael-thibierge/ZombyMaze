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

ViewLevel::ViewLevel() : View()
{
    _buttonLevel1 = false;
    _buttonLevel2 = false;
    _buttonQuit = false;
}


int ViewLevel::treatEventSFML()
{
    int returnValue = 1;
    Event event;
    while (_window->pollEvent(event)) {
        if (event.type == Event::MouseMoved)
        {
            updateButtons(event.mouseMove.x, event.mouseMove.y);
        }
        
        if (event.type == Event::MouseButtonPressed)
        {
            if (_buttonLevel1)
            {
                returnValue = -2;
                // at this point play/stop states is always stop !
                _modele->newGame(1);
            }
            
            else if (_buttonLevel2)
            {
                returnValue = -2;
                // at this point play/stop states is always stop !
                _modele->newGame(2);
            }
            
            else if (_buttonQuit)
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
    displayButtons();
}

bool ViewLevel::initSFML()
{
    return true;
}

bool ViewLevel::initButtons()
{
    string name = "button_";
    if (!initSprite(name+"level1", BUTTON_PLAY, 2, BUTTON_WIDTH, BUTTON_HEIGHT))
        return false;
    if (!initSprite(name+"level2", BUTTON_PLAY, 2, BUTTON_WIDTH, BUTTON_HEIGHT))
        return false;
    if (!initSprite(name+"quit", BUTTON_QUIT, 2, BUTTON_WIDTH, BUTTON_HEIGHT))
        return false;
    return true;
}

void ViewLevel::updateButtons(const unsigned int mouseX, const unsigned int mouseY)
{
    _buttonLevel1 = mouseOnButton(mouseX, mouseY, MENU_COLUMN[0], MENU_LINE[0], BUTTON_WIDTH, BUTTON_HEIGHT);
    _buttonLevel2 = mouseOnButton(mouseX, mouseY, MENU_COLUMN[0], MENU_LINE[1], BUTTON_WIDTH, BUTTON_HEIGHT);
    _buttonQuit = mouseOnButton(mouseX, mouseY, MENU_COLUMN[0], MENU_LINE[2], BUTTON_WIDTH, BUTTON_HEIGHT);
    

}

void ViewLevel::displayButtons()
{
    displayStandartButton("level1", MENU_COLUMN[0], MENU_LINE[0], _buttonLevel1);
    displayStandartButton("level2", MENU_COLUMN[0], MENU_LINE[1], _buttonLevel2 );
    displayStandartButton("quit", MENU_COLUMN[0], MENU_LINE[2], _buttonQuit);
}