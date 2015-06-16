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
    for (int i = 0 ; i < _size ; i ++)
    {
        _grid[i].resize(_size);
        for (int j = 0 ; j < _size ; j++)
        {
            _grid[i][j]= new MazeCase(j, i);
            _mazeCaseList.push_back(_grid[i][j]);
        }
    }
    
    //init tarceList
    for (MazeCase* mazeCase : _mazeCaseList)
    {
        _traceList.push_back(mazeCase->getTracePointer());
    }
    
    
}


Maze::~Maze()
{
    
    // delete grid
    for ( unsigned int line = 0 ; line < _size ; line++ )
    {
        for ( unsigned int column ; column < _size ; column++)
        {
            if (_grid[line][column] != nullptr)
            {
                delete _grid[line][column];
                _grid[line][column] = nullptr;
                
            }
        }
    }
    
    
    _wallList.clear();
    _traceList.clear();
    _mazeCaseList.clear();
}






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

}

void Maze::addWall(unsigned int x, unsigned int y, const char orientation)
{
    switch (orientation) {
        case 'h':
            // add physical wall
            _wallList.push_back(Wall::Horizontal(x*MAZECASE_SIZE+(x+1)*WALL_WIDTH_V, y*(MAZECASE_SIZE+WALL_HEIGHT_H)));
            
            // add wall in MazeCase
            _grid[y][x]->addWall(0);
            if (y > 0)
                _grid[y-1][x]->addWall(2);
            break;

        case 'v':
            // add physical wall
            _wallList.push_back(Wall::Vertical(x*(MAZECASE_SIZE+WALL_WIDTH_V), y*MAZECASE_SIZE+(y+1)*WALL_HEIGHT_H));
            
            // add wall in MazeCase
            _grid[y][x]->addWall(3);
            if (x > 0)
                _grid[y][x-1]->addWall(1);
            break;
        
        default:
            break;
    }
}

//
// ACCESSORS
//
MazeCase Maze::getCase(const int line, const int column) const
{
    return *_grid[line][column];
}

list<Wall*> * Maze::getWallsList()
{
    return &_wallList;
}


list<Trace**> * Maze::getTraceList()
{
    return &_traceList;
}


list<MazeCase*> * Maze::getMazeCaseList()
{
    return &_mazeCaseList;
}
