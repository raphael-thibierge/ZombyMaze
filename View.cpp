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
const bool View::init(GameModel* modele, sf::RenderWindow * window)
{
    _modele = modele;
    _window = window ;
    if (!initButtons())
        return false;
    if (!initSFML())
        return false;
    return true;
}

void View::displayStandartButton(const std::string name, const float positionX, const float positionY, bool active)
{
    
    string buttonName = "button_" + name;
    if (active)
    {
        buttonName += "1";
    }
    else
    {
        buttonName += "0";
    }
    _spritesList[buttonName].setPosition(positionX, positionY);
    _window->draw(_spritesList[buttonName]);
}

void View::displayText(const std::string text,const float positionX,const float positionY)
{
    sf::Font font;
    font.loadFromFile(resourcePath() + "sansation.ttf");
    sf::Text textDisplayed(text, font);
    textDisplayed.setCharacterSize(TEXT_SIZE);
    textDisplayed.setPosition(positionX, positionY);
    textDisplayed.setStyle(sf::Text::Bold);
    textDisplayed.setColor(sf::Color::White);
    _window->draw(textDisplayed);
}

void View::displayTitle( const std::string text, const float positionX, const float positionY)
{ 
    sf::Font font;
    font.loadFromFile(resourcePath() + "sansation.ttf");
    sf::Text textDisplayed(text, font);
    textDisplayed.setCharacterSize(TEXT_TITLE_SIZE);
    textDisplayed.setPosition(positionX, positionY);
    textDisplayed.setStyle(sf::Text::Bold);
    textDisplayed.setColor(sf::Color::White);
    _window->draw(textDisplayed);
}

const bool View::mouseOnButton
(const int mouseX, const int mouseY, const int buttonX, const int buttonY, const int buttonWidth, const int buttonHeight)
{ // return true if the mouse is on the button

    if (mouseX >= buttonX &&
        mouseX <= buttonX + buttonWidth &&
        mouseY >= buttonY &&
        mouseY <= buttonY + buttonHeight )
        return true;
    return false;
}

const bool View::initSprite(std:: string name, const std::string image, const unsigned int nbSprites, const unsigned int spriteWitdh, const unsigned int spriteHeight)
{
    // player
    _imagesList.insert(make_pair(name, sf::Texture()));
    if (!_imagesList[name].loadFromFile( resourcePath() + image))
        return false;
    
    string nameSprite = name;
    for ( unsigned int spriteNumber = 0 ; spriteNumber < nbSprites ; spriteNumber++ )
    {
        if (nbSprites > 1)
            nameSprite = name + to_string(spriteNumber);
        else
            nameSprite = name;
        
        _spritesList.insert(make_pair(nameSprite, sf::Sprite()));
        _spritesList[nameSprite].setTexture(_imagesList[name]);
        _spritesList[nameSprite].setTextureRect(sf::IntRect(spriteNumber*spriteWitdh,0, spriteWitdh, spriteHeight));
    }
    return true;
}

const void View::transformMousePosition(unsigned int &mouseX, unsigned int &mouseY)
{
    sf::Vector2u windowSize = _window->getSize();
    // if windows has been resized, we adapte mouse position
    if (windowSize.x != WINDOW_WIDTH || windowSize.y != WINDOW_HEIGHT)
    {
        mouseX = ( mouseX * WINDOW_WIDTH  ) / windowSize.x;
        mouseY = ( mouseY * WINDOW_HEIGHT ) / windowSize.y ;
    }

}

const int View::treatEventSFML()
{
    return 1;
}

void View::showViewSFML(){}

const bool View::initSFML()
{
    return true ;
}

const bool View::initButtons()
{
    return false;
}