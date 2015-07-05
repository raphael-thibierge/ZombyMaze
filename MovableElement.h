//
//  MovableElement.h
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __Console__MovableElement__
#define __Console__MovableElement__

#include <stdio.h>
#include "GraphicsElement.h"


class MovableElement : public GraphicElement {
protected:

    std::string _direction;
    unsigned int _speed;

//CONSTRUCTOR & DESTRUCTOR
public:
    MovableElement();
    
// METHODS
public:

    void move(std::string direction = "");
    
    void moveOpposite(std::string directon = "");
    
// STATICS
public:
    static const bool isDirection(const std::string direction);
    
    static const unsigned int directionToInt(const std::string direction);
    
    static const std::string intToDirection(const unsigned int direction);
    
    static const std::string oppositeDirection(std::string direction);
    

// ACCESSORS
public:

    void setDirection(const std::string direction);

    void setSpeed(const unsigned int speed);

    const std::string getDirection() const;

    const unsigned int getSpeed() const;

};

#endif /* defined(__Console__MovableElement__) */
