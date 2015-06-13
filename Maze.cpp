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
}





void Maze::init()
{
    _X = MAZE_X;
    _Y = MAZE_Y;
    _size = MAZE_SIZE;
    
    
    // initialistaion de la grille
    for ( unsigned int line = 0 ; line < _size ; line++ )
    {
        
        vector<MazeCase*> tmp;
        for ( unsigned int column ; column < _size ; column++)
        {
            tmp.push_back(new MazeCase(line, column));
        }
        tmp.resize(_size);
        _grid.push_back(tmp);
    }
    _grid.resize(_size);
    // fin initialisation
    
    
}

// STATICS

Maze Maze::MazeLevel1()
{
    Maze maze;
    return maze;
    
}

// ACCESSORS
MazeCase Maze::getCase(const int line, const int column) const
{
    return *_grid[line][column];
}



/* ===================================
vector<int> listType1 (const int size)
{
    vector<int> list;
    
    for (unsigned int i = 0; i < pow(size, 2); i++) {
        list.push_back(i);
    }
    return list;
}

vector<vector<int>> listType2(const int size)
{
    vector<vector<int>> list;
    
    int maxFor = pow(size, 2) - 1 ;
    for (unsigned int i = 0; i < maxFor ; i++)
    {
        if ( (i+1)%size != 0 )
        {
            vector<int> tmp;
            tmp.push_back(i);
            tmp.push_back(i+1);
            list.push_back( tmp );
        }
    }
    
    maxFor = pow(size, 2) - size;
    for (unsigned int i = 0 ; i < maxFor ; i++)
    {
        vector<int> tmp;
        tmp.push_back( i );
        tmp.push_back( i + size );
        
    }
    
    return list;
}

vector<vector<int>> Maze::algo(unsigned int n)
{
    vector<int> list1 = listType1(n);
    vector<vector<int>> list2 = listType2(n);
    
    vector<int> l;
    
    int test;
    
    // a corriger
    vector<int> tmp;
    
    while (list1 != tmp )
    {
        test = list1[0];
        int size = list2.size();
        
        int alea = rand()%(size);
        l = list2[alea];
        if (list1[l[0]] != list1[l[1]])
        {
            l[0] = list1[l[0]];
            l[1] = list1[l[1]];
            

        }
        
        
    }
    

    
    return list2;
}

*/