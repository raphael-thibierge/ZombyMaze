#ifndef BULLET_H
#define BULLET_H
#include "MovableElement.h"
#include <iostream>
#include <string>
#include <vector>


class Bullet : public MovableElement
{

private  :

    unsigned int _type;
    unsigned int _damage;
    std::string _shooter;



// Constructeurs destructeurs
public:
	Bullet (const std::string direction, const unsigned int X, const unsigned int Y);

    
	virtual ~Bullet ();


// Methods
public:
    void autoMove();

    void initBullet();

    std::string toString();


// ACCESSORS METHODS

    unsigned int getDamage() const;
    
    std::string getShooter() const;
    
    unsigned int getType() const;

};

#endif // BULLET_H
