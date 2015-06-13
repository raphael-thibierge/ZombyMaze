//
//  MovableElement.cpp
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "MovableElement.h"

using namespace std;

MovableElement::MovableElement() : GraphicElement()
{

}

void MovableElement::Move()
{
    if ( _direction == "up")
        _Y -= _speed;
    if (_direction == "down")
        _Y += _speed;
    if (_direction == "left")
        _X -= _speed;
    if (_direction == "right")
        _X += _speed;
}

void MovableElement::Move(string direction)
{
    if ( direction == "up")
        _Y -= _speed;
    if (direction == "down")
        _Y += _speed;
    if (direction == "left")
        _X -= _speed;
    if (direction == "right")
        _X += _speed;
}

// ACCESSORS

void MovableElement::setDirection(const std::string direction)
{
    if (direction == "up"
        || direction == "down"
        || direction == "left"
        || direction == "right")

        _direction = direction;
}

void MovableElement::setSpeed(const unsigned int speed)
{
    _speed = speed;
}

string MovableElement::getDirection() const
{
    return _direction;
}

unsigned int MovableElement::getSpeed() const
{
    return _speed;
}
