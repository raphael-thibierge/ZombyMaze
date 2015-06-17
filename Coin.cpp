//
//  Coin.cpp
//  ZombyMaze2
//
//  Created by Raphael Thibierge on 17/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "Coin.h"

using namespace std;


Coin::Coin(const unsigned int value, const unsigned int x, const unsigned int y) : GraphicElement()
{
    _value = value;
    _width = COIN_WIDTH;
    _height = COIN_HEIGHT;
    _X = x;
    _Y = y;
}

//
// ACCESSORS
//

unsigned int Coin::getValue() const
{
    return _value;
}

void Coin::setValue(const unsigned int value)
{
    _value = value;
}