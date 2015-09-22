//
//  ViewIntroduction.h
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 11/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __ShmupTerminal__ViewIntroduction__
#define __ShmupTerminal__ViewIntroduction__

#include "View.h"
#include <stdio.h>

class ViewIntroduction : public virtual View
{
private:
    sf::Clock _time;
    
    bool _end;
    
    int _zombyX;
    int _zombyY;
    int _playerX;
    int _playerY;
    int _cptSprite;
    

// CONSTRUCTOR AND DESTRUCTOR
//
public:

    ViewIntroduction();

    virtual ~ViewIntroduction();


// METHODS
//

    const int treatEventSFML() override;

    void showViewSFML() override;

    const bool initSFML() override;

    const bool initButtons() override;
    
    void update() override;
    
};



#endif /* defined(__ShmupTerminal__ViewIntroduction__) */
