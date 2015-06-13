//
//  Wall.h
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __Console__Wall__
#define __Console__Wall__

#include <stdio.h>
#include "GraphicsElement.h"

class Wall : public GraphicElement {
private:
    char _orientation ;
    
public:
    Wall();
    
    
private:
    void init();
};


#endif /* defined(__Console__Wall__) */
