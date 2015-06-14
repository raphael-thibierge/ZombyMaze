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

#ifndef Console_const_h
#define Console_const_h

//WINDOWS
const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 800;

// =====================    GAMEMODEL   ===================

// MAZE
const unsigned int MAZE_SIZE = 15;
const unsigned int MAZE_X = 0;
const unsigned int MAZE_Y = 0 ;


// MAZECASE
const unsigned int MAZECASE_SIZE = 50;

//PLAYER
const unsigned int PLAYER_INITIAL_X = 20;
const unsigned int PLAYER_INITIAL_Y = 20;
const unsigned int PLAYER_SPEED = 5;

// ENEMIES
const unsigned int ZOMBY_SPEED = 4 ;

// =====================    GAMEVIEW   ===================


//GAMEVIEW
const std::string VIEWGAME_MAZE_BACKGROUND = "images/background.png";
const int VIEWGAME_MAZE_BACKGROUND_WIDTH = 800;
const int VIEWGAME_MAZE_BACKGROUND_HEIGHT = 800;

const std::string VIEWGAME_IMAGE_PLAYER = "images/perso.png";
const unsigned int PLAYER_WIDTH = 31;
const unsigned int PLAYER_HEIGHT = 41;
const unsigned int PLAYER_NB_SPRITES = 3;

const std::string VIEWGAME_IMAGE_ZOMBY = "images/zomby.png";
const unsigned int ZOMBY_WIDTH = 31;
const unsigned int ZOMBY_HEIGHT = 41;
const unsigned int ZOMBY_NB_SPRITES = 3;

const std::string VIEWGAME_IMAGE_WALL_H = "images/MurH.png";
const std::string VIEWGAME_IMAGE_WALL_V = "images/MurV.png";
const unsigned int WALL_WIDTH_H = 53;
const unsigned int WALL_WIDTH_V = 12;
const unsigned int WALL_HEIGHT_H = 12;
const unsigned int WALL_HEIGHT_V = 53;

#endif
