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
#include "GraphicsElement.h"
class MazeCase : protected GraphicElement{
    
private:
    std::vector<bool> _walls;
    
    
public:
    MazeCase(const unsigned int line, const unsigned int column);
    
private:
    void init();
    
// ACCESSORS
public:
    bool isWall(std::string direction) const;
    
};

#endif /* defined(__Console__MazeCase__) */
