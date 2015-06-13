//
//  Enemy.h
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __Console__Enemy__
#define __Console__Enemy__

#include <stdio.h>
#include "MovableElement.h"

class Enemy : public MovableElement
{
private:
    unsigned int _life;
    bool _traceFound;
    

    
public:
    void autoMove();
    
    void traceFound(std::string _direction);
    
private:
    void init();

};

#endif /* defined(__Console__Enemy__) */
