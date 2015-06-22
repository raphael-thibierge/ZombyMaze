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
    bool _gunAvalaible;
    sf::Time _fireRateTime;
    sf::Clock _fireRate;
    
    
public:
    
    void autoMove();
    
    void chooseDirection(const std::string direction);
    
    Player();
    
    void reset();
    
    bool canShoot();
    

// ACCESSORS
    void setMoving(const bool moving);

    bool getMoving() const;
    
    bool getGun();
    
    void setGun(bool available);
    
    
};

#endif /* defined(__Console__Player__) */
