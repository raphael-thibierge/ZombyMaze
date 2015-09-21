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
const unsigned int WINDOW_WIDTH = 1200;
const unsigned int WINDOW_HEIGHT = 820;

// =====================    GAMEMODEL   ===================

// MAZE
const unsigned int MAZE_X = 0;
const unsigned int MAZE_Y = 0 ;
const std::string TEMOIN_IMAGE = "temoin.png";
const unsigned LEVEL_MAX = 5 ;

// MAZECASE
const unsigned int MAZECASE_SIZE = 50;

//PLAYER
const unsigned int PLAYER_INITIAL_X = 20;
const unsigned int PLAYER_INITIAL_Y = 20;
const unsigned int PLAYER_SPEED = 5;
const unsigned int PLAYER_NB_TRACE_MAX = 5;
const unsigned int PLAYER_ACCELERATION = 3;
const std::string PLAYER_FILE = resourcePath() + "player.txt" ;

const sf::Time PLAYER_FIRE_RATE = sf::seconds(0.5f);

const sf::Time PLAYER_BOOST_LIFE = sf::seconds(4.0f);
const sf::Time PLAYER_SHIELD_LIFE = sf::seconds(2.0f);

// ENEMIES
const unsigned int ZOMBY_SPEED = 3 ;
const unsigned int ZOMBY_ACCELERATION = 2;
const unsigned int ZOMBY_NB_TRACE_MAX = 0;

// TRACE
const std::string TRACE_IMAGE_UP[2] = {"tracehaut.png", "tracehaut.png"};
const std::string TRACE_IMAGE_DOWN[2] = {"tracebas.png", "tracebas.png"};
const std::string TRACE_IMAGE_LEFT[2] = {"tracegauche.png", "tracegauche.png" };
const std::string TRACE_IMAGE_RIGHT[2] = {"tracedroite.png", "tracedroite.png"};
const unsigned int TRACE_WIDTH = 20;
const unsigned int TRACE_HEIGHT = 50;
const unsigned int TRACE_NB_SPRITES = 1;
const sf::Time TRACE_LIFE = sf::seconds(0.5f);


// BULLET
const std::string BULLET_IMAGE_UP[2] = {"BulletUp.png", "BulletUp.png"};
const std::string BULLET_IMAGE_DOWN[2] = {"BulletDown.png", "BulletUp.png"};
const std::string BULLET_IMAGE_LEFT[2] = {"BulletLeft.png", "BulletUp.png"};
const std::string BULLET_IMAGE_RIGHT[2] = {"BulletRight.png", "BulletUp.png"};
const unsigned int BULLET_SPEED = 15;
const unsigned int BULLET_WIDTH = 16;
const unsigned int BULLET_HEIGHT = 6;
const unsigned int BULLET_DAMAGE = 10;

// COIN
const std::string COIN_IMAGE = "coin.png";
const unsigned int COIN_WIDTH = 41;
const unsigned int COIN_HEIGHT = 41;

// gun
const std::string GUN_IMAGE = "gun.png";
const std::string GUN_IMAGE_UNAVAILABLE = "gun_unvailable.png";
const unsigned int GUN_WIDTH = 41;
const unsigned int GUN_HEIGHT = 41;
const unsigned int GUB_AMMO = 5;

// boost
const std::string BOOST_IMAGE = "boost.png";
const std::string BOOST_IMAGE_UNAVAILABLE = "boost_unavailable.png";
const unsigned int BOOST_WIDTH = 41;
const unsigned int BOOST_HEIGHT = 41;

// shield
const std::string SHIELD_IMAGE = "shield.png";
const std::string SHIELD_IMAGE_UNAVAILABLE = "shield_unvailable.png";
const unsigned int SHIELD_WIDTH = 41;
const unsigned int SHIELD_HEIGHT = 41;


// BEST SCORS
const unsigned int BEST_SCORE_NB = 5;
const std::string BEST_SCORE_FILE = resourcePath() + "bestscores.txt";

