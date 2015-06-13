#include "ViewGame.h"

using namespace std;
using namespace sf;

ViewGame::ViewGame() : View()
{

}

ViewGame::~ViewGame()
{
}

bool ViewGame::initSFML()
{
    //background
    _imagesList.insert(make_pair("background", sf::Image()));
    if (!_imagesList["background"].LoadFromFile(VIEWGAME_MAZE_BACKGROUND))
        return false;

    _spritesList.insert(make_pair("background", sf::Sprite()));
    _spritesList["background"].SetImage(_imagesList["background"]);
    _spritesList["background"].SetSubRect(sf::IntRect(0,0, VIEWGAME_MAZE_BACKGROUND_WIDTH, VIEWGAME_MAZE_BACKGROUND_HEIGHT));

    // player
    _imagesList.insert(make_pair("player", sf::Image()));
    if (!_imagesList["player"].LoadFromFile(VIEWGAME_IMAGE_PLAYER))
        return false;

    _spritesList.insert(make_pair("player", sf::Sprite()));
    _spritesList["player"].SetImage(_imagesList["player"]);
    _spritesList["player"].SetSubRect(sf::IntRect(0,0, PLAYER_WIDTH, PLAYER_HEIGHT));

    // zomby
    _imagesList.insert(make_pair("zomby", sf::Image()));
    if (!_imagesList["zomby"].LoadFromFile(VIEWGAME_IMAGE_ZOMBY))
        return false;

    _spritesList.insert(make_pair("zomby", sf::Sprite()));
    _spritesList["zomby"].SetImage(_imagesList["zomby"]);
    _spritesList["zomby"].SetSubRect(sf::IntRect(0,0, ZOMBY_WIDTH, ZOMBY_HEIGHT));


    // wall
    _imagesList.insert(make_pair("horizontalWall", sf::Image()));
    if (!_imagesList["horizontalWall"].LoadFromFile(VIEWGAME_IMAGE_WALL))
        return false;

    _spritesList.insert(make_pair("wall_h", sf::Sprite()));
    _spritesList["horizontalWall"].SetImage(_imagesList["horizontalWall"]);
    _spritesList["horizontalWall"].SetSubRect(sf::IntRect(0,0, WALL_WIDTH, WALL_HEIGHT));

    // wall
    _imagesList.insert(make_pair("verticalWall", sf::Image()));
    if (!_imagesList["verticalWall"].LoadFromFile(VIEWGAME_IMAGE_WALL))
        return false;

    _spritesList.insert(make_pair("verticalWall", sf::Sprite()));
    _spritesList["verticalWall"].SetImage(_imagesList["verticalWall"]);
    _spritesList["verticalWall"].SetSubRect(sf::IntRect(0,0, WALL_WIDTH, WALL_HEIGHT));


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

    // draw player
    _spritesList["player"].SetPosition(_modele->getPlayer()->getX(), _modele->getPlayer()->getY());
    _window->Draw(_spritesList["player"]);

    //draw zombies
    for (Enemy* enemy : *_modele->getEnemiesList())
    {
        _spritesList["zomby"].SetPosition(enemy->getX(), enemy->getY());
        _window->Draw(_spritesList["zomby"]);
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
    _window->Display();
}

