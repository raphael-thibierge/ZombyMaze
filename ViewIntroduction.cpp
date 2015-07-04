//
//  ViewIntroduction.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 11/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "ViewIntroduction.h"

using namespace std;

//
// CONSTRUCTOR AND DESTRUCTOR
//
ViewIntroduction::ViewIntroduction()
{
    _time.restart();
    _end = false;
    _playerX = - PLAYER_WIDTH;
    _playerY = WINDOW_HEIGHT - PLAYER_HEIGHT - 80;
    _zombyX = - PLAYER_WIDTH - ZOMBY_WIDTH - 100;
    _zombyY = WINDOW_HEIGHT - ZOMBY_HEIGHT - 80;
    _cptSprite = 0 ;
}

ViewIntroduction::~ViewIntroduction(){}


//
// METHODS
//
int ViewIntroduction::treatEventSFML()
 {
    showViewSFML();

    int returnValue = 1;
    
     if (_end)
         returnValue = 0;

    sf::Event event;

     while (_window->pollEvent(event))
    {

        switch (event.type)
        {
        case sf::Event::Closed :
            returnValue = 111;
            break;

        case sf::Event::KeyPressed :
            switch (event.key.code)
            {
                case sf::Keyboard::Space:
                    returnValue = 0;
                    break;

                case sf::Keyboard::Escape :
                    returnValue = 0;
                    break;
                    
                case sf::Keyboard::R:
                    _playerX = - PLAYER_WIDTH;
                    _zombyX = - PLAYER_WIDTH - ZOMBY_WIDTH - 100;
                    break;
                
                default :
                    break;
        }
            break;

        default :
            break;
        }
    }

    return returnValue;
 }


void ViewIntroduction::showViewSFML()
{
    _window->draw(_spritesList["background"]);
    
    _playerX += 3;
    _zombyX += 3;
    _cptSprite++;
    
    if (_zombyX < (int)WINDOW_WIDTH)
    {
        string name = "player";
        
        if ((_playerX > 100 && _playerX < 200)
            || (_playerX > 400 && _playerX < 500)
            || (_playerX > 700 && _playerX < 800)
            || (_playerX > 1000 && _playerX < 1100)
            )
            name += "left";
        else
            name += "right";
        
        name += to_string(_cptSprite % PLAYER_NB_SPRITES);
        _spritesList[name].setPosition(_playerX, _playerY);
        _window->draw(_spritesList[name]);
        
        name = "zombyright" + to_string(_cptSprite % ZOMBY_NB_SPRITES);
        _spritesList[name].setPosition(_zombyX, _zombyY);
        _window->draw(_spritesList[name]);
    }
    else
    {
        _end = true;
    }
}

bool ViewIntroduction::initSFML()
{
    if (!initSprite("background", IMAGE_INTRO, 1, WINDOW_WIDTH, WINDOW_HEIGHT))
        return false;
    
    // player
    if (!initSprite("playerup", VIEWGAME_IMAGE_PLAYER_UP[0], PLAYER_NB_SPRITES, PLAYER_WIDTH, PLAYER_HEIGHT))
        return false;
    if (!initSprite("playerdown", VIEWGAME_IMAGE_PLAYER_DOWN[0], PLAYER_NB_SPRITES, PLAYER_WIDTH, PLAYER_HEIGHT))
        return false;
    if (!initSprite("playerleft", VIEWGAME_IMAGE_PLAYER_LEFT[0], PLAYER_NB_SPRITES, PLAYER_WIDTH, PLAYER_HEIGHT))
        return false;
    if (!initSprite("playerright", VIEWGAME_IMAGE_PLAYER_RIGHT[0], PLAYER_NB_SPRITES, PLAYER_WIDTH, PLAYER_HEIGHT))
        return false;
    
    // ZOMBY
    if (!initSprite("zombyright", VIEWGAME_IMAGE_ZOMBY_RIGHT[0], ZOMBY_NB_SPRITES, ZOMBY_WIDTH, ZOMBY_HEIGHT))
        return false;
    
    return true;
}

bool ViewIntroduction::initButtons()
{
    return true;
}

