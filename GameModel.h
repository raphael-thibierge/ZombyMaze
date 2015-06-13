//
//  GameModel.h
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __Console__GameModel__
#define __Console__GameModel__

#include <stdio.h>
#include "Player.h"
#include "Enemy.h"
#include "Maze.h"
#include "Trace.h"
#include "Wall.h"

class GameModel
{
private:
    Maze _maze;
    Player _player;
    std::list<Enemy*> _enemiesList;
    std::list<Trace*> _tracesList;
    std::list<Wall*> _wallsList;

public:
    GameModel();

    ~GameModel();
    
// METHODS

    void nextStep();

    bool wallsCollision(GraphicElement* element);
    
    void playerMove(std::string direction);
    
    
private :
    void init();

// ACCESSORS
public:

    std::list<Enemy*> * getEnemiesList();

    std::list<Trace *> * getTracesList();
    
    std::list<Wall *> * getWallsList();

    Player* getPlayer();
};

#endif /* defined(__Console__GameModel__) */