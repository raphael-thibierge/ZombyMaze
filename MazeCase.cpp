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
    
    init();
}

MazeCase::~MazeCase()
{
    if (_trace != nullptr)
        delete _trace;
    _trace = nullptr;
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


void MazeCase::newTrace(const string direction, const string owner)
{
    if (_trace != nullptr)
    {
        delete _trace;
    }
    _trace = new Trace( direction, owner,_X + (MAZECASE_SIZE-TRACE_WIDTH)/2, _Y + (MAZECASE_SIZE-TRACE_HEIGHT)/2);
}


void MazeCase::addWall(const unsigned int sideNumber)
{
    if (sideNumber < 4)
    {
        _walls[sideNumber] = true;
    }
}

vector<string> MazeCase::getAvalaibleDirecton() const
{
    vector<string> result;
    int cpt = 0;
    for (int i = 0; i < 4 ; i++)
    {
        if (!_walls[i])
        {
            result.push_back(MovableElement::intToDirection(i));
            cpt++;
        }
    }
    result.resize(cpt);
    return result;
}

// ACCESSORS
bool MazeCase::isWall(const string direction) const
{
    return _walls[MovableElement::directionToInt(direction)];
}

Trace* MazeCase::getTrace() const
{
    return _trace;
}

Trace** MazeCase::getTracePointer()
{
    return &_trace;
}