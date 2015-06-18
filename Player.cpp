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
    reset();
}

void Player::reset()
{
    _direction = "down";
    _isMoving = false;
    _speed = 5;
    _width = PLAYER_WIDTH;
    _height = PLAYER_HEIGHT;
    _name = "player";
    _traceNbMax = PLAYER_NB_TRACE_MAX;
}

void Player::autoMove()
{
    // if player has begun a movement
    if (_isMoving)
    {
        MovableElement::Move();
        // if he is in the destination mazeCase
        {
            if (_mazeCaseToGo != nullptr && _mazeCaseToGo->contain(this))
            {
                // end of the movement
                leaveTrace();
                _mazeCasePosition = _mazeCasePosition;
                _mazeCaseToGo = nullptr;
                _isMoving = false;
            }
        }
    }
}

void Player::chooseDirection(const string direction)
{
    if (isDirection(direction) && !_isMoving)
    {
        if (_mazeCasePosition != nullptr && _mazeCasePosition->isAvailableDirection(direction) )

        {
            _direction = direction;
            _mazeCaseToGo = _mazeCasePosition->getNextMazeCase(_direction);
            _isMoving = true;
        }
    }
}


void Player::setMoving(const bool moving)
{
    _isMoving = moving;
}

bool Player::getMoving() const
{
    return _isMoving;
}