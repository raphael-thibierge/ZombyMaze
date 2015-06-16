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
    _speed = 1;
    _direction = "down";
}

void MovableElement::Move()
{
    Move(_direction);
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

void MovableElement::MoveOpposite()
{
    MoveOpposite(_direction);
}

void MovableElement::MoveOpposite(string direction)
{
    if ( direction == "up")
        _Y += _speed;
    else if (direction == "down")
        _Y -= _speed;
    else if (direction == "left")
        _X += _speed;
    else if (direction == "right")
        _X -= _speed;
    else
        cout << "mauvaise direction " << endl;

}

// STATICS
bool MovableElement::isDirection(const string direcion)
{
    return (direcion == "up" || direcion == "down" || direcion == "left" || direcion == "right" );
}

unsigned int MovableElement::directionToInt(const string direction)
{
    if (direction == "up")
        return 0;
    if (direction == "right")
        return 1;
    if (direction == "down")
        return 2;
    if (direction == "left")
        return 3;
    return 0;
}

string MovableElement::intToDirection(const unsigned int direction)
{
    switch (direction) {
        case 0:
            return "up";
            break;
        case 1:
            return "right";
            break;
        
        case 2:
            return "down";
            break;
        
        case 3:
            return "left";
            
        default:
            return "up";
            break;
    }
}


//
// ACCESSORS
//
void MovableElement::setDirection(const string direction)
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
