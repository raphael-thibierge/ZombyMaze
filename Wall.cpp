//
//  Wall.cpp
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "Wall.h"

using namespace std;

Wall::Wall(const unsigned int positionX, const unsigned int positionY,  const unsigned int width, const unsigned int height) : GraphicElement()
{
    _X = positionX;
    _Y = positionY;
    _width = width;
    _height = height;


    init();
}

void Wall::init()
{
    // set size
    if (_width > _height)
    {
        _orientation = 'h';
    }
    else
    {
        _orientation = 'v';
    }
}

// SATTIC
Wall* Wall::Horizontal(const unsigned int X, const unsigned int Y)
{
    return new Wall(X, Y, WALL_WIDTH_H, WALL_HEIGHT_H);
}

Wall * Wall::Vertical(const unsigned int X, const unsigned int Y)
{
    return new Wall(X, Y, WALL_WIDTH_V, WALL_HEIGHT_V);
}

char Wall::getOrientation() const
{
    return _orientation;
}
