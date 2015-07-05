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

 
}

GameModel::~GameModel()
{
    _player.save();
    clear();
    if (_level != nullptr)
        delete _level;
    _level = nullptr;
}


//
// METHODS
//

// PUBLIC

void GameModel::nextStep()
{
    if (_level != nullptr && !_level->getLevelEnd())
        _level->runGame();    
}


void GameModel::playerMove(const std::string direction)
{
    _player.chooseDirection(direction);

}

void GameModel::playerShoot(const string direction)
{
    _level->playerShoot(direction);
}

bool GameModel::newGame(const unsigned int level)
{
    if (level == 0)
    {
        _level = new Level(_player.getLevel(), &_player);
        return true;
    }
    else if (level <= _player.getLevel())
    {
        _level = new Level(level, &_player);
        return true;
    }
    return false;
}

void GameModel::nextLevel()
{
    if ( _player.getLevel() < LEVEL_MAX )
        _player.nextLevel();
    _level = new Level(_player.getLevel(), &_player);
}

void GameModel::reset()
{
    if (_level != nullptr)
    {
        unsigned int retry = _level->getRetry();
        unsigned int level =  _level->getLevel();
    
        delete _level;
        _level = new Level(level, &_player);
        _level->setRetry(retry);
        
    }
}


// PRIVATE
void GameModel::clear()
{
    // LISTS DESTRUCTION
    if (_level != nullptr)
        delete _level;
    _level = nullptr;
}


// ============================================
// ============  ACCESSOR METHODS  ============
// ============================================

list<Enemy*> * GameModel::getEnemiesList()
{
    return _level->getEnemies();
}

list <Trace*> * GameModel::getTracesList()
{
    return _level->getTraces();
}

list<Wall *> * GameModel::getWallsList()
{
    return _level->getWalls();
}

list<MazeCase*> * GameModel::getMazeCaseList()
{
    return _level->getMazeCases();
}

list<Bullet *> * GameModel::getBulletList()
{
    return _level->getBullets();
}

Player* GameModel::getPlayer()
{
    return &_player;
}

Maze* GameModel::getMaze()
{
    return _level->getMaze();
}

const bool GameModel::getPlayStop() const
{
    return _level->getPlayStop();
}

const bool GameModel::getWin() const
{
    return _level->getWin();
}

const bool GameModel::getLoose() const
{
    return _level->getLoose();
}

void GameModel::setPlayStop()
{
    _level->setPlayStop();
}

std::list<PowerUp*> * GameModel::getPowersUp()
{
    return _level->getMaze()->getPowerUpList();
}

std::list<BackgroundElement> * GameModel::getBackgroundElements()
{
    return _level->getMaze()->getBackgroundElementlist();
}

Level* GameModel::getLevel()
{
    return _level;
}

