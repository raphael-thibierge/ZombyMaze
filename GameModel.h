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
#include "Bullet.h"
#include "Level.h"

class GameModel
{
private:
    Player _player;
    Level _level;
    
    
// stats

public:
    GameModel();

    ~GameModel();

// METHODS
public:
    void nextStep();

    void playerMove(const std::string direction);
    
    void reset();
    
    void playerShoot(const std::string direction);
    


private:
    
    
    void clear();
    


    
    
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
    
    std::list<Bullet*> * getBulletList();
    
    std::list<MazeCase*> * getMazeCaseList();
    
    Player* getPlayer();
    
    Maze * getMaze() ;
    
    void setPlayStop();
    
    
    

};

#endif /* defined(__Console__GameModel__) */
