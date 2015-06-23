//
//  BackgroundElement.h
//  ZombyMaze2
//
//  Created by Raphael Thibierge on 19/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __ZombyMaze2__BackgroundElement__
#define __ZombyMaze2__BackgroundElement__

#include <stdio.h>
#include "GraphicsElement.h"

class BackgroundElement : public GraphicElement
{
    std::string _name;
    
public:
    
    BackgroundElement(std::string name);
    
// ACCESSORS
public:
    std::string getName() const;
};
#endif /* defined(__ZombyMaze2__BackgroundElement__) */
