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
    _enemiesList.clear();
    _enemiesList.push_back(new Enemy);
    for (Enemy* enemy : _enemiesList)
    {
        enemy->setPosition(210,200);
    }
    
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
        _player.setMoving(false);
        
        updateMazeCasePosition();
        
        enemiesCheckTraces();
        
        moveAllEnemies();
        
        moveAllBullets();
        
        bulletCollision();
        
        if (enemiesCollision())
        {
            _playerLoose = true;
        }
        _playerWin = successOutOfMaze();
        
        if (_playerLoose)
        {
            cout << "loose !" << endl;
            setPlayStop();
        }
        else if (_playerWin)
        {
            cout << "win !" << endl;
            setPlayStop();
        }
        
    }
    
}


void GameModel::playerMove(const std::string direction)
{
    if (_player.getMazeCase() != nullptr && MovableElement::isDirection(direction) )
    {
        for (string value : _player.getMazeCase()->getAvalaibleDirecton())
        {
            if (direction == value)
            {
                _player.setDirection(direction);
            }
        }
    }

    MovableElement element = _player;
    element.Move();

    if (!Wall::wallsCollision(&element, getWallsList()) ||
        element.getX() <= 0 || (element.getX() + element.getWidth()) >= WINDOW_WIDTH ||
        element.getY() <= 0 || (element.getY() + element.getHeight()) >= WINDOW_HEIGHT
        )
    {
        _player.Move();
    }



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
        bullet->move();
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
    
    for (Bullet * bullet : _bulletsList)
    {
        if (bullet != nullptr)
        {
            delete bullet;
            bullet = nullptr;
        }
    }
    _bulletsList.clear();
    
    
    // TRACE DESTRUCTION
    
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