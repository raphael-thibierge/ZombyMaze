//
//  Button.cpp
//  ZombyMaze2
//
//  Created by Raphael Thibierge on 08/07/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "Button.h"


Button::Button(const std::string name, const std::string text) : GraphicElement(), _name(name), _text(text)
{}

bool Button::mouseOnButton(const unsigned int mouseX, const unsigned int mouseY) const
{
    return pointOnElement(mouseX, mouseY);
}