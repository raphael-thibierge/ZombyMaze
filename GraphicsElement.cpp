//
//  GraphicsElement.cpp
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "GraphicsElement.h"

using namespace std;
//
// CONSTRUCTOR
//
GraphicElement::GraphicElement()
{
    _X = 1;
    _Y = 1;
    _width = 1;
    _height = 1;
}

//
// METHODS
//

const bool GraphicElement::pointOnElement(const unsigned int positionX, const unsigned int positionY) const
{
    return ( positionX >= _X && positionX <= _X + _width
            && positionY >= _Y && positionY <= _Y + _height);
}

const bool GraphicElement::ElementOnElement(GraphicElement *element) const
{
    unsigned int eX = element->getX();
    unsigned int eY = element->getY();
    unsigned int eWidth = element->getWidth();
    unsigned int eHeight = element->getHeight();

    return ((pointOnElement(eX, eY) ||
             pointOnElement(eX, eY + eHeight) ||
             pointOnElement(eX + eWidth, eY) ||
             pointOnElement(eX + eWidth, eY + eHeight))

        || (element->pointOnElement(this->_X, this->_Y) ||
            element->pointOnElement(_X, _Y + _height) ||
            element->pointOnElement(_X + _width, _Y) ||
            element->pointOnElement(_X + _width, _Y + _height)));
}

const bool GraphicElement::contain(GraphicElement *element) const
{
    unsigned int eX = element->getX();
    unsigned int eY = element->getY();
    unsigned int eWidth = element->getWidth();
    unsigned int eHeight = element->getHeight();
    //cout << &element << " " << eX << " " << eY  << " " << eWidth << " " << eHeight << endl;
        
    return ((pointOnElement(eX, eY) &&
            pointOnElement(eX, eY + eHeight) &&
            pointOnElement(eX + eWidth, eY) &&
            pointOnElement(eX + eWidth, eY + eHeight)));
}

const string GraphicElement::toString()
{
    string text = "X=" + to_string(_X);
    text += " Y=" + to_string(_Y);
    text += " Width=" + to_string(_width);
    text += " Height=" + to_string(_height) + " / ";
    return text;
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

void GraphicElement::setSize(const unsigned int widht, const unsigned int height)
{
    _width = widht;
    _height = height;
}

const unsigned int GraphicElement::getX() const
{
    return _X;
}

const unsigned int GraphicElement::getY() const
{
    return _Y;
}

const unsigned int GraphicElement::getWidth() const
{
    return _width;
}

const unsigned int GraphicElement::getHeight() const
{
    return _height;
}

const unsigned int GraphicElement::getSurface() const
{
    return _width * _height;
}