//
//  Enemy.cpp
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "Enemy.h"

using namespace std;


Enemy::Enemy() : Perso()
{
    _width = ZOMBY_WIDTH;
    _height = ZOMBY_HEIGHT;
    _speed = ZOMBY_SPEED;
    _name = "zomby";
    _direction = "right";
    _traceNbMax = ZOMBY_NB_TRACE_MAX;
}

void Enemy::autoMove()
{
    if (_mazeCasePosition != nullptr)
    {
        // if enemi has begun a movement
        if (_isMoving)
        {
            move();
            // if he is in the destination mazeCase
            {
                GraphicElement e;
                e.setPosition(_X, _Y);
                e.setSize(_width, _height);
                if (_mazeCaseToGo != nullptr &&  _mazeCaseToGo->contain(&e))
                {
                    // end of the movement
                    setMazeCase(_mazeCaseToGo);
                    _mazeCaseToGo = nullptr;
                    _isMoving = false;
                }
            }
        }
        // else -> he is in a mazeCase
        else
        {
            changeDirection();
        }
    }
}

void Enemy::changeDirection()
{
    vector<std::string> avalaibleDirections ;
    // he has to choose a direction
    avalaibleDirections = _mazeCasePosition->getAvalaibleDirecton();
    
    if (_mazeCasePosition != nullptr && _mazeCasePosition->getTrace()->available())
    {
        traceFound(_mazeCasePosition->getTrace()->getDirection());
    }
    else
    {
        traceLoose();
        // random direction
        int random = 0;
        // if there is many possibilities
        if (avalaibleDirections.size() > 1)
        {
            do
            {
                random = rand() % avalaibleDirections.size();
            }
            while (avalaibleDirections[random] == oppositeDirection(_direction));
        }
        if (_mazeCasePosition->getExit())
            _direction = oppositeDirection(_direction);
        else
            _direction = avalaibleDirections[random];
    }
    _mazeCaseToGo = _mazeCasePosition->getNextMazeCase(_direction);
    _isMoving = true;
}


void Enemy::traceFound(std::string direction)
{
    _traceFound = true;
    _direction = direction;
    _speed = ZOMBY_SPEED +   ZOMBY_ACCELERATION;
}

void Enemy::traceLoose()
{
    _traceFound = false;
    _speed = ZOMBY_SPEED;
}

void Enemy::init()
{
    _traceFound = false;
    _playerFound = true;
    _life = 2;
}
