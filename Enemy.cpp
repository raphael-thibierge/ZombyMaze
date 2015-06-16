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
}





void Enemy::autoMove()
{
    if (_mazeCasePosition != nullptr)
    {
        cout << _mazeCasePosition->isWall(_direction) << endl;
        if (_mazeCasePosition->isWall(_direction))
        {
            changeDirection();
        }
        
        Move();
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
    cout << "direciton choisie " << _direction << endl;
    

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
