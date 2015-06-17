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

class MazeCase : public GraphicElement
{
// ATTRIBUTES
private:
    std::vector<bool> _walls;
    Trace* _trace;
    
// CONSTRUCTOR & DESTRUCTOR
public:
    MazeCase(const unsigned int x, const unsigned int y);
    
    ~MazeCase();
    
// METHODS
public:
    void newTrace(const std::string direction, const std::string owner);
    
    void addWall(const unsigned sideNumber);

    std::vector<std::string> getAvalaibleDirecton() const;
    
private:
    void init();
    


    
// ACCESSORS
public:
    bool isWall(const std::string direction) const;

    Trace* getTrace() const;
    
    Trace** getTracePointer();
};

#endif /* defined(__Console__MazeCase__) */
