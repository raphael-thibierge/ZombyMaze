//
//  View.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 09/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "View.h"

using namespace std;
//
// CONSTRUCTOR AND DESTRUCTOR
//
View::View(){}

View::~View(){
    _modele = nullptr;
    _window = nullptr;

}


//
// METHODS
//


bool View::init(GameModel* modele, sf::RenderWindow * window)
{
    _modele = modele;
    _window = window ;
    if (!initButtons())
        return false;
    if (!initSFML())
        return false;
    return true;
}

void View::displayStandartButton(const std::string text, const float positionX, const float positionY, bool active)
{
    /*
    if (active)
    {
        _spritesList["standartButton_active"].SetPosition(positionX, positionY);
        _window->Draw(_spritesList["standartButton_active"]);
    }

    else
    {
        _spritesList["standartButton"].SetPosition(positionX, positionY);
        _window->Draw(_spritesList["standartButton"]);
    }
    //_window->Draw(_spritesList["standartButton"]);

     displayText(text, positionX + 40, positionY+(BUTTON_HEIGHT - TEXT_SIZE)/2 - 5);
    */
}

void View::displayText(const std::string text,const float positionX,const float positionY)
{
    /*
    sf::String textDisplayed;
    textDisplayed.SetText(text);
    textDisplayed.SetSize(TEXT_SIZE);
    textDisplayed.SetPosition(positionX, positionY);
    _window->Draw(textDisplayed);
    */
}

void View::displayTitle( const std::string text, const float positionX, const float positionY)
{
    displayText(text, positionX, positionY);
}



bool View::mouseOnButton
(const int mouseX, const int mouseY, const int buttonX, const int buttonY, const int buttonWidth, const int buttonHeight)
{ // return true if the mouse is on the button

    if (mouseX >= buttonX &&
        mouseX <= buttonX + buttonWidth &&
        mouseY >= buttonY &&
        mouseY <= buttonY + buttonHeight )
        return true;
    return false;
}

bool View::initButtons()
{
/*
    // STANDART BUTTON
        //buttons's image
    _imagesList.insert(make_pair("standartButtons", sf::Image()));
    if (!_imagesList["standartButtons"].LoadFromFile(IMAGE_BUTTONS))
        return false;

    _imagesList.insert(make_pair("standartButtonsActive", sf::Image()));
    if (!_imagesList["standartButtonsActive"].LoadFromFile(IMAGE_BUTTONS_ACTIVE))
        return false;

    // standart button
    _spritesList.insert(make_pair("standartButton", sf::Sprite()));
    _spritesList["standartButton"].SetImage(_imagesList["standartButtons"]);
    _spritesList["standartButton"].SetSubRect(sf::IntRect(0, 0, BUTTON_WIDTH + BUTTON_SPRITE_X , BUTTON_HEIGHT + BUTTON_SPRITE_Y));

    // standart active button
    _spritesList.insert(make_pair("standartButton_active", sf::Sprite()));
    _spritesList["standartButton_active"].SetImage(_imagesList["standartButtonsActive"]);
    _spritesList["standartButton_active"].SetSubRect(sf::IntRect(0, 0, BUTTON_WIDTH + BUTTON_SPRITE_ACTIVE_X , BUTTON_HEIGHT + BUTTON_SPRITE_ACTIVE_Y));
*/
    return true;
}



