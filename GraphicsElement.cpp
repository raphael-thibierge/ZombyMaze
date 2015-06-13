//
//  GraphicsElement.cpp
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "GraphicsElement.h"


GraphicElement::GraphicElement()
{
    
}


void GraphicElement::setPosition(const unsigned int positionX, const unsigned int positionY)
{
    _X = positionX;
    _Y = positionY;
}

void GraphicElement::setX(const unsigned int positionX)
{
    _X = positionX;
}

void GraphicElement::setY(const unsigned int positionY)
{
    _Y = positionY;
}

unsigned int GraphicElement::getX() const
{
    return _X;
}

unsigned int GraphicElement::getY() const
{
    return _Y;
}

unsigned int GraphicElement::getWidth() const
{
    return _widht;
}

unsigned int GraphicElement::getHeight() const
{
    return _height;
}