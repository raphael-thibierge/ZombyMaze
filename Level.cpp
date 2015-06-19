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
    // add an enemy
    generateEnemies();
    updateMazeCasePosition();
    
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

void Level::runGame()
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

// PRIVATE
void Level::movementManager()
{
    _player->autoMove() ;
    moveAllEnemies();
    moveAllBullets();
}

void Level::collisionManager()
{
    bulletCollision();
    
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
                    if (enemy->getMazeCase() != nullptr)
                        enemy->getMazeCase()->addCoin();
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

void Level::enemiesCheckTraces()
{
    for (Enemy* enemy : _enemiesList)
    {
        enemy->findTrace(getTraces());
    }
}

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
        randomLine = rand() % _maze.getSize();
        randomColumn = rand() % _maze.getSize();
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
    if (MovableElement::isDirection(direction))
    {
        _bulletsList.push_back(_player->getShoot(direction));
    }

}

void Level::reset()
{
    clear();
    init();
}

void Level::clear()
{
    
}

//
// ACCESSOR METHODS
//

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