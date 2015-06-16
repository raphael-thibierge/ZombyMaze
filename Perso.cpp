//
//  Perso.cpp
//  ZombyMaze2
//
//  Created by Raphael Thibierge on 16/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "Perso.h"

// CONSTRUCTOR AND DESTRUCTOR
Perso::Perso() : MovableElement()
{
    
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
        _mazeCasePosition->newTrace(_direction);
    }
}

//
// ACCESSORS
//

MazeCase* Perso::getMazeCase() const
{
    return _mazeCasePosition;
}

void Perso::setMazeCase(MazeCase * mazeCase)
{
    _mazeCasePosition = mazeCase;
}
