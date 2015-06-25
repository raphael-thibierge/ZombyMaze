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
        }
    }
    return returnValue;
}

void ViewMainMenu::showViewSFML()
{
    _window->draw(_spritesList["background"]);
    
    displayStandartButton("play", MENU_COLUMN_1, MENU_LINE_1, _buttonPlay);
    displayStandartButton("theme", MENU_COLUMN_1, MENU_LINE_2, _buttonTheme );
    displayStandartButton("quit", MENU_COLUMN_1, MENU_LINE_3, _buttonQuit);
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
    
    return true;
}

void ViewMainMenu::updateButtons(const unsigned int mouseX, const unsigned int mouseY)
{
    _buttonPlay = mouseOnButton(mouseX, mouseY, MENU_COLUMN_1, MENU_LINE_1, BUTTON_WIDTH, BUTTON_HEIGHT);
    _buttonQuit = mouseOnButton(mouseX, mouseY, MENU_COLUMN_1, MENU_LINE_3, BUTTON_WIDTH, BUTTON_HEIGHT);
    _buttonTheme = mouseOnButton(mouseX, mouseY, MENU_COLUMN_1, MENU_LINE_2, BUTTON_WIDTH, BUTTON_HEIGHT);
}









