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
    std::list<Wall*> * _wallsList;
// stats
    bool _playerLoose;
    bool _playerWin;
    bool _play;

public:
    GameModel();

    ~GameModel();

// METHODS
public:
    void nextStep();

    void playerMove(std::string direction);
    
    void reset();

private:

    bool enemiesCollision();

    void moveAllEnemies();

    void enemiesCheckTraces();
    
    void updateMazeCasePosition();
    
    bool successOutOfMaze();


private :
    void init();

// ACCESSORS
public:
    
    bool getLoose() const;
    
    bool getWin() const;
    
    bool getPlayStop() const;

    std::list<Enemy*> * getEnemiesList();

    std::list<Trace *> * getTracesList();

    std::list<Wall *> * getWallsList();
    
    Player* getPlayer();
    
    Maze * getMaze() ;
    
    void setPlayStop();
    
    
    

};

#endif /* defined(__Console__GameModel__) */
