#ifndef LEVEL_H
#define LEVEL_H


#include "Enemy.h"
#include "Player.h"

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

public:

    Level (unsigned int level, Player * player, unsigned int * difficultyPointer);

	virtual ~Level ();


// METHODS
//
    // generation of enemies
    void generateEnemy();

    // verify collision between all level's objects
    void collisionManager();

    void runGame();




// ACCESSOR METHODS
//

    std::list<Enemy*> * getEnemies();

    std::list<Bullet*> * getBullet();

    Player * getPlayer()const;


};

#endif // LEVEL_H
