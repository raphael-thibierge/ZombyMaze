//
//  Coin.h
//  ZombyMaze2
//
//  Created by Raphael Thibierge on 17/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __ZombyMaze2__Coin__
#define __ZombyMaze2__Coin__

#include <stdio.h>
#include "GraphicsElement.h"

class Coin : public GraphicElement
{
private:
    unsigned int _value;
    
public:
    Coin(const unsigned int value, const unsigned int x, const unsigned int y);

// ACCESSORS
    const unsigned int getValue() const;
    
    void setValue(const unsigned int value);

};

#endif /* defined(__ZombyMaze2__Coin__) */