// =====================    INTRODUCTIONVIEW   ===================
const std::string IMAGE_INTRO = "backgroundMainMenu.png";
const float TIME_INTRODUCTION = 0.5f;

// =====================    GAMEVIEW   ===================
// TEXTES
const unsigned int TEXT_SIZE = 40;
const unsigned int TEXT_TITLE_SIZE = 60;

// BUTTONS
const unsigned int BUTTON_WIDTH = 300;
const unsigned int BUTTON_HEIGHT = 120;
const std::string BUTTON_TEXT_FONT = "";

const std::string BUTTON_PLAY = "buttonPlay.png";
const std::string BUTTON_QUIT = "buttonQuit.png";
const std::string BUTTON_THEME = "buttonTheme.png";
const std::string BUTTON_LEVEL = "bouonlevel1.png";


const std::string BACKGROUND_MAINMENU = "backgroundMainMenu.png";

const unsigned int MENU_COLUMN[1] = {750};
const unsigned int MENU_LINE[4] = {50, 250, 450, 650};

//GAMEVIEW
const std::string VIEWGAME_MAZE_BACKGROUND[2] = {"caca.png", "fond_rasta.png"};

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


const std::string VIEW_BACKGROUND_IMAGE = "background.png";


const std::string VIEWGAME_IMAGE_PLAYER_UP[2] = {"PersoDos.png", "rastados.png"};
const std::string VIEWGAME_IMAGE_PLAYER_DOWN[2] = {"perso.png", "RastaFace2.png"};
const std::string VIEWGAME_IMAGE_PLAYER_LEFT[2] = {"PersoGauche.png", "rastagauche.png"};
const std::string VIEWGAME_IMAGE_PLAYER_RIGHT[2] = {"PersoDroite.png", "rastadroite.png"};

const unsigned int PLAYER_WIDTH = 31;
const unsigned int PLAYER_HEIGHT = 41;
const unsigned int PLAYER_NB_SPRITES = 3;

const std::string VIEWGAME_IMAGE_ZOMBY_UP[2] = {"ZombieDos.png", "copsback.png"};
const std::string VIEWGAME_IMAGE_ZOMBY_DOWN[2] = { "ZombieFace.png", "copsface.png"};
const std::string VIEWGAME_IMAGE_ZOMBY_LEFT[2] =  {"ZombieGauche.png", "copsgauche.png" };
const std::string VIEWGAME_IMAGE_ZOMBY_RIGHT[2] = {"ZombieDroite.png", "copsdroite.png"};

const unsigned int ZOMBY_WIDTH = 31;
const unsigned int ZOMBY_HEIGHT = 41;
const unsigned int ZOMBY_NB_SPRITES = 3;
 
const std::string VIEWGAME_IMAGE_WALL_H[2] = {"MurH.png", "murcannaH.png"};
const std::string VIEWGAME_IMAGE_WALL_V[2] = {"MurV.png", "murcannaV.png"};
const unsigned int WALL_WIDTH_H = 53;
const unsigned int WALL_WIDTH_V = 12;
const unsigned int WALL_HEIGHT_H = 12;
const unsigned int WALL_HEIGHT_V = 53;

const std::string COLUMN_INFO_IMAGE[2] = {"colonneInfo2.png", "colonne_rasta.png"};
const unsigned int COLUMN_INFO_WIDTH = 400;
const unsigned int COLUMN_INFO_HEIGHT = 820;
const unsigned int COLUMN_INFO_X = 820;
const unsigned int COLUMN_INFO_Y = 0;
const unsigned int COLUMN_INFO_TEXT_X = 1000;

const unsigned int INFO_AMMO_Y = 80;
const unsigned int INFO_CRONO_Y = 400;
const unsigned int INFO_MONEY_Y = 290;
const unsigned int INFO_NB_RESTART = 180;

#endif
