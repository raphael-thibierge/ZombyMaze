//
//  GameModel.cpp
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "GameModel.h"

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
            delete enemy;
        enemy = nullptr;
    }
    _enemiesList.clear();
    
    // trace destruction
    for (Trace* trace : _traceList)
    {
        if  (trace != nullptr)
            delete trace;
        trace = nullptr;
    }
}


void GameModel::nextStep()
{
    _player.Move();

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
}

