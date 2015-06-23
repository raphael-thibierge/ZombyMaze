#include "Level.h"

//
// CONSTRUCTOR  AND DESTRUCTOR
//

using namespace std;

Level::Level ()
{
    
    _nbEnnemies = ENEMIES_MAX;
}


void Level::init()
{
    
    // init states
    _playerWin = false;
    _playerLoose = false;
    
    //_level = level;
    
    _enemiesCpt = 0;
    // init player position
    _player->setPosition(PLAYER_INITIAL_X, PLAYER_INITIAL_Y);
    _player->setMazeCase(nullptr);
    _player->setMoving(false);
    // add an enemy
    generateEnemies();
    
    updateMazeCasePosition();
    
    updateTraces();
    
    _chrono.restart();
    
}


Level::~Level ()
{
    for(auto enemy : _enemiesList)
        delete enemy;
    _enemiesList.clear();
    
    for(auto bullet : _bulletsList)
        delete bullet;
    _bulletsList.clear();
    
    _player = nullptr;
    _difficulty = nullptr;
    
}


//
// METHODS
//
// construct and run game

void Level::runGame()
{
    
    if (_play)
    {
        movementManager();
        
        collisionManager();
        
        updateTraces();
        
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

// ===========   MOVEMENTS
//
void Level::movementManager()
{
    _player->autoMove() ;
    moveAllEnemies();
    moveAllBullets();
}

void Level::collisionManager()
{
    bulletCollision();
    powerUpCollision();
    coinCollision();
}


void Level::moveAllEnemies()
{
    for (Enemy* enemy : _enemiesList)
    {
        enemy->autoMove();
    }
}

void Level::moveAllBullets()
{
    for (Bullet* bullet : _bulletsList)
    {
        bullet->autoMove();
    }
}


// ==============  COLLISISION

bool Level::enemiesCollision()
{
    list<Enemy*> enemiesToDestroy;
    bool returnValue = false;
    for (Enemy* enemy : _enemiesList)
    {
        if (_player->ElementOnElement(enemy))
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

void Level::bulletCollision()
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
                    _coinList.push_back(new Coin(1, enemy->getX(), enemy->getY()));
                    _enemiesToDestroy.push_back(enemy);
                }
                _bulletToDestroy.push_back(bullet);
            }
        }
        
        for (Wall* wall : *getWalls())
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

void Level::powerUpCollision()
{
    for (PowerUp* powerUp : *_maze.getPowerUpList())
    {
        
        if (powerUp->getAvailable() && powerUp->ElementOnElement(_player))
        {
            if ( powerUp->getName() == "gun")
            {
                _player->setGun(true);
                _player->addAmmo(GUB_AMMO);
                powerUp->setAvailable(false);
            }
        }
    }

}

void Level::coinCollision()
{
    list<Coin*> toDestroy;
    for (Coin* coin : _coinList)
    {
        if (coin->ElementOnElement(_player))
        {
            _player->addMoney(coin->getValue());
            toDestroy.push_back(coin);
        }
    }
    for (auto coin : toDestroy)
    {
        _coinList.remove(coin);
        if (coin != nullptr)
        {
            delete coin;
            coin = nullptr;
        }
    }
    toDestroy.clear();
}


// UPDATE OBJETCS
void Level::updateMazeCasePosition()
{
    // player
    _player->updateMazeCase(getMazeCases());
    
    // enemies
    for (Enemy* enemy : _enemiesList)
    {
        enemy->updateMazeCase(getMazeCases());
    }
}

void Level::updateTraces()
{
    for (auto trace : *getTraces())
    {
        trace->update();
    }
}


bool Level::successOutOfMaze()
{
    return !_maze.ElementOnElement(_player);
}

void Level::spawnRandomEnemy()
{
    unsigned int randomLine;
    unsigned int randomColumn;
    do
    {
        randomLine = rand() % (_maze.getSize()-1);
        randomColumn = rand() % (_maze.getSize()-1);
    } while (randomLine < 2 && randomColumn < 2);
    
    
    
    Enemy * enemy = new Enemy();
    enemy->setMazeCase(_maze.getMazeCase(randomLine, randomColumn));
    enemy->getMazeCase()->place(enemy);
    _enemiesList.push_back(enemy);
    enemy = nullptr;
}

void Level::generateEnemies()
{
    for (unsigned int i = 0 ; i < ENEMIES_MAX ; i++)
    {
        spawnRandomEnemy();
    }
}


void Level::playerShoot(const std::string direction)
{
    if (MovableElement::isDirection(direction) && _player->canShoot())
    {
        _player->useAmmo();
        _bulletsList.push_back(_player->getShoot(direction));
    }
    
}

void Level::reset()
{
    clear();
    _player->reset();
    _maze.reset();
    init();
}

void Level::clear()
{
    for (Trace* trace : *getTraces())
        trace->deleteTrace();
    
    for (Enemy* enemy : *getEnemies())
    {
        if (enemy != nullptr)
            delete enemy;
        enemy = nullptr;
    }
    getEnemies()->clear();
}

// ============================================
// ============  ACCESSOR METHODS  ============
// ============================================

list<Enemy*> * Level::getEnemies()
{
    return &_enemiesList;
}

list<Bullet*> * Level::getBullets()
{
    return &_bulletsList;
}

Player * Level::getPlayer()const
{
    return _player;
}

bool Level::getWin() const
{
    return _playerWin;
}

bool Level::getLoose() const
{
    return _playerLoose;
}

bool Level::getPlayStop() const
{
    return _play;
}

bool Level::getLevelEnd() const
{
    return _levelEnd;
}

list <Trace*> * Level::getTraces()
{
    return _maze.getTraceList();
}

list<Wall *> * Level::getWalls()
{
    return _maze.getWallsList();
}

list<MazeCase*> * Level::getMazeCases()
{
    return _maze.getMazeCaseList();
}

std::list<Coin*> * Level::getCoinList()
{
    return &_coinList;
}


Maze* Level::getMaze()
{
    return &_maze;
}

void Level::setPlayer(Player *player)
{
    _player = nullptr;
    _player = player;
}

void Level::setPlayStop()
{
    _play = !_play;
}

sf::Time Level::getTime()
{
    return _chrono.getElapsedTime();
}
