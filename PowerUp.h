//
//  PowerUp.h
//  ZombyMaze2
//
//  Created by Raphael Thibierge on 19/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __ZombyMaze2__PowerUp__
#define __ZombyMaze2__PowerUp__

#include <stdio.h>
#include "GraphicsElement.h"

class PowerUp : public GraphicElement {
    std::string _name;
    
public:
    
    PowerUp(std::string name);
    
    // ACCESSORS
public:
    std::string getName() const;
};


#endif /* defined(__ZombyMaze2__PowerUp__) */
