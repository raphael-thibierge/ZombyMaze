//
//  Enemy.cpp
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "Enemy.h"


Enemy::Enemy()
{
    _speed = 2;
}





void Enemy::autoMove()
{
    Move();

}

void Enemy::traceFound(std::string direction)
{
    _traceFound = true;
    _direction = direction;

}

void Enemy::init()
{
    _traceFound = false;
    _life = 2;
}
