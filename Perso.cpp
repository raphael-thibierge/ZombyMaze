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
    _traceNbMax = 0;
    _money = 0;
    
}

Perso::~Perso()
{
    _mazeCasePosition = nullptr;
    _traceList.clear();
}


//
// METHODS
//
void Perso::leaveTrace()
{
    if (_mazeCasePosition != nullptr)
    {
        int cpt = 0;
        if (_traceList.size() > _traceNbMax)
        {
            Trace * trace = _traceList.front();
            _traceList.remove(trace);
            _traceList.resize(_traceNbMax -1);
        }
        cout << "coucou" << endl;
        _traceList.push_back(_mazeCasePosition->getTrace());
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
    if (_name == "player")
    {
        _money += _mazeCasePosition->takeCoins();
        leaveTrace();
        
    }
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