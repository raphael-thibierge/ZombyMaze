//
//  Trace.cpp
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "Trace.h"

using namespace std;

Trace::Trace(const string direction, const unsigned int X, const unsigned int Y) : GraphicElement(), _direction(direction)
{
    _X = X;
    _Y = Y;
}

string Trace::getDirection() const
{
    return _direction;
}
