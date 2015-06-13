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
