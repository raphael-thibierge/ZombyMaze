//
//  Perso.cpp
//  ZombyMaze2
//
//  Created by Raphael Thibierge on 16/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "Perso.h"

using namespace std;

// CONSTRUCTOR AND DESTRUCTOR
Perso::Perso() : MovableElement()
{
    _name = "";
    _mazeCasePosition = nullptr;
    _life = 1;
    _dead = false;
    
}

Perso::~Perso()
{
    _mazeCasePosition = nullptr;
}


//
// METHODS
//
void Perso::leaveTrace()
{
    if (_mazeCasePosition != nullptr)
    {
        if (_mazeCasePosition->getTrace() != nullptr && _mazeCasePosition->getTrace()->getOwner() == _name)
        {
                _mazeCasePosition->getTrace()->setDirection(_direction);
        }
        else
        {
            _mazeCasePosition->newTrace(_direction, _name);
        }
    }
}

void Perso::affectDamage(const unsigned int damage)
{
    if (damage >= _life)
    {
        _life = 0;
        _dead = true;
    }
    else
    {
        _life -= damage;
    }
}

//
// ACCESSORS
//

MazeCase* Perso::getMazeCase() const
{
    return _mazeCasePosition;
}

unsigned int Perso::getLife() const
{
    return _life;
}

bool Perso::getDead() const
{
    return _dead;
}


void Perso::setMazeCase(MazeCase * mazeCase)
{
    _mazeCasePosition = mazeCase;
}

Bullet* Perso::getShoot(const std::string direction) const
{
    unsigned int x = _X + (_width - BULLET_WIDTH)/2;
    unsigned int y = _Y + (_height - BULLET_WIDTH)/2;
    
    return new Bullet(direction, x, y);
}
