//
//  Maze.cpp
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "Maze.h"

using namespace std;

#include <math.h>


Maze::Maze() : GraphicElement(){
    init();
    construct();

}

void Maze::init()
{
    _X = MAZE_X;
    _Y = MAZE_Y;
    _width = WINDOW_WIDTH;
    _height = WINDOW_HEIGHT;
    _size = MAZE_SIZE;
    
    _grid.resize(_size);
    for (int y = 0 ; y < _size ; y ++)
    {
        _grid[y].resize(_size);
        for (int x = 0 ; x < _size ; x++)
        {
            _grid[y][x].SetPosition(x, y);
            _mazeCaseList.push_back(&_grid[y][x]);
        }
    }
    
    //init tarceList
    for (MazeCase* mazeCase : _mazeCaseList)
    {
        _traceList.push_back(mazeCase->getTrace());
    }
    
    
}


Maze::~Maze()
{
    _wallList.clear();
    _traceList.clear();
    _mazeCaseList.clear();
}


//
// METHODS
//

// PUBLIC


// PRIVATE
void Maze::construct()
{
    fstream file;
    string line;

    file.open(MAZE_MATRICE_FILE, ios::in);
    for (unsigned int i = 0 ; i < MAZE_SIZE*2 ; i++ )
    {
        getline(file, line);
        for ( unsigned int j = 0 ; j < MAZE_SIZE ; j++)
        {
            if (line[j] == 'h')
            {
                // construct a horizontal wall
                addWall( j, i%MAZE_SIZE, 'h');

            }
            if (line[j] == 'v')
            {
                // construct a vertical wall
                addWall(i%MAZE_SIZE, j, 'v');
            }
        }
    }
    updateNextMazeCases();

}


void Maze::addWall(unsigned int x, unsigned int y, const char orientation)
{
    switch (orientation) {
        case 'h':
            // add physical wall
            _wallList.push_back(Wall::Horizontal(x*MAZECASE_SIZE+(x+1)*WALL_WIDTH_V, y*(MAZECASE_SIZE+WALL_HEIGHT_H)));
            
            // add wall in MazeCase
            _grid[y][x].addWall(MovableElement::directionToInt("up"));
            if (y > 0)
                _grid[y-1][x].addWall(MovableElement::directionToInt("down"));
            break;
            
        case 'v':
            // add vertical physical wall
            _wallList.push_back(Wall::Vertical(x*(MAZECASE_SIZE+WALL_WIDTH_V), y*MAZECASE_SIZE+(y+1)*WALL_HEIGHT_H));
            
            // add wall in MazeCase
            _grid[y][x].addWall(MovableElement::directionToInt("left"));
            
            if (x > 0)
            {
                _grid[y][x-1].addWall(MovableElement::directionToInt("right"));
            }
            break;
            
        default:
            break;
    }
}

void Maze::updateNextMazeCases()
{
    for (unsigned int line = 0 ; line < _size ; line ++)
    {
        for (unsigned int column = 0 ;  column < _size ; column++)
        {
            MazeCase* mazeCase = &_grid[line][column];
            for (string direction : mazeCase->getAvalaibleDirecton())
            {
                if (direction == "up" && line > 0)
                {
                    mazeCase->addNextMazeCase(&_grid[line-1][column], direction);
                }
                if (direction == "down")
                {
                    mazeCase->addNextMazeCase(&_grid[line+1][column], direction);
                }
                if (direction == "left" && column > 0)
                {
                    mazeCase->addNextMazeCase(&_grid[line][column-1], direction);
                }
                if (direction == "right")
                {
                    mazeCase->addNextMazeCase(&_grid[line][column+1], direction);
                }
            }
        }
    }
    
}


//
// ACCESSORS
//
MazeCase Maze::getCase(const int line, const int column) const
{
    return _grid[line][column];
}

list<Wall*> * Maze::getWallsList()
{
    return &_wallList;
}


list<Trace*> * Maze::getTraceList()
{
    return &_traceList;
}


list<MazeCase*> * Maze::getMazeCaseList()
{
    return &_mazeCaseList;
}

unsigned int Maze::getSize() const
{
    return _size;
}

MazeCase* Maze::getMazeCase(const unsigned int line, const unsigned int column)
{
    if (line < _size && column < _size )
    {
        return  &_grid[line][column];
    }
    return nullptr;
}