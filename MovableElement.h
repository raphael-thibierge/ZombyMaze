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
    void Move();

    void Move(std::string direction);
    
    void MoveOpposite();
    
    void MoveOpposite(std::string);
    
// STATICS
public:
    static bool isDirection(const std::string direcion);
    
    static unsigned int directionToInt(const std::string direction);
    
    static std::string intToDirection(const unsigned int direction);
    

// ACCESSORS
public:

    void setDirection(const std::string direction);

    void setSpeed(const unsigned int speed);

    std::string getDirection() const;

    unsigned int getSpeed() const;

};

#endif /* defined(__Console__MovableElement__) */
