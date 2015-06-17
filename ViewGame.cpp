#include "ViewGame.h"

using namespace std;
using namespace sf;

ViewGame::ViewGame() : View()
{
    _cptSprites = 0;
}

ViewGame::~ViewGame()
{
}

bool ViewGame::initSFML()
{
        //background
    if (!initSprite("background", VIEWGAME_MAZE_BACKGROUND, 1, VIEWGAME_MAZE_BACKGROUND_WIDTH, VIEWGAME_MAZE_BACKGROUND_HEIGHT))
        return false;
    
        // exit
    if (!initSprite("exitLabel", EXIT_IMAGE, 1, EXIT_IMAGE_WIDTH, EXIT_IMAGE_HEIGHT))
        return false;

    // player
    if (!initSprite("playerup", VIEWGAME_IMAGE_PLAYER_UP, PLAYER_NB_SPRITES, PLAYER_WIDTH, PLAYER_HEIGHT))
        return false;
    if (!initSprite("playerdown", VIEWGAME_IMAGE_PLAYER_DOWN, PLAYER_NB_SPRITES, PLAYER_WIDTH, PLAYER_HEIGHT))
        return false;
    if (!initSprite("playerleft", VIEWGAME_IMAGE_PLAYER_LEFT, PLAYER_NB_SPRITES, PLAYER_WIDTH, PLAYER_HEIGHT))
        return false;
    if (!initSprite("playerright", VIEWGAME_IMAGE_PLAYER_RIGHT, PLAYER_NB_SPRITES, PLAYER_WIDTH, PLAYER_HEIGHT))
        return false;

    // ZOMBY
    if (!initSprite("zombyleft", VIEWGAME_IMAGE_ZOMBY_LEFT, ZOMBY_NB_SPRITES, ZOMBY_WIDTH, ZOMBY_HEIGHT))
        return false;
    if (!initSprite("zombyright", VIEWGAME_IMAGE_ZOMBY_RIGHT, ZOMBY_NB_SPRITES, ZOMBY_WIDTH, ZOMBY_HEIGHT))
        return false;
    if (!initSprite("zombyup", VIEWGAME_IMAGE_ZOMBY_UP, ZOMBY_NB_SPRITES, ZOMBY_WIDTH, ZOMBY_HEIGHT))
        return false;
    if (!initSprite("zombydown", VIEWGAME_IMAGE_ZOMBY_DOWN, ZOMBY_NB_SPRITES, ZOMBY_WIDTH, ZOMBY_HEIGHT))
        return false;

    if (!initSprite("trace", TRACE_IMAGE, TRACE_NB_SPRITES, TRACE_WIDTH, TRACE_HEIGHT))
        return false;


    // walls
    if (!initSprite("horizontalWall", VIEWGAME_IMAGE_WALL_H, 1, WALL_WIDTH_H, WALL_HEIGHT_H))
        return false;

    if (!initSprite("verticalWall", VIEWGAME_IMAGE_WALL_V, 1, WALL_WIDTH_V, WALL_HEIGHT_V))
        return false;
    
    // gameOver
    if (!initSprite("gameOver", GAMEOVER_IMAGE, 1, GAMEOVER_IMAGE_WIDTH, GAMEOVER_IMAGE_HEIGHT))
        return false;
    
    // win
    if (!initSprite("win", WIN_IMAGE, 1, WIN_IMAGE_WIDTH, WIN_IMAGE_HEIGHT))
        return false;
    
    // BULLETS
    if (!initSprite("bullet", BULLET_IMAGE, 1, BULLET_WIDTH, BULLET_HEIGHT))
        return false;
    
    // temoin
    if (!initSprite("temoin", TEMOIN_IMAGE, 1, MAZECASE_SIZE, MAZECASE_SIZE))
        return false;
    
    cout << "Sprites initialisés" << endl;
    

    return true;
}


int ViewGame::treatEventSFML()
{
    int returnValue = 1;
    if (_modele->getPlayStop())
    {
        if (Keyboard::isKeyPressed(Keyboard::Up))
            _modele->playerMove("up");
        
        if (Keyboard::isKeyPressed(Keyboard::Down))
            _modele->playerMove("down");
        
        if (Keyboard::isKeyPressed(Keyboard::Left))
            _modele->playerMove("left");
        
        if (Keyboard::isKeyPressed(Keyboard::Right))
            _modele->playerMove("right");
        
        if (Keyboard::isKeyPressed(Keyboard::Z))
            _modele->playerShoot("up");
        
        if (Keyboard::isKeyPressed(Keyboard::S))
            _modele->playerShoot("down");
        
        if (Keyboard::isKeyPressed(Keyboard::Q))
            _modele->playerShoot("left");
        
        if (Keyboard::isKeyPressed(Keyboard::D))
            _modele->playerShoot("right");
    }
    
        Event event;
    while (_window->pollEvent(event))
    {
        
        switch (event.type)
        {   
            case sf::Event::KeyPressed :
                switch (event.key.code)
            {
                    
                case sf::Keyboard::Escape:
                    returnValue = 111;
                    break;
                    
                case sf::Keyboard::Space:
                    if (_modele->getWin() || _modele->getLoose())
                    {
                        _modele->reset();
                    }
                    _modele->setPlayStop();
                    break;
                    
                default :
                    break;
            }
                break;
                
            case sf::Event::Closed :
                returnValue = 111;
                break;
                
            default:
                break;
        }
    }

        return returnValue;
}

