//
//  MazeCase.cpp
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "MazeCase.h"

using namespace std;

MazeCase::MazeCase()
{
    // init position
    
    _width = MAZECASE_SIZE;
    _height = MAZECASE_SIZE;
    
    init();
}

MazeCase::~MazeCase()
{
    
}

void MazeCase::init()
{
    // init walls
    place(&_trace);
    for (unsigned int i = 0; i < 4 ; i++)
        _walls.push_back(false);
    _walls.resize(4);
}


void MazeCase::newTrace(const string direction, const string owner)
{
    _trace.newTrace(direction, owner);
}


void MazeCase::addWall(const unsigned int sideNumber)
{
    if (sideNumber < 4)
        _walls[sideNumber] = true;
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


unsigned int MazeCase::takeCoins()
{
    unsigned int total = 0;
    for(Coin* coin : _coinList)
    {
        total+= coin->getValue();
        delete coin;
        coin = nullptr;
    }
    _coinList.clear();
    return total;
}

void MazeCase::addCoin()
{
    _coinList.push_back(new Coin(1, _X, _Y));
}

void MazeCase::SetPosition(const unsigned int x, const unsigned y)
{
    _X = MAZE_X + ( x * MAZECASE_SIZE ) + (x+1)*WALL_WIDTH_V;
    _Y = MAZE_Y + ( y * MAZECASE_SIZE ) + (y+1)*WALL_HEIGHT_H;
}


void MazeCase::place(GraphicElement *element) const
{
    element->setX(_X + (_width - element->getWidth() ) / 2 );
    element->setY(_Y + (_height - element->getHeight() ) / 2 );
}




// ACCESSORS
bool MazeCase::isWall(const string direction) const
{
    return _walls[MovableElement::directionToInt(direction)];
}

Trace* MazeCase::getTrace()
{
    return &_trace;
}

std::list<Coin*> * MazeCase::getCoinList()
{
    return &_coinList;
}