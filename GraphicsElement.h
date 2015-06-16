//
//  GraphicsElement.h
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __Console__GraphicsElement__
#define __Console__GraphicsElement__

#include "const.h"

class GraphicElement {
protected:
    unsigned int _width;
    unsigned int _height;
    unsigned int _X;
    unsigned int _Y;
    

// CONSTRUCTOR
public:
    GraphicElement();

// METHODS
public:
    bool pointOnElement(const unsigned int positionX, const unsigned int positionY) const;
    
    bool ElementOnElement(GraphicElement* element) const;
    
    bool contain(GraphicElement* element) const;
    
    std::string toString();
    
// ACCESSORS
    void setX(const unsigned int positionX);
    
    void setY(const unsigned int positionY);
    
    void setPosition(const unsigned int positionX, const unsigned int positionY);
    
    unsigned int getX() const;
    
    unsigned int getY() const;
    
    unsigned int getWidth() const;
    
    unsigned int getHeight() const;
    
};

#endif /* defined(__Console__GraphicsElement__) */
