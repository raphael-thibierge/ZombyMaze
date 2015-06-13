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


public:

    MovableElement();

    void Move();

    void Move(std::string direction);

// ACCESSORS
public:

    void setDirection(const std::string direction);

    void setSpeed(const unsigned int speed);

    std::string getDirection() const;

    unsigned int getSpeed() const;

};

#endif /* defined(__Console__MovableElement__) */
