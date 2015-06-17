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
            _grid[y][x]= new MazeCase(x, y);
            _mazeCaseList.push_back(_grid[y][x]);
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
            _grid[y][x]->addWall(MovableElement::directionToInt("up"));
            if (y > 0)
                _grid[y-1][x]->addWall(MovableElement::directionToInt("down"));
            break;
            
        case 'v':
            // add vertical physical wall
            _wallList.push_back(Wall::Vertical(x*(MAZECASE_SIZE+WALL_WIDTH_V), y*MAZECASE_SIZE+(y+1)*WALL_HEIGHT_H));
            
            // add wall in MazeCase
            _grid[y][x]->addWall(MovableElement::directionToInt("left"));
            cout << " line " << y << " column " << x << "direction " << "left" << endl;
            if (x > 0)
            {
                _grid[y][x-1]->addWall(MovableElement::directionToInt("right"));
                cout << ">> line " << y << " column " << x-1 << "direction " << "right" << endl;
            }
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
