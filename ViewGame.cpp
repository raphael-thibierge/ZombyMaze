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

const bool ViewGame::initSFML()
{
    _imagesList.clear();
    _spritesList.clear();
    
    unsigned int number = _modele->getPlayer()->getTheme() - 1;
    
        //background
    if (!initSprite("background", VIEWGAME_MAZE_BACKGROUND[number], 1, VIEWGAME_MAZE_BACKGROUND_WIDTH, VIEWGAME_MAZE_BACKGROUND_HEIGHT))
        return false;
    
        // exit
    if (!initSprite("exitLabel", EXIT_IMAGE, 1, EXIT_IMAGE_WIDTH, EXIT_IMAGE_HEIGHT))
        return false;

    // player
    if (!initSprite("playerup", VIEWGAME_IMAGE_PLAYER_UP[number], PLAYER_NB_SPRITES, PLAYER_WIDTH, PLAYER_HEIGHT))
        return false;
    if (!initSprite("playerdown", VIEWGAME_IMAGE_PLAYER_DOWN[number], PLAYER_NB_SPRITES, PLAYER_WIDTH, PLAYER_HEIGHT))
        return false;
    if (!initSprite("playerleft", VIEWGAME_IMAGE_PLAYER_LEFT[number], PLAYER_NB_SPRITES, PLAYER_WIDTH, PLAYER_HEIGHT))
        return false;
    if (!initSprite("playerright", VIEWGAME_IMAGE_PLAYER_RIGHT[number], PLAYER_NB_SPRITES, PLAYER_WIDTH, PLAYER_HEIGHT))
        return false;

    // ZOMBY
    if (!initSprite("zombyleft", VIEWGAME_IMAGE_ZOMBY_LEFT[number], ZOMBY_NB_SPRITES, ZOMBY_WIDTH, ZOMBY_HEIGHT))
        return false;
    if (!initSprite("zombyright", VIEWGAME_IMAGE_ZOMBY_RIGHT[number], ZOMBY_NB_SPRITES, ZOMBY_WIDTH, ZOMBY_HEIGHT))
        return false;
    if (!initSprite("zombyup", VIEWGAME_IMAGE_ZOMBY_UP[number], ZOMBY_NB_SPRITES, ZOMBY_WIDTH, ZOMBY_HEIGHT))
        return false;
    if (!initSprite("zombydown", VIEWGAME_IMAGE_ZOMBY_DOWN[number], ZOMBY_NB_SPRITES, ZOMBY_WIDTH, ZOMBY_HEIGHT))
        return false;

    // TRACES
    if (!initSprite("traceup", TRACE_IMAGE_UP[number], TRACE_NB_SPRITES, TRACE_WIDTH, TRACE_HEIGHT))
        return false;
    
    if (!initSprite("tracedown", TRACE_IMAGE_DOWN[number], TRACE_NB_SPRITES, TRACE_WIDTH, TRACE_HEIGHT))
        return false;
    
    if (!initSprite("traceleft", TRACE_IMAGE_LEFT[number], TRACE_NB_SPRITES, TRACE_HEIGHT, TRACE_WIDTH))
        return false;
    
    if (!initSprite("traceright", TRACE_IMAGE_RIGHT[number], TRACE_NB_SPRITES, TRACE_HEIGHT, TRACE_WIDTH))
        return false;



    // walls
    if (!initSprite("horizontalWall", VIEWGAME_IMAGE_WALL_H[number], 1, WALL_WIDTH_H, WALL_HEIGHT_H))
        return false;

    if (!initSprite("verticalWall", VIEWGAME_IMAGE_WALL_V[number], 1, WALL_WIDTH_V, WALL_HEIGHT_V))
        return false;
    
    // gameOver
    if (!initSprite("gameOver", GAMEOVER_IMAGE, 1, GAMEOVER_IMAGE_WIDTH, GAMEOVER_IMAGE_HEIGHT))
        return false;
    
    // win
    if (!initSprite("win", WIN_IMAGE, 1, WIN_IMAGE_WIDTH, WIN_IMAGE_HEIGHT))
        return false;
    
    // BULLETS
    if (!initSprite("bulletleft", BULLET_IMAGE_LEFT[number], 1, BULLET_WIDTH, BULLET_HEIGHT))
        return false;
    
    if (!initSprite("bulletright", BULLET_IMAGE_RIGHT[number], 1, BULLET_WIDTH, BULLET_HEIGHT))
        return false;
    
    if (!initSprite("bulletup", BULLET_IMAGE_UP[number], 1, BULLET_HEIGHT, BULLET_WIDTH))
        return false;
    
    if (!initSprite("bulletdown", BULLET_IMAGE_DOWN[number], 1, BULLET_HEIGHT, BULLET_WIDTH))
        return false;
    
    // temoin
    if (!initSprite("temoin", TEMOIN_IMAGE, 1, MAZECASE_SIZE, MAZECASE_SIZE))
        return false;
    
    // coin
    if (!initSprite("coin", COIN_IMAGE, 1, COIN_WIDTH, COIN_HEIGHT))
        return false;
    
    // gun
    if (!initSprite("gun", GUN_IMAGE, 1, GUN_WIDTH, GUN_HEIGHT))
        return false;
    if (!initSprite("gun_unavailable", GUN_IMAGE_UNAVAILABLE, 1, GUN_WIDTH, GUN_HEIGHT))
        return false;
    
    // boost
    if (!initSprite("boost", BOOST_IMAGE, 1, BOOST_WIDTH, BOOST_HEIGHT))
        return false;
    if (!initSprite("boost_unavailable", BOOST_IMAGE_UNAVAILABLE, 1, BOOST_WIDTH, BOOST_HEIGHT))
        return false;
    
    // shield
    if (!initSprite("shield", SHIELD_IMAGE, 1, SHIELD_WIDTH, SHIELD_HEIGHT))
        return false;
    if (!initSprite("shield_unavailable", SHIELD_IMAGE_UNAVAILABLE, 1, SHIELD_WIDTH, SHIELD_HEIGHT))
        return false;
    
    // column info
    if (!initSprite("columnInfo", COLUMN_INFO_IMAGE[number], 1, COLUMN_INFO_WIDTH, COLUMN_INFO_HEIGHT))
        return false;
    
    cout << "Sprites initialisés" << endl;

    return true;
}