void ViewGame::showViewSFML()
{
    
    if (_modele->getLoose())
    {
        displayGameOver();
    }
    
    else if (_modele->getWin())
    {
        displayWin();
    }else
    {
        
        // draw background
        _window->draw(_spritesList["background"]);
        
        displayBackGround();
        displayMaze();
        
        displayEnnemies();
        
        displayTrace();
        
        displayPlayer();
        
        displayBullets();
        
        _cptSprites++;
    }
}

void ViewGame::displayEnnemies()
{
    string name = "zomby" ;

    for (Enemy* enemy : *_modele->getEnemiesList())
    {
        name += enemy->getDirection();
        if (ZOMBY_NB_SPRITES > 1)
        {
            name += to_string(_cptSprites % ZOMBY_NB_SPRITES);
        }
        _spritesList[name].setPosition(enemy->getX(), enemy->getY());
        _window->draw(_spritesList[name]);
        if (enemy->getMazeCase() != nullptr)
        {
            name = "temoin";
            _spritesList[name].setPosition(enemy->getMazeCase()->getX(), enemy->getMazeCase()->getY());
            _window->draw(_spritesList[name]);
            _spritesList[name].setPosition(enemy->getMazeCase()->getY(), enemy->getMazeCase()->getX ());
            _window->draw(_spritesList[name]);
            int cpt = 0;
            for (auto direction : enemy->getMazeCase()->getAvalaibleDirecton())
            {
                cout << "mazecase " << cpt << " " << direction << endl;
                cpt++;
  
            }
            
        }
    }
}

void ViewGame::displayMaze()
{
    for (Wall* wall : *_modele->getWallsList())
    {

        switch (wall->getOrientation())
        {
            case 'v' :
                _spritesList["verticalWall"].setPosition(wall->getX(), wall->getY());
                _window->draw(_spritesList["verticalWall"]);
                break;

            case 'h' :
                _spritesList["horizontalWall"].setPosition(wall->getX(), wall->getY());
                _window->draw(_spritesList["horizontalWall"]);
                break;

            default:
                break;
        } 
    }
}

void ViewGame::displayPlayer()
{
    if (_modele->getPlayer() != nullptr)
    {
        string name = "player" ;
        if (PLAYER_NB_SPRITES > 1)
        {
            if (!_modele->getPlayer()->getMoving())
            {
                name += "down" + to_string(0);
            }

            else
            {
                name += _modele->getPlayer()->getDirection() + to_string(_cptSprites % PLAYER_NB_SPRITES);
            }
        }
        
        _spritesList[name].setPosition(_modele->getPlayer()->getX(), _modele->getPlayer()->getY());
        _window->draw(_spritesList[name]);

    }
}


void ViewGame::displayTrace()
{
    for (MazeCase* mazeCase : *_modele->getMaze()->getMazeCaseList())
    {
        
        if (mazeCase->getTrace() != nullptr)
        {
            _spritesList["trace"].setPosition(mazeCase->getTrace()->getX(), mazeCase->getTrace()->getY());
            _window->draw(_spritesList["trace"]);

        }
    }
}

void ViewGame::displayGameOver()
{
    _spritesList["gameOver"].setPosition(GAMEOVER_IMAGE_X, GAMEOVER_IMAGE_Y);
    _window->draw(_spritesList["gameOver"]);
}

void ViewGame::displayWin()
{
    _spritesList["win"].setPosition(GAMEOVER_IMAGE_X, GAMEOVER_IMAGE_Y);
    _window->draw(_spritesList["win"]);
}

void ViewGame::displayBullets()
{
    
    for (Bullet* bullet : *_modele->getBulletList())
    {
        _spritesList["bullet"].setPosition(bullet->getX(), bullet->getY());
        _window->draw(_spritesList["bullet"]);
    }
}

void ViewGame::displayInMazeCase(const unsigned int x, const unsigned int y, const std::string spriteName, const unsigned int width, const unsigned int height)
{
    unsigned int xSprite ;
    unsigned int ySprite ;
    
    xSprite = x * (MAZECASE_SIZE)  ;
    ySprite = y * (MAZECASE_SIZE) ;
    //cout << xSprite << " " << ySprite << endl;
    _spritesList[spriteName].setPosition(xSprite, ySprite);
    _window->draw(_spritesList[spriteName]);
    
}

void ViewGame::displayBackGround()
{
    displayInMazeCase(MAZE_SIZE-1, MAZE_SIZE-1, "exitLabel", EXIT_IMAGE_WIDTH, EXIT_IMAGE_HEIGHT);
}