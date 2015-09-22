//
//  Menu.cpp
//  MenuSFML
//
//  Created by Raphael Thibierge on 15/07/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "Menu.h"

using namespace std;

Menu::Menu(const unsigned int width, const unsigned int height) : sf::RenderTexture(), GraphicElement()
{
    _width = width;
    _height = height;
    
    _isMosaic = false;
    _nbColumn = 0;
    
    if (!create(_width, _height))
        cout << "error at creating menu" << endl;
}


Menu::Menu(Menu const &menu) : sf::RenderTexture(), GraphicElement()
{
    _width = menu.getWidth();
    _height = menu.getHeight();
    _isMosaic = menu._isMosaic;
    _nbColumn = menu._nbColumn;
    
    if (!create(_width, _height))
        cout << "error at creating menu" << endl;
    
    if (_isMosaic)
    {
        _buttonList.clear();
        unsigned int numberOfButtons = menu._buttonList.size();
       // createMosaic(numberOfButtons, menu._nbColumn);
    }
}


// PUBLIC METHODS

sf::Text displayText(const std::string text,const float positionX,const float positionY)
{
    sf::Font font;
    font.loadFromFile(resourcePath() + "sansation.ttf");
    sf::Text textDisplayed(text, font);
    textDisplayed.setCharacterSize(30);
    textDisplayed.setPosition(positionX, positionY);
    textDisplayed.setStyle(sf::Text::Bold);
    textDisplayed.setColor(sf::Color::White);
    
    return textDisplayed;
}


void Menu::update(unsigned int mouseX, unsigned int mouseY)
{
    mouseX -= _X;
    mouseY -= _Y;
    clear(sf::Color::Transparent);
    
    for (auto button : _buttonList)
    {
        button.second->update(mouseX, mouseY);
        
        int bX = button.second->getPosition().x;
        int bY = button.second->getPosition().y;
        int bW = button.second->getWidth();
        int bH =  button.second->getHeight();
        
        int size = 60;
        
        
        draw(*button.second);
        sf::Font font;
        
        if (button.second->getAvailable())
        {
            font.loadFromFile(resourcePath() + "sansation.ttf");
            sf::Text textDisplayed(button.second->getText(), font);
            textDisplayed.setCharacterSize(size);
            
            textDisplayed.setStyle(sf::Text::Bold);
            textDisplayed.setColor(sf::Color::White);
            
            int x = bX + 20;
            int y = bY + (bH - size)/2 ;
            textDisplayed.setPosition(x, y);
            
            draw(textDisplayed);
        }
    }
    
    display();
}


void Menu::standartUpdate()
{
    clear(sf::Color::Transparent);
    
    for (auto button : _buttonList)
    {
        button.second->standartUpdate();
        
        int bX = button.second->getPosition().x;
        int bY = button.second->getPosition().y;
        int bW = button.second->getWidth();
        int bH =  button.second->getHeight();
        
        int size = 60;
        
        
        draw(*button.second);
        sf::Font font;
        
        if (button.second->getAvailable())
        {
            font.loadFromFile(resourcePath() + "sansation.ttf");
            sf::Text textDisplayed(button.second->getText(), font);
            textDisplayed.setCharacterSize(size);
            
            textDisplayed.setStyle(sf::Text::Bold);
            textDisplayed.setColor(sf::Color::White);
            
            int x = bX + 20;
            int y = bY + (bH - size)/2 ;
            textDisplayed.setPosition(x, y);
            
            draw(textDisplayed);
        }
    }

    
    display();
}



void Menu::addStandartButton(std::string name, std::string text, const unsigned int x, const unsigned int y)
{
    _buttonList.insert(make_pair(name, new Button(name, text, x, y)));
}

void Menu::addPictureButton(std::string name, std::string filename, const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height)
{
    _buttonList.insert(make_pair(name ,new Button(name, filename, x, y, width, height)));
}

void Menu::createMosaic(const unsigned int nbButton, const unsigned int nbColumn)
{
    string name = "mosaic";
    unsigned int cpt = 0;
    unsigned int between = ( getWidth() - ( nbColumn * 100) ) / ( nbColumn + 1);
    
    unsigned int line = 0;
    while (line <= nbButton/nbColumn )
    {
        unsigned int column = 0 ;
        while ( column < nbColumn && cpt < nbButton )
        {
            cpt++;
            int x = between * ( column + 1 ) + column * 100 ;
            int y = between * ( line + 1 ) + line * 100;
            addStandartButton(name + to_string(cpt), to_string(cpt), x, y);
            column++;
        }
        line++;
    }
    
    _isMosaic = true;
    _nbColumn = nbColumn;
    
}


// PRIVATE METHODS

// ACCESSOR METHODS

sf::Sprite Menu::getSprite()
{
    _sprite.setTexture(getTexture());
    _sprite.setPosition(_X, _Y);
    return _sprite;
}

const bool Menu::getButtonActive(const std::string name) const
{
    for (auto buttonPair : _buttonList)
    {
        if (buttonPair.first == name)
        {
            return buttonPair.second->getActive();
        }
    }
    return false;
}

Button * Menu::getButtonClicked()
{
    for (auto button : _buttonList)
    {
        if (button.second->getActive() && button.second->getAvailable())
        {
            return button.second;
        }
    }
    return nullptr;
}


Button * Menu::forceGetButtonClicked()
{
    for (auto button : _buttonList)
    {
        if (button.second->getActive())
        {
            return button.second;
        }
    }
    return nullptr;
}


