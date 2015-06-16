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

class Perso : public MovableElement
{
private:
    MazeCase * _mazeCasePosition;

// CONSTRUCTORS AND DESTRUCTORS
public:
    Perso();
    
    ~Perso();
    
// METHODS
public:
    void leaveTrace();
    
// ACCESSORS
public:
    MazeCase * getMazeCase() const;
    
    void setMazeCase(MazeCase* mazeCase);
    
    
    
};


#endif /* defined(__ZombyMaze2__Perso__) */
