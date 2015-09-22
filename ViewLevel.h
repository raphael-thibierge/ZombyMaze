//
//  ViewLevel.h
//  ZombyMaze2
//
//  Created by Raphael Thibierge on 25/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __ZombyMaze2__ViewLevel__
#define __ZombyMaze2__ViewLevel__

#include <stdio.h>
#include "View.h"

class ViewLevel : public virtual View
{   
    
    bool _buttonQuit;
    Menu _levelMenu;
    
public:
    ViewLevel();
    
    const int treatEventSFML() override;
    
    void showViewSFML() override;
    
    const bool initSFML() override;
    
    const bool initButtons() override;
    
    void displayButtons();
    
    void update() override;
    
};


#endif /* defined(__ZombyMaze2__ViewLevel__) */
