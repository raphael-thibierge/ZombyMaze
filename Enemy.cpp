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
                cout << _X << " " << _Y << " " << " " << _width << " " << _height << endl;
                if (_mazeCaseToGo != nullptr &&  _mazeCaseToGo->contain(&e))
                {
                    // end of the movement
                    setMazeCase(_mazeCaseToGo);
                    _mazeCaseToGo = nullptr;
                    _isMoving = false;
                }
            }
        }
        // else -> he is in a mainCase
        else
        {
            vector<std::string> avalaibleDirection ;
            // he has to choose a direction
            avalaibleDirection = _mazeCasePosition->getAvalaibleDirecton();
            
            if (_traceFound && _mazeCasePosition != nullptr && _mazeCasePosition->getTrace()->available())
            {
                _direction = _mazeCasePosition->getTrace()->getDirection();
            }
            else
            {
                // random direction
                int random = 0;
                // if there is many possibilities
                if (avalaibleDirection.size() > 1)
                {
                    do
                    {
                        random = rand() % avalaibleDirection.size();
                    }
                    while (avalaibleDirection[random] == oppositeDirection(_direction));
                }
                
                
                _direction = avalaibleDirection[random];
                _mazeCaseToGo = _mazeCasePosition->getNextMazeCase(_direction);
                _isMoving = true;
            }
        }
    }
}

void Enemy::changeDirection()
{
    vector<string> directions = _mazeCasePosition->getAvalaibleDirecton();
    
    int random;
    do
    {
        random = rand() % directions.size();
    } while (directions[random] == _direction);
    
    _direction = directions[random];
}

void Enemy::findTrace(std::list<Trace *> *tracesList)
{
    for (Trace* trace : *tracesList)
    {
        if (trace->available() && trace->getOwner() == "player")
        {
            traceFound(trace->getDirection());
            return;
        }
    }
    traceLoose();
}



void Enemy::traceFound(std::string direction)
{
    _traceFound = true;
    _direction = direction;
    _speed += ZOMBY_ACCELERATION;
}

void Enemy::traceLoose()
{
    _traceFound = false;
    _speed -= ZOMBY_ACCELERATION;
}

void Enemy::init()
{
    _traceFound = false;
    _playerFound = true;
    _life = 2;
}
