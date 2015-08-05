//
//  Player.cpp
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "Player.h"

using namespace std;

Player::Player() : Perso()
{
    _level = 1;
    _theme = 1;
    reset();
}

void Player::reset()
{
    _direction = "down";
    _isMoving = false;
    _speed = PLAYER_SPEED;
    _width = PLAYER_WIDTH;
    _height = PLAYER_HEIGHT;
    _name = "player";
    
    load();
    
    // speed bonnus
    _boostAvalaible = false;
    _boostActivated = false;
    
    // shield bonnus
    _shieldAvalaible = false;
    _shieldActivated = false;
    
    // gun bonus
    _gunAvalaible = false;
    _fireRateTime = PLAYER_FIRE_RATE;
    _nbAmmo = 0;
    
    _fireRate.restart();
    _time.restart();
    _boostTime = _time.getElapsedTime();
    _shieldTime = _time.getElapsedTime();
}

void Player::update()
{
    _boostTime += _time.getElapsedTime();
    _shieldTime += _time.getElapsedTime();
    _time.restart();
    
    if (_boostTime > PLAYER_BOOST_LIFE)
    {
        if (_boostActivated)
            _boostAvalaible = false;
        _boostActivated = false;
        
    }
    
    if (_shieldTime > PLAYER_SHIELD_LIFE)
    {
        if (_shieldActivated)
            _shieldAvalaible = false;
        _shieldActivated = false;
    }
    
    autoMove();
}

void Player::autoMove()
{
    // if player has begun a movement
    if (_isMoving)
    {
        if (_boostActivated)
            _speed = PLAYER_SPEED + PLAYER_ACCELERATION;
        else
            _speed = PLAYER_SPEED;
        
        move();
        // if he is in the destination mazeCase
        {
            if (_mazeCaseToGo != nullptr && _mazeCaseToGo->contain(this))
            {
                // end of the movement
                leaveTrace();
                setMazeCase(_mazeCaseToGo);
                _mazeCasePosition->place(this);
                _mazeCaseToGo = nullptr;
                _isMoving = false;
            }
        }
    }
}

void Player::useAmmo()
{
    if (_nbAmmo > 0)
        _nbAmmo--;
}

void Player::useBoost()
{
    if (_boostAvalaible)
    {
        _boostActivated = true;
        _boostTime = sf::seconds(0.0);
    }
}

void Player::useShield()
{
    if (_shieldAvalaible)
    {
        _shieldActivated = true;
        _shieldTime = sf::seconds(0.0f);
    }
}

void Player::chooseDirection(const string direction)
{
    if (isDirection(direction) && !_isMoving)
    {
        if (_mazeCasePosition != nullptr && _mazeCasePosition->isAvailableDirection(direction) )

        {
            _direction = direction;
            _mazeCaseToGo = _mazeCasePosition->getNextMazeCase(_direction);
            _isMoving = true;
        }
    }
}

void Player::nextLevel()
{
    _level++;
}


const bool Player::canShoot()
{
    if(_gunAvalaible && _nbAmmo > 0 && _fireRate.getElapsedTime() > _fireRateTime)
    {
        _fireRate.restart();
        return true;
    }
    return false;
}


void Player::save()
{
    fstream saveFile ;
    // open or create a save file
    saveFile.open(PLAYER_FILE, ios::out);
    saveFile << _money << "\n";
    saveFile << _level << "\n";
    saveFile.close();
}

void Player::load()
{
    fstream saveFile ;
    string line;
    // load a save file
    saveFile.open(PLAYER_FILE, ios::in);
    
    getline(saveFile, line);
    _money = atoi(&line[0]);
    cout << "monez" << _money << endl;
    getline(saveFile, line);
    _level = atoi(&line[0]);
    cout << "lvl" << _level << endl;
}


// ACCESSORS

void Player::setMoving(const bool moving)
{
    _isMoving = moving;
}

const bool Player::getMoving() const
{
    return _isMoving;
}

const bool Player::getGun()
{
    return _gunAvalaible;
}

const bool Player::getShield() const
{
    return _shieldAvalaible;
}

const bool Player::getBoost() const
{
    return _boostAvalaible;
}

const bool Player::getShieldActivated() const
{
    return _shieldActivated;
}

const unsigned int Player::getAmmo() const
{
    return _nbAmmo;
}

const unsigned int Player::getTheme() const
{
    return _theme;
}

void Player::setGun(bool available = true)
{
    _gunAvalaible = available;
}

void Player::setTheme(const unsigned int theme)
{
    _theme = theme;
}

const unsigned int Player::getLevel() const
{
    return _level;
}

void Player::addAmmo(const unsigned int number)
{
    _nbAmmo += number;
}

void Player::setBoost(const bool boost = true)
{
    _boostAvalaible = boost;
}

void Player::setShield(const bool shield)
{
    _shieldAvalaible = shield;
}