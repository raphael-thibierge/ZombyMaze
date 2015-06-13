#include "ViewGame.h"

using namespace std;

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
    if (!_imagesList["player"].LoadFromFile(VIEWGAME_IMAGE_PLAYER))
        return false;

    _spritesList.insert(make_pair("player", sf::Sprite()));
    _spritesList["player"].SetImage(_imagesList["player"]);
    _spritesList["player"].SetSubRect(sf::IntRect(0,0, PLAYER_WIDTH, PLAYER_HEIGHT));

    // zomby
    if (!_imagesList["zomby"].LoadFromFile(VIEWGAME_IMAGE_PLAYER))
        return false;

    _spritesList.insert(make_pair("zomby", sf::Sprite()));
    _spritesList["zomby"].SetImage(_imagesList["zomby"]);
    _spritesList["zomby"].SetSubRect(sf::IntRect(0,0, ZOMBY_WIDTH, ZOMBY_HEIGHT
    ));
    return true;
}


int ViewGame::treatEvent()
{
    return 0;
}

int ViewGame::treatEventSFML()
{
    return 1;
}

void ViewGame::showViewTerminal()
{
}
void ViewGame::showViewSFML()
{
    _window->Clear();
    _window->Draw(_spritesList["background"]);
    for (Enemy* enemy : _modele->getEnemiesList())
    {
        _spritesList["zomby"].SetPosition(enemy->getX(); enemy->getY());
        _window.Draw(_spritesList["zomby"]);
    }
    _window->Display();
}

