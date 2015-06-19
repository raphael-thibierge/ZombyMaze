#include "Level.h"

//
// CONSTRUCTOR  AND DESTRUCTOR
//

using namespace std;

Level::Level (unsigned int level, Player * player, unsigned int * difficultyPointer) : _player(player), _difficulty(difficultyPointer)
{
    //cout << "\n=====================" << endl;
    //cout << "CONSTRUCTOR LEVEL" << endl;

    _nbEnnemies = ENEMIES_MAX;
    _level = level;

    _enemiesCpt = 0;

}

Level::~Level ()
{
    //cout << "\n=====================" << endl;
    //cout << "DESTRUCTOR LEVEL" << endl;

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






//
// ACCESSOR METHODS
//

list<Enemy*> * Level::getEnemies()
{
    return &_enemiesList;
}

list<Bullet*> * Level::getBullet()
{
    return &_bulletsList;
}

Player * Level::getPlayer()const
{
    return _player;
}
