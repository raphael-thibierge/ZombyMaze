//
//  View.h
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 09/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __ShmupTerminal__View__
#define __ShmupTerminal__View__

#include <stdio.h>
#include "GameModel.h"
#include "const.h"



class View
{
protected: 
    GameModel* _modele;

    // SFML Window
    sf::RenderWindow * _window;

    std::map<std::string, sf::Sprite> _spritesList;
    std::map<std::string, sf::Texture> _imagesList;
    

// CONSTRUCTOR AND DESTRUCTOR
//
public :

    View();

    virtual ~View();

// METHODS
//
    // SFML VERSION

    virtual const int treatEventSFML();

    virtual void showViewSFML();
    
    virtual const bool initSFML();
    
    virtual const bool initButtons();

    void displayStandartButton( const std::string name, const float positionX, const float positionY, const bool active = false);

    void displayText( const std::string text, const float positionX, const float positionY);

    void displayTitle( const std::string text, const float positionX, const float positionY);

    const bool mouseOnButton(const int mouseX, const int mouseY, const int buttonX, const int buttonY, const int buttonWidth, const int buttonHeight);

    const bool init(GameModel* modele, sf::RenderWindow * window);

    
    const bool initSprite(const std::string name, const std::string image, const unsigned int nbSprites, const unsigned int spriteWitdh, const unsigned int spriteHeight);

};
#endif /* defined(__ShmupTerminal__View__) */