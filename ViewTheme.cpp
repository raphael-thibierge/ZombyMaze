//
//  ViewTheme.cpp
//  ZombyMaze2
//
//  Created by Raphael Thibierge on 25/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "ViewTheme.h"
using namespace std;
using namespace sf;

ViewTheme::ViewTheme() : View()
{
    _buttonTheme1 = false;
    _buttonTheme2 = false;
    _buttonQuit = false;
}


const int ViewTheme::treatEventSFML()
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
            if (_buttonTheme1)
            {
                returnValue = 0;
                _modele->getPlayer()->setTheme(1);
            }
            
            else if (_buttonTheme2)
            {
                returnValue = 0;
                _modele->getPlayer()->setTheme(2);
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

void ViewTheme::showViewSFML()
{
    displayTitle("Choose yout theme", 100, 100);
    displayButtons();
}

const bool ViewTheme::initSFML()
{
    return true;
}

const bool ViewTheme::initButtons()
{
    string name = "button_";
    if (!initSprite(name+"theme1", BUTTON_PLAY, 2, BUTTON_WIDTH, BUTTON_HEIGHT))
        return false;
    if (!initSprite(name+"theme2", BUTTON_PLAY, 2, BUTTON_WIDTH, BUTTON_HEIGHT))
        return false;
    if (!initSprite(name+"quit", BUTTON_QUIT, 2, BUTTON_WIDTH, BUTTON_HEIGHT))
        return false;
    return true;
}

void ViewTheme::updateButtons(const unsigned int mouseX, const unsigned int mouseY)
{
    _buttonTheme1 = mouseOnButton(mouseX, mouseY, MENU_COLUMN[0], MENU_LINE[0], BUTTON_WIDTH, BUTTON_HEIGHT);
    _buttonTheme2 = mouseOnButton(mouseX, mouseY, MENU_COLUMN[0], MENU_LINE[1], BUTTON_WIDTH, BUTTON_HEIGHT);
    _buttonQuit = mouseOnButton(mouseX, mouseY, MENU_COLUMN[0], MENU_LINE[2], BUTTON_WIDTH, BUTTON_HEIGHT);
    
    
}

void ViewTheme::displayButtons()
{
    displayStandartButton("theme1", MENU_COLUMN[0], MENU_LINE[0], _buttonTheme1);
    displayStandartButton("theme2", MENU_COLUMN[0], MENU_LINE[1], _buttonTheme2 );
    displayStandartButton("quit", MENU_COLUMN[0], MENU_LINE[2], _buttonQuit);
}