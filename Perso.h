//
//  Perso.h
//  ZombyMaze2
//
//  Created by Raphael Thibierge on 16/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __ZombyMaze2__Perso__
#define __ZombyMaze2__Perso__

#include <stdio.h>
#include "MovableElement.h"
#include "Maze.h"
#include "Bullet.h"

class Perso : public MovableElement
{
protected:
    MazeCase * _mazeCasePosition;
    MazeCase * _mazeCaseToGo;
    std::string _name;
    unsigned int _life;
    std::list<Trace*> _traceList;
    unsigned int _traceNbMax;
    unsigned int _money;
    
    
    // states
    bool _dead;
    bool _isMoving;

// CONSTRUCTORS AND DESTRUCTORS
public:
    Perso();
    
    ~Perso();
    
// METHODS
public:
    void leaveTrace();
    
    void affectDamage(const unsigned int damage);
    
    void updateMazeCase(std::list<MazeCase*> * mazeCaseList);

    
// ACCESSORS
public:
    MazeCase * getMazeCase() const;
    
    MazeCase * getMazeCasToGo() const;
    
    unsigned int getLife() const;
    
    bool getDead() const;

    void setMazeCase(MazeCase* mazeCase);
    
    Bullet* getShoot(const std::string direction) const;
    
    std::list<Trace*> * getTraceList();
    
    unsigned int getMoney() const;
    
};


#endif /* defined(__ZombyMaze2__Perso__) */