const int ViewGame::treatEventSFML()
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
                    returnValue = 0;
                    break;
                    
                case sf::Keyboard::R:
                    _modele->reset();
                    break;
                    
                case sf::Keyboard::A:
                    _modele->getPlayer()->useBoost();
                    break;
                
                case sf::Keyboard::E:
                    _modele->getPlayer()->useShield();
                    break;
                
                    
        
                case sf::Keyboard::Space:
                    if (_modele->getLoose())
                    {
                        _modele->getLevel()->reset();
                        //_modele->setPlayStop();
                    }
                    else if (_modele->getWin() )
                    {
                        if (_modele->getPlayer()->getLevel() == LEVEL_MAX)
                            returnValue = -3;
                        else
                            _modele->nextLevel();
                    }
                    else
                    {
                        _modele->setPlayStop();
                    }
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
    }
    else
    {
        displayBackGround();
        
        displayColumn();
        
        displayMaze();
        
        displayMazeCase();
        
        displayEnnemies();
        
        displayPlayer();
        
        displayBullets();
        
    }
}

void ViewGame::displayEnnemies()
{
    string name ;
    for (Enemy* enemy : *_modele->getEnemiesList())
    {
        name = "zomby";
        name += enemy->getDirection();
        if (ZOMBY_NB_SPRITES > 1)
        {
            name += to_string(_cptSprites % ZOMBY_NB_SPRITES);
        }
        _spritesList[name].setPosition(enemy->getX(), enemy->getY());
        _window->draw(_spritesList[name]);
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
        string name = "bullet" + bullet->getDirection();
        _spritesList[name].setPosition(bullet->getX(), bullet->getY());
        _window->draw(_spritesList[name]);
    }
}

void ViewGame::displayInMazeCase(const unsigned int x, const unsigned int y, const std::string spriteName, const unsigned int width, const unsigned int height)
{
    unsigned int xSprite ;
    unsigned int ySprite ;
    
    xSprite = x * (MAZECASE_SIZE)  ;
    ySprite = y * (MAZECASE_SIZE) ;
    _spritesList[spriteName].setPosition(xSprite, ySprite);
    _window->draw(_spritesList[spriteName]);
    
}

void ViewGame::displayBackGround()
{
    // draw background
    _window->draw(_spritesList["background"]);

    for (BackgroundElement element : *_modele->getBackgroundElements())
    {
        if (element.getName() == "out")
        {
            _spritesList["exitLabel"].setPosition(element.getX(), element.getY());
            _window->draw(_spritesList["exitLabel"]);
        }
    }
}


