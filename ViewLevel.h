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
    bool _buttonLevel1;
    bool _buttonLevel2;
    bool _buttonQuit;
    
    
public:
    ViewLevel();
    
    int treatEventSFML() override;
    
    void showViewSFML() override;
    
    bool initSFML() override;
    
    bool initButtons() override;
    
     void updateButtons(const unsigned int mouseX, const unsigned int mouseY);
    
    void displayButtons();
    
};


#endif /* defined(__ZombyMaze2__ViewLevel__) */
