//
//  Wall.cpp
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "Wall.h"

using namespace std;

Wall::Wall(const unsigned int positionX, const unsigned int positionY) : GraphicElement()
{
    init();
    _X = positionX;
    _Y = positionY;
}

void Wall::init()
{
    // set size
    _width = WALL_WIDTH;
    _height = WALL_HEIGHT;
    
    _orientation = 'h';
}