void ViewGame::displayMazeCase()
{
    for (PowerUp* powerUp : *_modele->getPowersUp())
    {
        if (powerUp->getAvailable())
        {
            string name = powerUp->getName();
            _spritesList[name].setPosition(powerUp->getX(), powerUp->getY());
            _window->draw(_spritesList[name]);
        }
    }
    
    for (MazeCase* mazeCase : *_modele->getMazeCaseList())
    {

        Trace * trace = mazeCase->getTrace();
        if (trace->available())
        {
            mazeCase->place(trace);
            string name = "trace" + trace->getDirection();
            _spritesList[name].setPosition(trace->getX(), trace->getY());
            _window->draw(_spritesList[name]);
        }
    }
    
    for (Coin* coin : *_modele->getLevel()->getCoinList())
    {
        if (coin != nullptr)
        {
            _spritesList["coin"].setPosition(coin->getX(), coin->getY());
            _window->draw(_spritesList["coin"]);
        }
    }
    
}

const bool ViewGame::initButtons()
{
    return true;
}

void ViewGame::displayColumn()
{
    _spritesList["columnInfo"].setPosition(COLUMN_INFO_X, COLUMN_INFO_Y);
    _window->draw(_spritesList["columnInfo"]);
    
    //Others
    if (_modele->getPlayer() != nullptr);
    displayText(to_string(_modele->getPlayer()->getMoney()), COLUMN_INFO_TEXT_X, INFO_MONEY_Y);
    if (_modele->getPlayStop())
        _cptSprites++;
    
    
    // time
    string time = to_string(_modele->getLevel()->getTime().asSeconds());
    string newTime;
    
    unsigned int cpt = 0;
    do
    {
        newTime += time[cpt];
        cpt++;
        
    } while (time[cpt] != '.' && cpt < time.length());
    for (unsigned int i = 0 ; i <= 1 ; i++)
    {
        newTime+= time[cpt+i];
    }
    
    if (_modele->getLevel() != nullptr)
        displayText(newTime, COLUMN_INFO_TEXT_X, INFO_CRONO_Y);
    
    if (_modele->getPlayer() != nullptr)
        displayText(to_string(_modele->getPlayer()->getAmmo()), COLUMN_INFO_TEXT_X, INFO_AMMO_Y);
    
    if (_modele->getLevel() != nullptr)
        displayText(to_string(_modele->getLevel()->getRetry()), COLUMN_INFO_TEXT_X, INFO_NB_RESTART);
    
    // BONNUS BOOST
    if (_modele->getPlayer()->getBoost())
    {
        _spritesList["boost"].setPosition(900, 700);
        _window->draw(_spritesList["boost"]);
        
        //  boost life
        if (_modele->getPlayer()->getBoostActivated())
        {
            sf::Time time = PLAYER_BOOST_LIFE -_modele->getPlayer()->getBoostTime();
            int timeF = time.asSeconds()+1;
            if (timeF >  PLAYER_BOOST_LIFE.asSeconds())
            {
                timeF--;
            }
            
            string text = to_string(timeF);
            text = text[0];
            displayText(text, 911, 750);
        }
        else
            displayText("A", 910, 750);
    }
    else
    {
        _spritesList["boost_unavailable"].setPosition(900, 700);
        _window->draw(_spritesList["boost_unavailable"]);
    }
    

    
    // BONNUS GUN
    if (_modele->getPlayer()->getGun())
    {
        _spritesList["gun"].setPosition(1000, 700);
        _window->draw(_spritesList["gun"]);
    }
    else
    {
        _spritesList["gun_unavailable"].setPosition(1000, 700);
        _window->draw(_spritesList["gun_unavailable"]);
    }

    
        // BONNUS SHIELD
    if (_modele->getPlayer()->getShield())
    {
        _spritesList["shield"].setPosition(1100, 700);
        _window->draw(_spritesList["shield"]);
        
        // shield life
        if (_modele->getPlayer()->getShieldActivated())
        {
            sf::Time time = PLAYER_SHIELD_LIFE -_modele->getPlayer()->getShieldTime();
            int timeF = time.asSeconds()+1;
            if (timeF >  PLAYER_SHIELD_LIFE.asSeconds())
            {
                timeF--;
            }
            string text = to_string(timeF);
            text = text[0];
            displayText(text, 1111, 750);
        }
        else
            displayText("E", 1110, 750);
    }
    else
    {
        _spritesList["shield_unavailable"].setPosition(1110, 700);
        _window->draw(_spritesList["shield_unavailable"]);
    }


}