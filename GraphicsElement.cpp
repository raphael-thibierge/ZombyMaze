//
//  GraphicsElement.cpp
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "GraphicsElement.h"

//
// CONSTRUCTOR
//
GraphicElement::GraphicElement()
{
    
}

//
// METHODS
//

bool GraphicElement::pointOnElement(const unsigned int positionX, const unsigned int positionY) const
{
    return ( positionX >= _X && positionX <= _X + _width
            && positionY >= _Y && positionY <= _Y + _height);
}

bool GraphicElement::ElementOnElement(GraphicElement *element) const
{
    unsigned int eX = element->getX();
    unsigned int eY = element->getY();
    unsigned int eWidth = element->getWidth();
    unsigned int eHeight = element->getHeight();
    
    return ((element->pointOnElement(eX, eY) ||
             element->pointOnElement(eX, eY + eHeight) ||
             element->pointOnElement(eX + eWidth, eY) ||
             element->pointOnElement(eX + eWidth, eY + eHeight))
            
        || (element->pointOnElement(_X, _Y) ||
            element->pointOnElement(_X, _Y + _height) ||
            element->pointOnElement(_X + _width, _Y) ||
            element->pointOnElement(_X + _width, _Y + _height)));
}


//
// ACCESSORS
//
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
    return _width;
}

unsigned int GraphicElement::getHeight() const
{
    return _height;
}