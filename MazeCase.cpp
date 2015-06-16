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
    _X = MAZE_X + ( column * MAZECASE_SIZE ) + (column+1)*WALL_WIDTH_V;
    _Y = MAZE_Y + ( line * MAZECASE_SIZE ) + (line+1)*WALL_HEIGHT_H;
    _width = MAZECASE_SIZE;
    _height = MAZECASE_SIZE;
    
    cout << _X << " " << column << " " <<_Y << " " << line << endl;
    
    init();
}

MazeCase::~MazeCase()
{
    
}

void MazeCase::init()
{
    //init trace
    _trace = nullptr;
    
    // init walls
    for (unsigned int i = 0; i < 4 ; i++)
        _walls.push_back(false);
    _walls.resize(4);
}


void MazeCase::newTrace(string direction)
{
    if (_trace != nullptr)
    {
        delete _trace;
    }
    _trace = new Trace( direction, _X + (MAZECASE_SIZE-TRACE_WIDTH)/2, _Y + (MAZECASE_SIZE-TRACE_HEIGHT)/2);
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

Trace* MazeCase::getTrace() const
{
    return _trace;
}

Trace** MazeCase::getTracePointer()
{
    return &_trace;
}