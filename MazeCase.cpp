//
//  MazeCase.cpp
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "MazeCase.h"

using namespace std;

MazeCase::MazeCase(const unsigned int line, const unsigned int column)
{
    // init position
    _X = MAZE_X + ( column * MAZECASE_SIZE );
    _Y = MAZE_Y + ( line + MAZECASE_SIZE );
    
    init();
}


void MazeCase::init()
{
    // init walls
    for (unsigned int i = 0; i < 4 ; i++)
        _walls.push_back(false);
    _walls.resize(4);
    
    
    
    
}



// ACCESSORS
bool MazeCase::isWall(string direction) const
{
    if ( direction == "up" )
        return _walls[0];
    if ( direction == "right" )
        return _walls[1];
    if ( direction == "down" )
        return _walls[2];
    if ( direction == "left" )
        return _walls[3];
    return false;
}