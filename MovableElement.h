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


class MovableElement : protected GraphicElement {
protected:
    
    std::string _direction;
    unsigned int _speed;
    
    
public:
    
    MovableElement();
    
    void Move();
    
};

#endif /* defined(__Console__MovableElement__) */
