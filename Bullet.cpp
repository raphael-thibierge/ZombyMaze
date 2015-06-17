#include "Bullet.h"

using namespace std ;

// Constructors/Destructors
//

Bullet::Bullet(const string direction, const unsigned int X, const unsigned int Y) : MovableElement()
{
    _X = X;
    _Y = Y;
    initBullet();
}

Bullet::~Bullet () {
    cout << __FUNCTION__ << endl ;
}


//
// Methods
//

void Bullet::initBullet(){


    _damage = BULLET_DAMAGE;
    _speed = BULLET_SPEED;
    _width = BULLET_WIDTH;
    _height = BULLET_HEIGHT;

/*
    if (_direction == "NORTH")
        _Y -= _height;
    if (_direction == "SOUTH")
        _Y += _height;
 */
}

string Bullet::toString()
{
    string text = "BULLET : " ;
    text += " Shooter=" + _shooter + " ";
    text += toString();
    text += " speed=";
    text += to_string(_speed);
    text += " direction=" + _direction ;
    text += " damage=" + to_string(_damage);
    text += " bullet type=" + to_string(_type);
    text += " shooter=" + _shooter;
    return text;
}

// Accessor methods
//

unsigned int Bullet::getDamage() const
{
    return _damage;
}

string Bullet::getShooter() const
{
    return _shooter;
}

unsigned int Bullet::getType() const
{
    return _type;
}


// Other methods
//

