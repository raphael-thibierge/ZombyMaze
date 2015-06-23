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
}

ViewIntroduction::~ViewIntroduction(){}


//
// METHODS
//


int ViewIntroduction::treatEventSFML()
 {
    showViewSFML();

    int returnValue = 1;
     /*
    if (_time.getElapsedTime() > TIME_INTRODUCTION)
        returnValue = 0;
*/
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
                    // at this point play/stop states is always stop !
                    _modele->setPlayStop();
                    break;

                case sf::Keyboard::Escape :
                    returnValue = 0;
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
}

bool ViewIntroduction::initSFML()
{
    if (!initSprite("background", IMAGE_INTRO, 1, WINDOW_WIDTH, WINDOW_HEIGHT))
        return false;
    return true;
}

bool ViewIntroduction::initButtons()
{
    return true;
}

