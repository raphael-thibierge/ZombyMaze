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
    _spritesList["background"].SetSubRect(sf::IntRect(0,0, 800, 800));
    _spritesList["background"].SetPosition(MAZE_X,MAZE_Y);

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
    _window->Display();
}

