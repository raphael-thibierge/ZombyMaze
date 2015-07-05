//
//  MazeCase.cpp
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "MazeCase.h"

using namespace std;

// CONSTRUCTOR AND DESTRUCTOR
MazeCase::MazeCase()
{
    // init position
    _width = MAZECASE_SIZE;
    _height = MAZECASE_SIZE;
    _exit = false;
    init();
}

MazeCase::~MazeCase()
{
    for (auto pair : _nextMazeCase)
        pair.second = nullptr;
}

void MazeCase::init()
{
    // init walls
    for (unsigned int i = 0; i < 4 ; i++)
        _walls.push_back(false);
    _walls.resize(4);
    
    // init next maze case
    _nextMazeCase.insert(make_pair("up", nullptr));
    _nextMazeCase.insert(make_pair("down", nullptr));
    _nextMazeCase.insert(make_pair("left", nullptr));
    _nextMazeCase.insert(make_pair("right", nullptr));
}

//
// PUBLIC METHODS
//
void MazeCase::newTrace(const string direction, const string owner)
{
    _trace.newTrace(direction, owner);
}

void MazeCase::addWall(const unsigned int sideNumber)
{
    if (sideNumber < 4)
        _walls[sideNumber] = true;
}

void MazeCase::addNextMazeCase(MazeCase * mazeCase, const std::string direction)
{
    if (MovableElement::isDirection(direction))
        _nextMazeCase[direction] = mazeCase;
}

vector<string> MazeCase::getAvalaibleDirection() const
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

void MazeCase::place(GraphicElement *element) const
{
    element->setX(_X + (_width - element->getWidth() ) / 2 );
    element->setY(_Y + (_height - element->getHeight() ) / 2 );
}

const bool MazeCase::isAvailableDirection(std::string direction)
{
    return ( MovableElement::isDirection(direction) && !_walls[MovableElement::directionToInt(direction)]);
}

const bool MazeCase::isWall(const string direction) const
{
    return _walls[MovableElement::directionToInt(direction)];
}


//
// ACCESSORS
//

// GETTERS
Trace* MazeCase::getTrace()
{
    return &_trace;
}

MazeCase* MazeCase::getNextMazeCase(const std::string direction)
{
    MazeCase* mazeCase;
    if (MovableElement::isDirection(direction))
        return _nextMazeCase[direction] ;
    return  nullptr;
}

const bool MazeCase::getExit() const
{
    return _exit;
}

// SETTERS
void MazeCase::setExit(const bool exit)
{
    _exit = exit;
}

void MazeCase::SetPosition(const unsigned int x, const unsigned y)
{
    _X = MAZE_X + ( x * MAZECASE_SIZE ) + (x+1)*WALL_WIDTH_V;
    _Y = MAZE_Y + ( y * MAZECASE_SIZE ) + (y+1)*WALL_HEIGHT_H;
    place(&_trace);
}