//
//  Player.h
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __Console__Player__
#define __Console__Player__

#include <stdio.h>
#include "Perso.h"
#include "Trace.h"
#include "Maze.h"

class Player : public Perso
{
private:
    bool _isMoving;
    
    
public:
    
    void autoMove();
    
    void chooseDirection(const std::string direction);
    
    Player();
    
    void reset();

    

// ACCESSORS
    void setMoving(const bool moving);

    bool getMoving() const;
    
    
};

#endif /* defined(__Console__Player__) */
