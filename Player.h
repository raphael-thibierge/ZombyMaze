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
    sf::Clock _time;
    
    // gun bonnus
    bool _gunAvalaible;
    sf::Time _fireRateTime;
    sf::Clock _fireRate;
    unsigned int _nbAmmo;
    
    // speed bonnus
    bool _boostAvalaible;
    bool _boostActivated;
    sf::Time _boostTime;
    
    
    // shield bonnus
    bool _shieldAvalaible;
    bool _shieldActivated;
    sf::Time _shieldTime;
    
    // other
    unsigned int _level;
    unsigned int _theme;
    
public:
    
    Player();
    
    void autoMove();
    
    void chooseDirection(const std::string direction);
    
    void reset();
    
    const bool canShoot();
    
    void useAmmo();
    
    void useBoost();
    
    void useShield();
    
    void nextLevel();
    
    void update();
    
    void addAmmo(const unsigned int number);
    
    void save();
    
    void load();
    

// ACCESSORS
public:
    // GETTERS
    const bool getMoving() const;
    
    const bool getGun();
    
    const bool getShieldActivated() const;
    
    const bool getShield() const;
    
    const sf::Time getShieldTime() const
    {
        return _shieldTime;
    }
    
    const bool getBoost() const;
    
    const bool getBoostActivated() const
    {
        return _boostActivated;
    }
    
    const sf::Time getBoostTime() const
    {
        return _boostTime;
    }
    
    const unsigned int getTheme() const;
    
    const unsigned int getAmmo() const;
    
    const unsigned int getLevel() const;
    
    // SETTERS
    void setMoving(const bool moving);
    
    void setTheme(const unsigned int theme);
    
    void setGun(bool available);

    void setBoost(const bool boost);
    
    void setShield(const bool shield);
    
};

#endif /* defined(__Console__Player__) */
