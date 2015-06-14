//
//  Trace.h
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __Console__Trace__
#define __Console__Trace__

#include <stdio.h>
#include "GraphicsElement.h"

class Trace : public GraphicElement
{
private:
    unsigned int _life;
    std::string _direction;

public:
    Trace(const std::string direction, const unsigned int X, const unsigned int Y);

    void looseLife();

// ACCESSORS
public:
    std::string getDirection() const;



};


#endif /* defined(__Console__Trace__) */
