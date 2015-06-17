#ifndef BULLET_H
#define BULLET_H
#include "MovableElement.h"
#include <iostream>
#include <string>
#include <vector>


class Bullet : virtual public MovableElement
{

private :

    unsigned int _type;
    unsigned int _damage;
    std::string _shooter;
    std::string _direction;
    float _speed;

public:

// Constructeurs destructeurs

	Bullet (const std::string direction, const unsigned int X, const unsigned int Y);

    
	virtual ~Bullet ();


// Methodes
    
    // move the bullet (depend of its direction and speed)
    void move ();

    void initBullet();

    std::string toString();


// ACCESSORS METHODS

    unsigned int getDamage() const;
    
    std::string getShooter() const;
    
    unsigned int getType() const;

};

#endif // BULLET_H
