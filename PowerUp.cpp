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
}

std::string PowerUp::getName() const
{
    return _name;
}