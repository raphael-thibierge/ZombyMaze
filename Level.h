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
    int _enemiesCpt;
    Maze _maze;
    
    // states
    bool _playerLoose;
    bool _playerWin;
    bool _play;
    bool _levelEnd;

public:

    Level ();

	virtual ~Level ();


// METHODS
//
    // generation of enemies
    void generateEnemy();

    void runGame();
    
    void construct();
    
    void movementManager();
    
    // verify collision between all level's objects
    void collisionManager();

    void playerShoot(const std::string direction);
    
    bool enemiesCollision();
    
    void bulletCollision();
    
    void powerUpCollision();
    
    void moveAllEnemies();
    
    void moveAllBullets();
    
    void enemiesCheckTraces();
    
    void updateMazeCasePosition();
    
    bool successOutOfMaze();

    void spawnRandomEnemy();
    
    void generateEnemies();

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
    
    Player* getPlayer();
    
    Maze * getMaze() ;
    
    
    
    
    void setPlayStop();
    
    void setPlayer(Player * player);
};

    



#endif // LEVEL_H
