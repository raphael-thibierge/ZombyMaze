//
//  ViewMainMenu.cpp
//  ZombyMaze2
//
//  Created by Raphael Thibierge on 23/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "ViewMainMenu.h"

using namespace std;
using namespace sf;

ViewMainMenu::ViewMainMenu() : View()
{
    _buttonPlay = false;
    _buttonQuit = false;
    _buttonTheme = false;
    _buttonLevel = false;

}


int ViewMainMenu::treatEventSFML()
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
            if (_buttonPlay)
            {
                returnValue = -2;
                // at this point play/stop states is always stop !
                _modele->newGame();
            }
            
            if (_buttonQuit)
            {
                returnValue = 0;
            }
            
            if (_buttonLevel)
            {
                returnValue = -4;
            }
            if (_buttonTheme)
            {
                returnValue = -5;
            }
            
        }
    }
    return returnValue;
}

void ViewMainMenu::showViewSFML()
{
    _window->draw(_spritesList["background"]);
    
    displayStandartButton("play", MENU_COLUMN[0], MENU_LINE[0], _buttonPlay);
    displayStandartButton("level", MENU_COLUMN[0], MENU_LINE[1], _buttonLevel);
    displayStandartButton("theme", MENU_COLUMN[0], MENU_LINE[2], _buttonTheme );
    displayStandartButton("quit", MENU_COLUMN[0], MENU_LINE[3], _buttonQuit);
}



bool ViewMainMenu::initSFML()
{
    if (!initSprite("background", BACKGROUND_MAINMENU, 1, WINDOW_WIDTH, WINDOW_HEIGHT))
        return false;

    return true;
}

bool ViewMainMenu::initButtons()
{
    string name = "button_";
    if (!initSprite(name+"play", BUTTON_PLAY, 2, BUTTON_WIDTH, BUTTON_HEIGHT))
        return false;
    if (!initSprite(name+"quit", BUTTON_QUIT, 2, BUTTON_WIDTH, BUTTON_HEIGHT))
        return false;
    if (!initSprite(name+"theme", BUTTON_THEME, 2, BUTTON_WIDTH, BUTTON_HEIGHT))
        return false;
    if (!initSprite(name+"level", BUTTON_LEVEL, 2, BUTTON_WIDTH, BUTTON_HEIGHT))
        return false;
    
    return true;
}

void ViewMainMenu::updateButtons(const unsigned int mouseX, const unsigned int mouseY)
{
    _buttonPlay = mouseOnButton(mouseX, mouseY, MENU_COLUMN[0], MENU_LINE[0], BUTTON_WIDTH, BUTTON_HEIGHT);
    _buttonLevel = mouseOnButton(mouseX, mouseY, MENU_COLUMN[0], MENU_LINE[1], BUTTON_WIDTH, BUTTON_HEIGHT);
    _buttonTheme = mouseOnButton(mouseX, mouseY, MENU_COLUMN[0], MENU_LINE[2], BUTTON_WIDTH, BUTTON_HEIGHT);
    _buttonQuit = mouseOnButton(mouseX, mouseY, MENU_COLUMN[0], MENU_LINE[3], BUTTON_WIDTH, BUTTON_HEIGHT);
    
}









