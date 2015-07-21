//
//  Button.h
//  
//
//  Created by Raphael Thibierge on 15/07/2015.
//
//

#ifndef ____Button__
#define ____Button__

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GraphicsElement.h"
#include "ResourcePath.hpp"


class Button : public sf::Sprite {
private:
    std::string _name;
    std::string _text;
    
    int _width;
    int _height;
    
    sf::Texture _picture;
    
    // states
    bool _active;
    
public:
    Button(const std::string name, const std::string text, const unsigned int x, const unsigned int y);
    
    Button(const std::string name, const std::string fileName, const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height);
    
    
    
    void update(const unsigned int mouseX, const unsigned int mouseY);
    
    // METHODS
    
    bool mouseOnButton(const unsigned int mouseX, const unsigned int mouseY) const; 
    
    // ACCESSORS
    
    void setText(const std::string text) { _text = text ;}
    
    void setName(const std::string name) { _name = name;}
    
    void setPicture(const std::string fileName, const unsigned int width, const unsigned int height);
    
    void setWidth(const unsigned int width) { _width = width; }
    
    void setHeight(const unsigned int height){ _height = height;}
    
    std::string getText() const { return _text;}
    
    std::string getName() const { return _name;}
    
    bool getActive() const { return _active; }
    
    const unsigned int getWidth() const { return _width;};
    
    const unsigned int getHeight() const { return _height;};
    
    
    // STATIC METHODS
public:
    static Button standartButton(std::string text);
    
    static Button pictureButton(std::string filename, const unsigned int    whidth, const unsigned int height);
    
    
};

#endif /* defined(____Button__) */
