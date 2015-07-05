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
#include "PowerUp.h"
#include "BackgroundElement.h"
#include <iostream>
#include <fstream>

class Maze : public GraphicElement
{
// ATTRIBUTES
private:
    std::vector<std::vector<MazeCase>> _grid;
    std::list<Wall*> _wallList;
    std::list<Trace*> _traceList;
    std::list<MazeCase*> _mazeCaseList;
    std::list<PowerUp*> _powerUpList;
    std::list<BackgroundElement> _backgroundElementList;
    unsigned int _nbEnnemies;
    unsigned int _size ;
    std::string _fileName;

// CONTRUCTOR AND DESTRUCTOR
public:
    Maze(const unsigned int number);
    
    ~Maze();

// METHODS
public:
    void clearTraceList();
    
    void clear();
    
    void reset();
    
private:
    void init();

    void construct();

    void addWall(unsigned int x, unsigned int y, const char orientation);
    
    void updateNextMazeCases();


// ACCESSORS
public :
    MazeCase getCase(const int line, const int column) const;

    std::list<Wall*> * getWallsList();
    
    std::list<Trace*> * getTraceList();
    
    std::list<MazeCase*> * getMazeCaseList();
    
    std::list<PowerUp *> *getPowerUpList();
    
    std::list<BackgroundElement> *getBackgroundElementlist();
    
    unsigned int getSize() const;
    
    MazeCase* getMazeCase(const unsigned int line, const unsigned int column);
    
    unsigned int getNbEnnemies() const
    {
        return _nbEnnemies;
    }

};



#endif /* defined(__Console__Maze__) */
