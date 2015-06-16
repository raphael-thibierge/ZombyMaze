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
    std::string _owner;

public:

    Trace(const std::string direction, const std::string owner, const unsigned int X, const unsigned int Y);

    void looseLife();

// ACCESSORS
public:
    std::string getDirection() const;
    
    std::string getOwner() const;
    
    void setDirection(std::string direction);



};


#endif /* defined(__Console__Trace__) */
