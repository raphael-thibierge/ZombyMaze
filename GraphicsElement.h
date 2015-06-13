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
    unsigned int _widht;
    unsigned int _height;
    unsigned int _X;
    unsigned int _Y;
    
    
public:
    GraphicElement();
    
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
