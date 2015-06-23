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
    // details
    _name = "";
    _life = 1;
    _traceNbMax = 0;
    _money = 0;
    
    
    // pointers
    _mazeCasePosition = nullptr;
    _mazeCaseToGo = nullptr;
    
    // _states
    _dead = false;
    _isMoving = false;
}

Perso::~Perso()
{
    _mazeCasePosition = nullptr;
    _mazeCaseToGo = nullptr;
    _traceList.clear();
}


//
// METHODS
//
void Perso::leaveTrace()
{
    if (_mazeCasePosition != nullptr)
    {
        _mazeCasePosition->newTrace(_direction, _name); 

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

void Perso::updateMazeCase(std::list<MazeCase *> *mazeCaseList)
{
    for (MazeCase* mazeCase : *mazeCaseList)
    {
        if (mazeCase->contain(this))
        {
            setMazeCase(mazeCase);
        }
    }
}

void Perso::addMoney(const unsigned int value)
{
    _money += value;
}

// ============================================
// ============  ACCESSOR METHODS  ============
// ============================================

MazeCase* Perso::getMazeCase() const
{
    return _mazeCasePosition;
}

MazeCase* Perso::getMazeCasToGo() const
{
    return _mazeCaseToGo;
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

unsigned int Perso::getMoney() const
{
    return _money;
}