//
//  MazeCase.h
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __Console__MazeCase__
#define __Console__MazeCase__

#include <stdio.h>
#include "MovableElement.h"
#include "Trace.h"
#include "Coin.h"
class MazeCase : public GraphicElement
{
// ATTRIBUTES
private:
    std::vector<bool> _walls;
    std::map<std::string, MazeCase*> _nextMazeCase;
    
    Trace _trace;
    
// CONSTRUCTOR & DESTRUCTOR
public:
    MazeCase();
    
    ~MazeCase();
    
// METHODS
public:
    void newTrace(const std::string direction, const std::string owner);
    
    void addWall(const unsigned sideNumber);
    
    void addNextMazeCase(MazeCase * mazeCase,const std::string direction);

    std::vector<std::string> getAvalaibleDirecton() const;

    void clear();
    
    void SetPosition(const unsigned int x, const unsigned y);
    
    void place(GraphicElement* element) const;
    
    bool isAvailableDirection(std::string direction);
    
    
private:
    void init();
    


    
// ACCESSORS
public:
    bool isWall(const std::string direction) const;

    Trace* getTrace();
    
    
    
    MazeCase* getNextMazeCase(const std::string direction) ;

};

#endif /* defined(__Console__MazeCase__) */
