//
//  PowerUp.cpp
//  ZombyMaze2
//
//  Created by Raphael Thibierge on 19/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "PowerUp.h"

PowerUp::PowerUp(std::string name) : GraphicElement()
{
    _name = name;
    _width = GUN_WIDTH;
    _height = GUN_HEIGHT;
    _avalaible = true;
}

std::string PowerUp::getName() const
{
    return _name;
}

bool PowerUp::getAvailable() const
{
    return _avalaible;
}

void PowerUp::setAvailable(const bool available)
{
    _avalaible = available;
}