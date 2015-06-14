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

    if (!initSprite("zomby", VIEWGAME_IMAGE_ZOMBY, ZOMBY_NB_SPRITES, ZOMBY_WIDTH, ZOMBY_WIDTH))
        return false;

    if (!initSprite("horizontalWall", VIEWGAME_IMAGE_WALL, 1, WALL_WIDTH, WALL_HEIGHT))
        return false;

    if (!initSprite("verticalWall", VIEWGAME_IMAGE_WALL, 1, WALL_WIDTH, WALL_HEIGHT))
        return false;

    return true;
}


int ViewGame::treatEvent()
{
    return 0;
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

void ViewGame::showViewTerminal()
{
}
void ViewGame::showViewSFML()
{
    // clear windows
    _window->Clear();
    // draw background
    _window->Draw(_spritesList["background"]);

    string name;

    // draw player
    if (_modele->getPlayer() != nullptr)
    {
        name = "player" ;
        if (PLAYER_NB_SPRITES > 1)
        {
            name += to_string(_cptSprites % PLAYER_NB_SPRITES);
        }
        _spritesList[name].SetPosition(_modele->getPlayer()->getX(), _modele->getPlayer()->getY());
        _window->Draw(_spritesList[name]);
    }


    //draw zombies
    name = "zomby" ;
    if (ZOMBY_NB_SPRITES > 1)
    {
        name += to_string(_cptSprites % ZOMBY_NB_SPRITES);
    }

    for (Enemy* enemy : *_modele->getEnemiesList())
    {
        _spritesList[name].SetPosition(enemy->getX(), enemy->getY());
        _window->Draw(_spr)
        cout << enemy->getX() << " " << enemy->getY() << endl;
    }

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
                cout << "mur inconnu" << endl;
                break;

        }
    }

    // draw
    _cptSprites++;
    _window->Display();
}

