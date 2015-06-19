#include "Bullet.h"

using namespace std ;

// Constructors/Destructors
//

Bullet::Bullet(const string direction, const unsigned int X, const unsigned int Y) : MovableElement()
{
    _direction = direction;
    _X = X;
    _Y = Y;
    initBullet();
}

Bullet::~Bullet () {}


//
// Methods
//

void Bullet::initBullet(){


    _damage = BULLET_DAMAGE;
    _speed = BULLET_SPEED;
    _width = BULLET_WIDTH;
    _height = BULLET_HEIGHT;

    if (_direction == "NORTH")
        _Y -= _height;
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

void Bullet::autoMove()
{
    MovableElement::move(_direction);
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

