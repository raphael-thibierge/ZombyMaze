#ifndef LEVEL_H
#define LEVEL_H


#include "Enemy.h"
#include "Player.h"
#include "Maze.h"

class Level
{

private:

    unsigned int _level;
	unsigned int _nbEnnemies;
    Player * _player;
    std::list<Enemy*> _enemiesList ;
    std::list<Bullet*> _bulletsList;
    std::list<Coin*> _coinList;
    int _enemiesCpt;
    Maze _maze;
    
    sf::Clock _chrono;
    sf::Time _time;
    
    // states
    bool _playerLoose;
    bool _playerWin;
    bool _play;
    bool _levelEnd;
    
    unsigned int _nbRetry;

public:

    Level(const unsigned int level, Player* player);

	virtual ~Level ();


// METHODS
//

    // construct and run game
    void runGame();

    void construct();
    
    void generateEnemies();
    
    void spawnRandomEnemy();
    
    bool successOutOfMaze();
    
    void playerShoot(const std::string direction);
    
    
    // COLLISION
    void collisionManager();
    
    bool enemiesCollision();
    
    void bulletCollision();
    
    void powerUpCollision();
    
    void coinCollision();

    
    // MOVEMENT
    void movementManager();
    
    void moveAllEnemies();
    
    void moveAllBullets();
    
    // UPDATE OBJETCS
    void updateTraces();    

    // OTHER
    void init();
    
    void reset();
    
    void clear();



// ACCESSOR METHODS
//

    std::list<Enemy*> * getEnemies();

    std::list<Bullet*> * getBullets();

    Player * getPlayer()const;
    
    bool getLoose() const;
    
    bool getWin() const;
    
    bool getPlayStop() const;
    
    bool getLevelEnd() const;
    
    std::list<Trace *> * getTraces();
    
    std::list<Wall *> * getWalls();
    
    std::list<MazeCase*> * getMazeCases();
    
    std::list<Coin*> * getCoinList();
    
    Player* getPlayer();
    
    Maze * getMaze() ;
    
    sf::Time getTime();
    
    const unsigned int getRetry() const;
    
    const unsigned int getLevel() const
    {
        return _level;
    }
    
    
    void setPlayStop();
    
    void setPlayer(Player * player);
    
    void setRetry(const unsigned int number)
    {
        _nbRetry = number;
    }
};

    



#endif // LEVEL_H