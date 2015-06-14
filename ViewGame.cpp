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

    if (!initSprite("player", VIEWGAME_IMAGE_PLAYER, PLAYER_NB_SPRITES, PLAYER_WIDTH, PLAYER_HEIGHT))
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



    if (!initSprite("horizontalWall", VIEWGAME_IMAGE_WALL_H, 1, WALL_WIDTH_H, WALL_HEIGHT_H))
        return false;

    if (!initSprite("verticalWall", VIEWGAME_IMAGE_WALL_V, 1, WALL_WIDTH_V, WALL_HEIGHT_V))
        return false;

    return true;
}


int ViewGame::treatEventSFML()
{
    int returnValue = 1;
    Event event;
        while (_window->GetEvent(event))
        {
            switch (event.Type)
            {
                case Event::KeyPressed :
                    switch (event.Key.Code)
                    {

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

        const Input & input = _window->GetInput(); // input : const reference

        // MOVEMENT
        // UP
        if (input.IsKeyDown(Key::Up)){
            _modele->playerMove("up");
        }
        // DOWN
        if (input.IsKeyDown(Key::Down)){
            _modele->playerMove("down");
        }
        //LEFT
        if (input.IsKeyDown(Key::Left)){
            _modele->playerMove("left");
        }
        //RIGHT
        if (input.IsKeyDown(Key::Right)){
            _modele->playerMove("right");
        }
    return returnValue;
}

void ViewGame::showViewSFML()
{
    // clear windows
    _window->Clear();
    // draw background
    _window->Draw(_spritesList["background"]);

    displayMaze();

    displayEnnemies();

    displayTrace();

    displayPlayer();

    _cptSprites++;
    _window->Display();
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
        _spritesList[name].SetPosition(enemy->getX(), enemy->getY());
        _window->Draw(_spritesList[name]);
    }
}

void ViewGame::displayMaze()
{
    for (Wall* wall : *_modele->getWallsList())
    {

        switch (wall->getOrientation())
        {
            case 'v' :
                _spritesList["verticalWall"].SetPosition(wall->getX(), wall->getY());
                _window->Draw(_spritesList["verticalWall"]);
                break;

            case 'h' :
                _spritesList["horizontalWall"].SetPosition(wall->getX(), wall->getY());
                _window->Draw(_spritesList["horizontalWall"]);
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
                name += to_string(0);
            else
                name += to_string(_cptSprites % PLAYER_NB_SPRITES);
        }

        _spritesList[name].SetPosition(_modele->getPlayer()->getX(), _modele->getPlayer()->getY());
        _window->Draw(_spritesList[name]);

    }
}


void ViewGame::displayTrace()
{
    cout << _modele->getTracesList()->size() << endl;
    for (Trace* trace : *_modele->getTracesList())
    {
        _spritesList["trace"].SetPosition(trace->getX(), trace->getY());
        _window->Draw(_spritesList["trace"]);
    }
}
