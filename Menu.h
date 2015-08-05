//
//  Menu.h
//  MenuSFML
//
//  Created by Raphael Thibierge on 15/07/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __MenuSFML__Menu__
#define __MenuSFML__Menu__

#include <stdio.h>
#include <vector>
#include <map>
#include "Button.h"


class Menu : public sf::RenderTexture, public GraphicElement
{
// ATTRIBUTES
private:
    std::map<std::string, Button*> _buttonList ;
    sf::Sprite _sprite;
    bool _isMosaic;
    unsigned int _nbColumn ;
    
public:
    Menu(const unsigned int width, const unsigned int height);
    
    Menu(Menu const &menu);
    
    
    
// PUBLIC METHODS
public:
    void update(unsigned int mouseX, unsigned int mouseY);
    
    void addStandartButton(std::string name, std::string text, const unsigned int x, const unsigned int y);
    
    void addPictureButton(std::string name, std::string filename, const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height);
    
    void createMosaic(const unsigned int nbButton, const unsigned int nbColumn);
    
    
// PRIVATE METHODS
private:
    
// accessors
public:
    
    sf::Sprite getSprite();
    
    const bool getButtonActive(const std::string name) const;
    
    Button * getButtonClicked();

};



#endif /* defined(__MenuSFML__Menu__) */
