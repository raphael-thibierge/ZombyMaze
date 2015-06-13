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
    for (Wall* wall : _wallsList)
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
    //_player.Move();

}

bool GameModel::wallsCollision(GraphicElement* element)
{
    for (Wall* wall : _wallsList)
    {
        if ( wall->ElementOnElement(element))
            return true;
    }
    return false;
}


void GameModel::playerMove(std::string direction)
{
    GraphicElement * element = &_player;
    
    _player.Move(direction);
    if (wallsCollision(element))
        _player.MoveOpposite(direction);
    
    delete element;
    element = nullptr;
}


void GameModel::init()
{
    // init player position
    _player.setPosition(PLAYER_INITIAL_X, PLAYER_INITIAL_Y);

    // add an enemy
    _enemiesList.push_back(new Enemy);
    for (Enemy* enemy : _enemiesList)
    {
        enemy->setPosition(0,0);
    }
    
    
    // add walls
    _wallsList.push_back(new Wall(rand()%WINDOW_WIDTH, rand()%WINDOW_HEIGHT));
    _wallsList.push_back(new Wall(rand()%WINDOW_WIDTH, rand()%WINDOW_HEIGHT));

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
    return &_wallsList;
}

Player* GameModel::getPlayer()
{
    return &_player;
}
