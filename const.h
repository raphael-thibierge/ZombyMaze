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
const unsigned int MAZE_SIZE = 6;
const unsigned int MAZE_X = 0;
const unsigned int MAZE_Y = 0 ;


// MAZECASE
const unsigned int MAZECASE_SIZE = 40;

//PLAYER
const unsigned int PLAYER_INITIAL_X = 100;
const unsigned int PLAYER_INITIAL_Y = 100;





// =====================    GAMEVIEW   ===================


//GAMEVIEW
const std::string VIEWGAME_MAZE_BACKGROUND = "images/background.png";
const int VIEWGAME_MAZE_BACKGROUND_WIDTH = 878;
const int VIEWGAME_MAZE_BACKGROUND_HEIGHT = 878;

const std::string VIEWGAME_IMAGE_PLAYER = "images/persoface.png";
const unsigned int PLAYER_WIDTH = 42;
const unsigned int PLAYER_HEIGHT = 42;
const std::string VIEWGAME_IMAGE_ZOMBY = "images/zombieface.png";
const unsigned int ZOMBY_WIDTH = 30;
const unsigned int ZOMBY_HEIGHT = 30;
const std::string VIEWGAME_IMAGE_WALL = "images/zombieface.png";
const unsigned int WALL_WIDTH = 10;
const unsigned int WALL_HEIGHT = 10;

#endif
