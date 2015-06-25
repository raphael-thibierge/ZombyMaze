//
//  ViewTheme.h
//  ZombyMaze2
//
//  Created by Raphael Thibierge on 25/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __ZombyMaze2__ViewTheme__
#define __ZombyMaze2__ViewTheme__
#include "View.h"

#include <stdio.h>
class ViewTheme : public virtual View
{
    bool _buttonTheme1;
    bool _buttonTheme2;
    bool _buttonQuit;
    
    
public:
    ViewTheme();
    
    int treatEventSFML() override;
    
    void showViewSFML() override;
    
    bool initSFML() override;
    
    bool initButtons() override;
    
    void updateButtons(const unsigned int mouseX, const unsigned int mouseY);
    
    void displayButtons();
    
};

#endif /* defined(__ZombyMaze2__ViewTheme__) */
