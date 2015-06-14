//
//  Enemy.cpp
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "Enemy.h"

using namespace std;


Enemy::Enemy()
{
    _speed = ZOMBY_SPEED;
    changeDirection();
}





void Enemy::autoMove(list<Wall*> * wallList)
{

    if (Wall::wallsCollision(this, wallList))
    {
        cout << "collision" << endl;
        MoveOpposite();
        changeDirection();
        Move();
    }
    else
    {
        Move();
    }

}

void Enemy::changeDirection()
{
    std::string newDirection = "";

    do
    {
        int random = rand() % 4 ;
        switch (random) {
            case 0:
                newDirection = "up";
                break;

            case 1:
                newDirection = "down";
                break;

            case 2:
                newDirection = "left";
                break;

            case 3:
                newDirection = "right";
                break;

            default:
                cout << __FUNCTION__ << "mauvaise direction" << endl;
                break;
        }
    } while (_direction == newDirection );
    _direction = newDirection;
}

void Enemy::findTrace(std::list<Trace *> *tracesList)
{
    for (Trace* trace : *tracesList)
    {
        if (this->ElementOnElement(trace))
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
