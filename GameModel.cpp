//
//  GameModel.cpp
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "GameModel.h"

using namespace std;

//
// CONSTRUCTOR & DESTRUCTOR
GameModel::GameModel()
{
    init();
    _gameStart = false;
}

void GameModel::init()
{
    _level.setPlayer(&_player);
    _level.init();
    
}

GameModel::~GameModel()
{
    clear();
}


//
// METHODS
//

// PUBLIC

void GameModel::nextStep()
{
    if (!_level.getLevelEnd())
        _level.runGame();
    
}


void GameModel::playerMove(const std::string direction)
{
    _player.chooseDirection(direction);

}

void GameModel::reset()
{
    _level.reset();
}

void GameModel::playerShoot(const string direction)
{
    _level.playerShoot(direction);
}



// PRIVATE

void GameModel::clear()
{
    // LISTS DESTRUCTION
    _level.clear();
}

void GameModel::newLevel()
{
    _level.reset();
}



//
// ACCESSORS
//

list<Enemy*> * GameModel::getEnemiesList()
{
    return _level.getEnemies();
}

list <Trace*> * GameModel::getTracesList()
{
    return _level.getTraces();
}

list<Wall *> * GameModel::getWallsList()
{
    return _level.getWalls();
}

list<MazeCase*> * GameModel::getMazeCaseList()
{
    return _level.getMazeCases();
}

list<Bullet *> * GameModel::getBulletList()
{
    return _level.getBullets();
}

Player* GameModel::getPlayer()
{
    return &_player;
}

Maze* GameModel::getMaze()
{
    return _level.getMaze();
}



bool GameModel::getPlayStop() const
{
    return _level.getPlayStop();
}

bool GameModel::getWin() const
{
    return _level.getWin();
}

bool GameModel::getLoose() const
{
    return _level.getLoose();
}

void GameModel::setPlayStop()
{
    _level.setPlayStop();
}

std::list<PowerUp*> * GameModel::getPowersUp()
{
    return _level.getMaze()->getPowerUpList();
}

std::list<BackgroundElement> * GameModel::getBackgroundElements()
{
    return _level.getMaze()->getBackgroundElementlist();
}