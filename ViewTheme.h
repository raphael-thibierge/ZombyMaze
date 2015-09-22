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
    Menu _themeMenu;
    bool _buttonQuit;
    
    
public:
    ViewTheme();
    
    const int treatEventSFML() override;
    
    void showViewSFML() override;
    
    const bool initSFML() override;
    
    const bool initButtons() override;
    
    void update() override;
    
};

#endif /* defined(__ZombyMaze2__ViewTheme__) */
