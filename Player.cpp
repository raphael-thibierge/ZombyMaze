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
    _level = 1;
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
    _gunAvalaible = false
    ;
    _fireRateTime = PLAYER_FIRE_RATE;
    _nbAmmo = 0;
    _fireRate.restart();
}

void Player::autoMove()
{
    // if player has begun a movement
    if (_isMoving)
    {
        move();
        // if he is in the destination mazeCase
        {
            if (_mazeCaseToGo != nullptr && _mazeCaseToGo->contain(this))
            {
                // end of the movement
                leaveTrace();
                setMazeCase(_mazeCaseToGo);
                _mazeCaseToGo = nullptr;
                _isMoving = false;
            }
        }
    }
}

void Player::useAmmo()
{
    if (_nbAmmo > 0)
        _nbAmmo--;
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

void Player::nextLevel()
{
    _level++;
}


bool Player::canShoot()
{
    if(_gunAvalaible && _nbAmmo > 0 && _fireRate.getElapsedTime() > _fireRateTime)
    {
        _fireRate.restart();
        return true;
    }
    return false;
}

void Player::setMoving(const bool moving)
{
    _isMoving = moving;
}

bool Player::getMoving() const
{
    return _isMoving;
}

bool Player::getGun()
{
    return _gunAvalaible;
}

unsigned int Player::getAmmo() const
{
    return _nbAmmo;
}

void Player::setGun(bool available = true)
{
    _gunAvalaible = available;
}

unsigned int Player::getLevel() const
{
    return _level;
}

void Player::addAmmo(const unsigned int number)
{
    _nbAmmo += number;
}