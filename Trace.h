//
//  Trace.h
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __Console__Trace__
#define __Console__Trace__

#include <stdio.h>
#include "MovableElement.h"

class Trace : public GraphicElement
{
private:
    std::string _direction;
    std::string _owner;
    sf::Time _lifeTime;
    sf::Time _life;
    sf::Clock _time;
    //sf::time;
    
// states
    bool _available;
    

public:

    Trace();
    
    const bool available() const;
    
    void newTrace(const std::string direction, const std::string owner);
    
    void deleteTrace();
    
   
// ACCESSORS
public:
    const std::string getDirection() const;
    
    const std::string getOwner() const;
    
    void update();
    
    void setDirection(std::string direction);
    
    void setPlayPause();


};


#endif /* defined(__Console__Trace__) */
