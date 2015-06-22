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
    _width = TRACE_WIDTH;
    _height = TRACE_HEIGHT;
    _lifeTime = TRACE_LIFE;
    
    deleteTrace(); // init the trace
}



bool Trace::available() const
{
    return _available;
}

void Trace::newTrace(const std::string direction, const std::string owner)
{
    deleteTrace();
    if (MovableElement::isDirection(direction))
    {
        _direction = direction;
        _owner = owner;
        _life.restart();
        _available = true;
    }
    else
    {
        cout << __FUNCTION__ << " not a direction" << endl;
    }
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
    else
    {
        _available = false;
    }
}