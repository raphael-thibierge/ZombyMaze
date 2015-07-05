//
//  ViewMainMenu.h
//  ZombyMaze2
//
//  Created by Raphael Thibierge on 23/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __ZombyMaze2__ViewMainMenu__
#define __ZombyMaze2__ViewMainMenu__

#include <stdio.h>
#include "View.h"

class ViewMainMenu : public virtual View {
private:
    // button states
    bool _buttonPlay;
    bool _buttonQuit;
    bool _buttonTheme;
    bool _buttonLevel;
public:
    
    // CONSTRUCTOR
    
    ViewMainMenu();
    
    // METHODS
    
    const int treatEventSFML() override;
    
    void showViewSFML() override;
    
    const bool initSFML() override;
    
    const bool initButtons() override;
    
    void displayButtons();
    
    
    
   void updateButtons(const unsigned int mouseX, const unsigned int mouseY);
    
    
};


#endif /* defined(__ZombyMaze2__ViewMainMenu__) */
