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
}

void GameModel::init()
{
    // init states
    _playerWin = false;
    _playerLoose = false;
    _play = false;
    
    // init player position
    _player.setPosition(PLAYER_INITIAL_X, PLAYER_INITIAL_Y);
    // add an enemy
    generateEnemies();
    updateMazeCasePosition();
    
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
    if (_play)
    {
        movementManager();
        
        collisionManager();
        
        // enemiesCheckTraces();
        
        if (enemiesCollision())
        {
            _playerLoose = true;
        }
        _playerWin = successOutOfMaze();
        
        if (_playerLoose)
        {
            setPlayStop();
        }
        else if (_playerWin)
        {
            setPlayStop();
        }
        
    }
    
}


void GameModel::playerMove(const std::string direction)
{
    _player.chooseDirection(direction);

}

void GameModel::reset()
{
    clear();
    init();
}

void GameModel::playerShoot(const string direction)
{
    if (MovableElement::isDirection(direction))
    {
        _bulletsList.push_back(_player.getShoot(direction));
    }
}

// PRIVATE
void GameModel::movementManager()
{
    _player.autoMove() ;
    moveAllEnemies();
    moveAllBullets();
}

void GameModel::collisionManager()
{
    bulletCollision();
    
}


void GameModel::moveAllEnemies()
{
    for (Enemy* enemy : _enemiesList)
    {
        enemy->autoMove();
    }
}

void GameModel::moveAllBullets()
{
    for (Bullet* bullet : _bulletsList)
    {
        bullet->autoMove();
    }
}

bool GameModel::enemiesCollision()
{
    list<Enemy*> enemiesToDestroy;
    bool returnValue = false;
    for (Enemy* enemy : _enemiesList)
    {
        if (_player.ElementOnElement(enemy))
        {
            returnValue = true;
            enemiesToDestroy.push_back(enemy);
        }
        else if (!_maze.contain(enemy))
        {
            enemiesToDestroy.push_back(enemy);
        }
    }
    
    for (Enemy* enemy : enemiesToDestroy)
    {
        _enemiesList.remove(enemy);
        if (enemy != nullptr)
            delete enemy;
        enemy = nullptr;
    }
    enemiesToDestroy.clear();
    return returnValue;
}

void GameModel::bulletCollision()
{
    list<Bullet*> _bulletToDestroy;
    list<Enemy*> _enemiesToDestroy;
    
    for (Bullet * bullet : _bulletsList)
    {
        
        for (Enemy* enemy : _enemiesList)
        {
            if (enemy->ElementOnElement(bullet))
            {
                // affect damage to the enemy
                enemy->affectDamage(bullet->getDamage());
                if (enemy->getDead())
                {
                    if (enemy->getMazeCase() != nullptr)
                        enemy->getMazeCase()->addCoin();
                    _enemiesToDestroy.push_back(enemy);
                }
                _bulletToDestroy.push_back(bullet);
            }
        }
        
        for (Wall* wall : *getWallsList())
        {
            if (wall->ElementOnElement(bullet))
            {
                _bulletToDestroy.push_back(bullet);
            }
        }
         
    }
    
    _bulletToDestroy.unique();
    _enemiesToDestroy.unique();
    
    for (Enemy* enemy : _enemiesToDestroy)
    {
        _enemiesList.remove(enemy);
        if (enemy != nullptr)
        {
            delete enemy;
            enemy = nullptr;
        }
    }
    
    for (Bullet* bullet : _bulletToDestroy)
    {
        _bulletsList.remove(bullet);
        if (bullet != nullptr)
        {
            delete bullet;
            bullet = nullptr;
        }
    }
    
    _enemiesToDestroy.clear();
    _bulletToDestroy.clear();
}

void GameModel::enemiesCheckTraces()
{
    for (Enemy* enemy : _enemiesList)
    {
        enemy->findTrace(getTracesList());
    }
}

void GameModel::updateMazeCasePosition()
{
    // player
    _player.updateMazeCase(getMazeCaseList());
    
    // enemies
    for (Enemy* enemy : _enemiesList)
    {
        enemy->updateMazeCase(getMazeCaseList());
    }
}

bool GameModel::successOutOfMaze()
{
    return !_maze.ElementOnElement(&_player);
}

void GameModel::clear()
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
    
    // bullets destruction
    for (Bullet * bullet : _bulletsList)
    {
        if (bullet != nullptr)
        {
            delete bullet;
            bullet = nullptr;
        }
    }
    _bulletsList.clear();
    _player.reset();
    
    
    // traces destruction
    for (Trace* trace : *getTracesList())
    {
        trace->deleteTrace();
    }
    
}

void GameModel::spawnRandomEnemy()
{
    unsigned int randomLine;
    unsigned int randomColumn;
    do
    {
        randomLine = rand() % _maze.getSize();
        randomColumn = rand() % _maze.getSize();
    } while (randomLine < 2 && randomColumn < 2);
    
    
    
    Enemy * enemy = new Enemy();
    enemy->setMazeCase(_maze.getMazeCase(randomLine, randomColumn));
    enemy->getMazeCase()->place(enemy);
    _enemiesList.push_back(enemy);
    enemy = nullptr;
}

void GameModel::generateEnemies()
{
    for (unsigned int i = 0 ; i < ENEMIES_MAX ; i++)
    {
        spawnRandomEnemy();
    }
}



//
// ACCESSORS
//

list<Enemy*> * GameModel::getEnemiesList()
{
    return &_enemiesList;
}

list <Trace*> * GameModel::getTracesList()
{
    return _maze.getTraceList();
}

list<Wall *> * GameModel::getWallsList()
{
    return _maze.getWallsList();
}

list<MazeCase*> * GameModel::getMazeCaseList()
{
    return _maze.getMazeCaseList();
}

list<Bullet *> * GameModel::getBulletList()
{
    return &_bulletsList;
}

Player* GameModel::getPlayer()
{
    return &_player;
}

Maze* GameModel::getMaze()
{
    return &_maze;
}

void GameModel::setPlayStop()
{
    _play = !_play;
}

bool GameModel::getPlayStop() const
{
    return _play;
}

bool GameModel::getWin() const
{
    return _playerWin;
}

bool GameModel::getLoose() const
{
    return _playerLoose;
}