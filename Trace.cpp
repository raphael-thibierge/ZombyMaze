//
//  Trace.cpp
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "Trace.h"

using namespace std;

Trace::Trace(string direction) : GraphicElement(), _direction(direction)
{
    
}

string Trace::getDirection() const
{
    return _direction;
}