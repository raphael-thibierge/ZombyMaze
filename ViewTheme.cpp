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

ViewTheme::ViewTheme() : View(), _themeMenu(Menu(400, 300))
{
    _buttonQuit = false;
    _themeMenu.createMosaic(2, 2);
    _themeMenu.setPosition(400, 200);
    _themeMenu.update(0, 0);
}


const int ViewTheme::treatEventSFML()
{
    int returnValue = 1;
    Event event;
    while (_window->pollEvent(event)) {
        if (event.type == Event::MouseMoved)
        {
            unsigned int mouseX = event.mouseMove.x;
            unsigned int mouseY = event.mouseMove.y;
            
            transformMousePosition(mouseX, mouseY);
            
            _themeMenu.update(mouseX, mouseY);
            _buttonQuit = mouseOnButton(mouseX, mouseY, 450, 600, BUTTON_WIDTH, BUTTON_HEIGHT);
        }
        
        if (event.type == Event::MouseButtonPressed)
        {
            Button * button = _themeMenu.getButtonClicked();
            
            if (button != nullptr)
            {
                string level = button->getText();
                unsigned int number = atoi(&level[0]);
                if (number <= 2 )
                {
                    returnValue = 0;
                    _modele->getPlayer()->setTheme(number);
                }
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
        if (event.type == event.Closed )
            return 111;
    }
    return returnValue;
}

void ViewTheme::showViewSFML()
{
    _window->draw(_spritesList["background"]);
    _window->draw(_themeMenu.getSprite());
    displayTitle("Choose yout theme", 340, 100);
    displayStandartButton("quit", 450, 600, _buttonQuit);
}

const bool ViewTheme::initSFML()
{
    if (!initSprite("background", VIEW_BACKGROUND_IMAGE, 1, WINDOW_WIDTH, WINDOW_HEIGHT))
        return false;
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

void ViewTheme::update()
{
    cout << "aaa" << endl;
    if (_modele->getPlayer() != nullptr)
    {
        int number = 1;
        for (auto button : *_themeMenu.getButtonsList())
        {
            cout << ">>" << number << " " << _modele->getPlayer()->getTheme() << endl;
            if ( number <= _modele->getPlayer()->getTheme() && button.second != nullptr)
                
                button.second->setAvailable(true);
            else if (button.second != nullptr)
                button.second->setAvailable(false);
            number++;
        }
        _themeMenu.standartUpdate();
    }
}
