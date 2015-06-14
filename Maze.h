//
//  Maze.h
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __Console__Maze__
#define __Console__Maze__

#include <stdio.h>
#include "MazeCase.h"
#include "Wall.h"
#include <iostream>
#include <fstream>

class Maze : public GraphicElement
{

private:
    std::vector<std::vector<MazeCase*> > _grid;
    std::list<Wall*> _wallList;
    unsigned int _size ;

public:

    Maze();

private:

    void init();

    void construct();
    
    
    
    void addWall(unsigned int x, unsigned int y, const char orientation);

    //static std::vector<int> listType1 (const int size);

    //static std::vector<std::vector<int>> listType2(const int size);
    //static std::vector<std::vector<int>> algo(unsigned int n);
public :
    //static std::list<Wall*> laby(unsigned int n);

// STATICS




// ACCESSORS
public :
    MazeCase getCase(const int line, const int column) const;

    std::list<Wall*> getWallsList() const;

};



#endif /* defined(__Console__Maze__) */
