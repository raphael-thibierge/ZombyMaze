//
//  const.h
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>

#ifndef Console_const_h
#define Console_const_h

//WINDOWS
const unsigned int WINDOW_WIDTH = 1175;
const unsigned int WINDOW_HEIGHT = 820;

// =====================    GAMEMODEL   ===================

// MAZE
const unsigned int MAZE_SIZE = 14;
const unsigned int MAZE_X = 0;
const unsigned int MAZE_Y = 0 ;
const std::string MAZE_MATRICE_FILE = resourcePath() + "1.txt";
const std::string TEMOIN_IMAGE = "temoin.png";

// MAZECASE
const unsigned int MAZECASE_SIZE = 50;

//PLAYER
const unsigned int PLAYER_INITIAL_X = 20;
const unsigned int PLAYER_INITIAL_Y = 20;
const unsigned int PLAYER_SPEED = 5;
const unsigned int PLAYER_NB_TRACE_MAX = 5;

// ENEMIES
const unsigned int ZOMBY_SPEED = 3 ;
const unsigned int ZOMBY_ACCELERATION = 0;
const unsigned int ZOMBY_NB_TRACE_MAX = 0;

// TRACE
const std::string TRACE_IMAGE = "traces.png";
const unsigned int TRACE_WIDTH = 20;
const unsigned int TRACE_HEIGHT = 42;
const unsigned int TRACE_NB_SPRITES = 1;
const sf::Time TRACE_LIFE = sf::seconds(0.5f);


// BULLET
const std::string BULLET_IMAGE_UP = "BulletUp.png";
const std::string BULLET_IMAGE_DOWN = "BulletDown.png";
const std::string BULLET_IMAGE_LEFT = "BulletLeft.png";
const std::string BULLET_IMAGE_RIGHT = "BulletRight.png";
const unsigned int BULLET_SPEED = 15;
const unsigned int BULLET_WIDTH = 16;
const unsigned int BULLET_HEIGHT = 6;
const unsigned int BULLET_DAMAGE = 10;

// COIN
const std::string COIN_IMAGE = "coin.png";
const unsigned int COIN_WIDTH = 41;
const unsigned int COIN_HEIGHT = 41;

//
const unsigned int ENEMIES_MAX = 10 ;

// gun
const std::string GUN_IMAGE = "gun.png";
const unsigned int GUN_WIDTH = 41;
const unsigned int GUN_HEIGHT = 41;


// =====================    INTRODUCTIONVIEW   ===================
const std::string IMAGE_INTRO = "Intro.png";
const float TIME_INTRODUCTION = 2.0f;

// =====================    GAMEVIEW   ===================
// TEXTES
const unsigned int TEXT_SIZE = 40;

//GAMEVIEW
const std::string VIEWGAME_MAZE_BACKGROUND = "fond.png";
const int VIEWGAME_MAZE_BACKGROUND_WIDTH = WINDOW_WIDTH;
const int VIEWGAME_MAZE_BACKGROUND_HEIGHT = WINDOW_HEIGHT;

const std::string GAMEOVER_IMAGE = "GameOver.png";
const unsigned int GAMEOVER_IMAGE_X = 0;
const unsigned int GAMEOVER_IMAGE_Y = 0;
const unsigned int GAMEOVER_IMAGE_WIDTH = WINDOW_WIDTH;
const unsigned int GAMEOVER_IMAGE_HEIGHT = WINDOW_HEIGHT;


const std::string EXIT_IMAGE = "PanneauSortie.png";
const unsigned int EXIT_IMAGE_WIDTH = 40;
const unsigned int EXIT_IMAGE_HEIGHT = 40;


const std::string WIN_IMAGE = "Win.png";
const unsigned int WIN_IMAGE_X = 0;
const unsigned int WIN_IMAGE_Y = 0;
const unsigned int WIN_IMAGE_WIDTH = WINDOW_WIDTH;
const unsigned int WIN_IMAGE_HEIGHT = WINDOW_HEIGHT;



const std::string VIEWGAME_IMAGE_PLAYER_UP = "PersoDos.png";
const std::string VIEWGAME_IMAGE_PLAYER_DOWN = "perso.png";
const std::string VIEWGAME_IMAGE_PLAYER_LEFT = "PersoGauche.png";
const std::string VIEWGAME_IMAGE_PLAYER_RIGHT = "PersoDroite.png";

const unsigned int PLAYER_WIDTH = 31;
const unsigned int PLAYER_HEIGHT = 41;
const unsigned int PLAYER_NB_SPRITES = 3;

const std::string VIEWGAME_IMAGE_ZOMBY_UP = "ZombieDos.png";
const std::string VIEWGAME_IMAGE_ZOMBY_DOWN = "ZombieFace.png";
const std::string VIEWGAME_IMAGE_ZOMBY_LEFT = "ZombieGauche.png";
const std::string VIEWGAME_IMAGE_ZOMBY_RIGHT = "ZombieDroite.png";
const unsigned int ZOMBY_WIDTH = 31;
const unsigned int ZOMBY_HEIGHT = 41;
const unsigned int ZOMBY_NB_SPRITES = 3;

const std::string VIEWGAME_IMAGE_WALL_H = "MurH.png";
const std::string VIEWGAME_IMAGE_WALL_V = "MurV.png";
const unsigned int WALL_WIDTH_H = 53;
const unsigned int WALL_WIDTH_V = 12;
const unsigned int WALL_HEIGHT_H = 12;
const unsigned int WALL_HEIGHT_V = 53;

const sf::Time PLAYER_FIRE_RATE = sf::seconds(0.5f);

#endif
