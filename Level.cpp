#include "Level.h"

//
// CONSTRUCTOR  AND DESTRUCTOR
//

using namespace std;
 

Level::Level(const unsigned int level, Player* player) : _level(level), _maze(Maze(level)), _player(player)
{
    _nbEnnemies = _maze.getNbEnnemies();
    _nbRetry = 0;
    init();
}


void Level::init()
{
    
    // init states
    _playerWin = false;
    _playerLoose = false;
    _play = true;
    _levelEnd = false;
    
    _enemiesCpt = 0;
    
    // init player position
    _player->setPosition(PLAYER_INITIAL_X, PLAYER_INITIAL_Y);
    _player->setMoving(false);
    _player->updateMazeCase(getMazeCases());
    
    cout << getEnemies()->size() << endl;
    // add enenies
    generateEnemies();
    
    cout << getEnemies()->size() << endl;
    updateTraces();
    
    _chrono.restart();
    _time = _chrono.getElapsedTime();
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
}


//
// METHODS
//
// construct and run game

void Level::runGame()
{
    
    if (_play)
    {
        _player->update();
        
        movementManager();
        
        collisionManager();
        
        updateTraces();
        
        if (enemiesCollision())
        {
            _playerLoose = true;
        }
        _playerWin = successOutOfMaze();
        
        if (_playerLoose)
        {
            setPlayStop();
            _player->save();
        }
        else if (_playerWin)
        {
            setPlayStop();
            _nbRetry = 0;
            _player->save();
        }
        _time += _chrono.getElapsedTime();
        _chrono.restart();
    }
}

// ===========   MOVEMENTS
//
void Level::movementManager()
{
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
        if (enemy != nullptr)
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
//
bool Level::enemiesCollision()
{
    list<Enemy*> enemiesToDestroy;
    bool returnValue = false;
    // in enemy list
    for (Enemy* enemy : _enemiesList)
    {
        if (_player->ElementOnElement(enemy))
        {
            returnValue = !_player->getShieldActivated();
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
                
            }
            else if ( powerUp->getName() == "boost")
            {
                _player->setBoost(true);
            }
            else if ( powerUp->getName() == "shield")
            {
                _player->setShield(true);
            }
            
            powerUp->setAvailable(false);
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
    for (unsigned int i = 0 ; i < _nbEnnemies ; i++)
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
    _nbRetry++;
    init();
}

void Level::clear()
{
    // reset trace
    for (Trace* trace : *getTraces())
        trace->deleteTrace();
    
    // gelete enemies
    for (Enemy* enemy : *getEnemies())
    {
        if (enemy != nullptr)
            delete enemy;
        enemy = nullptr;
    }
    getEnemies()->clear();
    
    // delete coins
    for (Coin* coin : *getCoinList())
    {
        if (coin != nullptr)
            delete coin;
        coin = nullptr;
    }
    getCoinList()->clear();
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

const unsigned int Level::getRetry() const
{
    return _nbRetry;
}

void Level::setPlayer(Player *player)
{
    _player = nullptr;
    _player = player;
}

void Level::setPlayStop()
{
    _play = !_play;
    _chrono.restart();
    for (auto trace : *getTraces())
        trace->setPlayPause();
}

sf::Time Level::getTime()
{
    return _time;
}
