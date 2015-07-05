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



void MovableElement::move(string direction)
{
    if (direction == "")
        direction = _direction;
    
    if ( direction == "up")
        _Y -= _speed;
    if (direction == "down")
        _Y += _speed;
    if (direction == "left")
        _X -= _speed;
    if (direction == "right")
        _X += _speed;
}


void MovableElement::moveOpposite(string direction)
{
    if (direction == "" )
        direction = _direction;
    
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
const bool MovableElement::isDirection(const string direction)
{
    return (direction == "up" || direction == "down" || direction == "left" || direction == "right" );
}

const unsigned int MovableElement::directionToInt(const string direction)
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

const string MovableElement::intToDirection(const unsigned int direction)
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
            return "null";
            break;
    }
}

const string MovableElement::oppositeDirection(std::string direction)
{
    if (isDirection(direction))
    {
        return intToDirection((directionToInt(direction)+2)%4 );
    }
    return "null";
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

const string MovableElement::getDirection() const
{
    return _direction;
}

const unsigned int MovableElement::getSpeed() const
{
    return _speed;
}
