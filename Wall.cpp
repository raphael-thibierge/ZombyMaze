//
//  Wall.cpp
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "Wall.h"

using namespace std;

Wall::Wall() : GraphicElement()
{
    init();
}

void Wall::init()
{
    // set size
    _width = WALL_WIDTH;
    _height = WALL_HEIGHT;

    // position
    _X = 0;
    _Y = 0;
    
    _orientation = 'h';
}