	//
//  Trace.cpp
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "Trace.h"

using namespace std;

Trace::Trace() : GraphicElement()
{
    _owner = "";
    _direction = "";
    _width = TRACE_WIDTH;
    _height = TRACE_HEIGHT;
    _available = false;
}



bool Trace::available() const
{
    if (_available)
    {
        cout << "ok" << endl;
    }
    return  _available;
}

void Trace::newTrace(const std::string direction, const std::string owner)
{
    if (MovableElement::isDirection(direction))
    {
        _direction = direction;
        _available = true;
    }
    _owner = owner;
}

void Trace::deleteTrace()
{
    _direction = "";
    _owner = "";
    _available = false;
}

//
// ACCESSORS
//


string Trace::getDirection() const
{
    return _direction;
}


string Trace::getOwner() const
{
    return _owner;
}


void Trace::setDirection(std::string direction)
{
    if (direction == "up" || direction == "down" || direction == "left" || direction == "right")
    {
        _direction = direction;
    }
}