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
    _time.Reset();
}

ViewIntroduction::~ViewIntroduction(){}


//
// METHODS
//


int ViewIntroduction::treatEventSFML()
 {
    showViewSFML();

    int returnValue = 1;

    if (_time.GetElapsedTime() > TIME_INTRODUCTION)
        returnValue = 0;

    sf::Event event;

     while (_window->GetEvent(event))
    {

        switch (event.Type)
        {
        case sf::Event::Closed :
            returnValue = 111;
            break;

        case sf::Event::KeyPressed :
            switch (event.Key.Code)
            {

                case sf::Key::Space:
                    returnValue = 0;
                    break;

                case sf::Key::Escape :
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
    _window->Draw(_spritesList["background"]);
}

bool ViewIntroduction::initSFML()
{
        // background image
    _imagesList.insert(make_pair("background", sf::Image()));
    if (!_imagesList["background"].LoadFromFile(IMAGE_INTRO))
        return false;
    // background sprite
    _spritesList.insert(make_pair("background", sf::Sprite()));
    _spritesList["background"].SetImage(_imagesList["background"]);
    _spritesList["background"].SetSubRect(sf::IntRect(0,0, WINDOW_WIDTH, WINDOW_HEIGHT));
    _spritesList["background"].SetPosition(0,0);
    return true;
}

