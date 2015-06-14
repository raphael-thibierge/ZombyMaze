//
//  GameModel.cpp
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "GameModel.h"

using namespace std;

GameModel::GameModel()
{
    init();
}

GameModel::~GameModel()
{
    // LISTS DESTRUCTION
    // enemies destruction
    for (Enemy * enemy : _enemiesList)
    {
        if (enemy != nullptr)
        {
            delete enemy;
            enemy = nullptr;
        }
    }
    _enemiesList.clear();

    // trace destruction
    for (Trace* trace : _tracesList)
    {
        if  (trace != nullptr)
        {
            delete trace;
            trace = nullptr;
        }

    }

    // wall destruction
    for (Wall* wall : *_wallsList)
    {
        if (wall != nullptr)
        {
            delete wall;
            wall = nullptr;
        }
    }
}


void GameModel::nextStep()
{
    _player.setMoving(false);

    enemiesCheckTraces();

    moveAllEnemies();

    if (enemiesCollision())
    {
        _playerLoose = true;
        cout << "You loose" << endl;
    }

}


void GameModel::playerMove(std::string direction)
{
    _player.setDirection(direction);
    
    MovableElement element = _player;
    element.Move();
    
    if (!Wall::wallsCollision(&element, _wallsList) ||
        element.getX() <= 0 || (element.getX() + element.getWidth()) >= WINDOW_WIDTH ||
        element.getY() <= 0 || (element.getY() + element.getHeight()) >= WINDOW_HEIGHT
        )
    {
        _player.Move();
        _tracesList.push_back(_player.getTrace());
        
    }
        
    

}


void GameModel::moveAllEnemies()
{
    for (Enemy* enemy : _enemiesList)
    {
        enemy->autoMove(_wallsList);
    }
}

bool GameModel::enemiesCollision()
{
    for (Enemy* enemy : _enemiesList)
    {
        if (_player.ElementOnElement(enemy))
        {
            return true;
        }
    }
    return false;
}


void GameModel::enemiesCheckTraces()
{
    for (Enemy* enemy : _enemiesList)
    {
        enemy->findTrace(&_tracesList);
    }
}

void GameModel::init()
{
    // init states
    _playerWin = false;
    _playerLoose = false;

    // init player position
    _player.setPosition(PLAYER_INITIAL_X, PLAYER_INITIAL_Y);

    // add an enemy
    _enemiesList.push_back(new Enemy);
    for (Enemy* enemy : _enemiesList)
    {
        enemy->setPosition(220,200);
    }

    // add walls
    _wallsList = _maze.getWallsList();

}

list<Enemy*> * GameModel::getEnemiesList()
{
    return &_enemiesList;
}

list <Trace*> * GameModel::getTracesList()
{
    return &_tracesList;
}

list<Wall *> * GameModel::getWallsList()
{
    return _wallsList;
}

Player* GameModel::getPlayer()
{
    return &_player;
}
