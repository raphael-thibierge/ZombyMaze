//
//  Button.cpp
//  
//
//  Created by Raphael Thibierge on 15/07/2015.
//
//

#include "Button.h"

using namespace std;

Button::Button(const std::string name, const std::string text, const unsigned int x, const unsigned int y) : sf::Sprite(), _name(name), _text(text)
{
    // init states
    _active = false;
    _available = true;
    
    // provisional
    _width = 100;
    _height = 100;
    
    //loading button picture
    setPicture(resourcePath() + "ButtonNew.png" , _width, _height);
    setPosition(x, y);

}

Button::Button(const std::string name, const std::string fileName, const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height) : sf::Sprite(), _name(name), _width(width), _height(height)
{
    // init states
    _active = false;
    
    //loading button picture
    setPicture(fileName , _width, _height);
    setPosition(x, y);
    
}


void Button::update(const unsigned int mouseX, const unsigned int mouseY)
{

    _active = mouseOnButton(mouseX, mouseY);
    
    if (_active && _available )
    {
        setTextureRect(sf::IntRect(_width, 0, _width, _height));
    }
    else if (_available)
    {
        setTextureRect(sf::IntRect(0, 0, _width, _height));
    }
    else
    {
        setTextureRect(sf::IntRect(_width*2, 0, _width, _height));
    }
}

void Button::standartUpdate()
{
    if (_active && _available )
    {
        setTextureRect(sf::IntRect(_width, 0, _width, _height));
    }
    else if (_available)
    {
        setTextureRect(sf::IntRect(0, 0, _width, _height));
    }
    else
    {
        setTextureRect(sf::IntRect(_width*2, 0, _width, _height));
    }

}


bool Button::mouseOnButton(const unsigned int mouseX, const unsigned int mouseY) const
{
    return (getPosition().x <= mouseX && getPosition().x + _width >= mouseX && getPosition().y <= mouseY && getPosition().y + _height >= mouseY) ; // pointOnElement(mouseX, mouseY*/);
}

void Button::setPicture(const std::string fileName, const unsigned int width, const unsigned int height)
{
    _width = width;
    _height = height;
    _picture.loadFromFile(fileName);
    setTexture(_picture);
    setTextureRect(sf::IntRect(0, 0, _width, _height));

}

// STATIC METHODS
Button Button::standartButton(std::string text)
{
    string name = "standartButton";
    
    return Button(name, text, 0, 0);
}

Button Button::pictureButton(std::string filename, const unsigned int    width, const unsigned int height)
{
    Button button = Button("picture", " ", 0, 0);
    button.setPicture(filename , width, height);
    return button;
}