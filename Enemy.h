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
#include "Perso.h"
#include "Trace.h"
#include "Wall.h"


class Enemy : public Perso
{
private:
    unsigned int _life;
    
    // states
    bool _traceFound;
    bool _playerFound;


public:
    Enemy();

    void autoMove();
    
    void changeDirection();

    void traceFound(std::string _direction);
    
    void traceLoose();    

private:
    void init();

};

#endif /* defined(__Console__Enemy__) */
