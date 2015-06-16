//
//  Player.cpp
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "Player.h"

using namespace std;

Player::Player() : Perso()
{
    _direction = "down";
    _isMoving = false;
    _speed = 5;
    _width = PLAYER_WIDTH;
    _height = PLAYER_HEIGHT;
}

void Player::Move(const std::string direction)
{
    if (direction == "up" || direction == "down" || direction == "left" || direction == "right")
        _direction = direction;

    _isMoving = true;
    MovableElement::Move(_direction);
    leaveTrace();
}





void Player::setMoving(const bool moving)
{
    _isMoving = moving;
}

bool Player::getMoving() const
{
    return _isMoving;
}

Trace * Player::getTrace()
{
    if (_direction == "up")
        return new Trace( _direction,_X + (_width-TRACE_WIDTH)/2, _Y);
    if (_direction == "down")
        return  new Trace(_direction, _X + (_width-TRACE_WIDTH)/2, _Y);
    if (_direction == "left")
        return  new Trace(_direction, _X, _Y);
    if (_direction == "right")
        return  new Trace(_direction, _X, _Y);
    return nullptr;
}
