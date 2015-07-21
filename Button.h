//
//  Button.h
//  ZombyMaze2
//
//  Created by Raphael Thibierge on 08/07/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __ZombyMaze2__Button__
#define __ZombyMaze2__Button__
#include "GraphicsElement.h"
#include <stdio.h>

class Button : public GraphicElement {
    std::string _name;
    std::string _text;
    
public:
    Button(const std::string name, const std::string text);
    
    
// METHODS
    
    bool mouseOnButton(const unsigned int mouseX, const unsigned int mouseY) const;
    
    
    
// ACCESSORS
    
    void setText(const std::string text) { _text = text ;}
    
    void setName(const std::string name) { _name = name;}
    
    std::string getText() const { return _text;}
    
    std::string getName() const { return _name;}
    
    
    
    
    
};

#endif /* defined(__ZombyMaze2__Button__) */
