#ifndef LEVEL_H
#define LEVEL_H


#include "Enemy.h"
#include "Player.h"
#include "Maze.h"

class Level
{

private:

    unsigned int _level;
	unsigned int * _difficulty;
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

    Level ();

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
    void updateMazeCasePosition();
    
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
    
    void setPlayStop();
    
    void setPlayer(Player * player);
};

    



#endif // LEVEL_H