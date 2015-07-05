//
//  BackgroundElement.cpp
//  ZombyMaze2
//
//  Created by Raphael Thibierge on 19/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "BackgroundElement.h"

using namespace std;

BackgroundElement::BackgroundElement(std::string name) : GraphicElement()
{
    _name = name;
}

const std::string BackgroundElement::getName() const
{
    return _name;
}