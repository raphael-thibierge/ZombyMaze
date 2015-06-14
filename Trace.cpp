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
    _life = TRACE_LIFE;
}

string Trace::getDirection() const
{
    return _direction;
}

void Trace::looseLife()
{
    if ( _life > 0)
        _life--;
}
