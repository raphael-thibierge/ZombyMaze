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
    std::string _name;
    unsigned int _life;
    
    // states
    bool _dead;

// CONSTRUCTORS AND DESTRUCTORS
public:
    Perso();
    
    ~Perso();
    
// METHODS
public:
    void leaveTrace();
    
    void affectDamage(const unsigned int damage);
    
    
// ACCESSORS
public:
    MazeCase * getMazeCase() const;
    
    unsigned int getLife() const;
    
    bool getDead() const;

    void setMazeCase(MazeCase* mazeCase);
    
    Bullet* getShoot(const std::string direction) const;
    
};


#endif /* defined(__ZombyMaze2__Perso__) */
