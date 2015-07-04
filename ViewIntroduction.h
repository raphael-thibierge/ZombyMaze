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

    int treatEventSFML() override;

    void showViewSFML() override;

    bool initSFML() override;

    bool initButtons() override;
    
};



#endif /* defined(__ShmupTerminal__ViewIntroduction__) */
