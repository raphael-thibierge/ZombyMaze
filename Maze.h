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

class Maze : public GraphicElement
{

private:
    std::vector<std::vector<MazeCase*> > _grid;
    unsigned int _size ;

public:

    Maze();

private:

    void init();


    void addWall(unsigned int line, unsigned int column, const std::string orientation);


// STATICS
public:
    static Maze MazeLevel1();


// ACCESSORS
public :
    MazeCase getCase(const int line, const int column) const;

};



#endif /* defined(__Console__Maze__) */
