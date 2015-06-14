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
#include "MovableElement.h"
#include "Trace.h"

class Player : public MovableElement
{
private:
    bool _isMoving;

public:

    void Move(std::string direction = "");

    Player();

    void tryLeaveTrace(std::list<Trace *> * traceList);

// ACCESSORS
    void setMoving(const bool moving);

    bool getMoving() const;

    Trace * getTrace() ;

};

#endif /* defined(__Console__Player__) */
