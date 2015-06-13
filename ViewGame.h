#ifndef VIEWGAME_H_INCLUDED
#define VIEWGAME_H_INCLUDED
#include "View.h"

class ViewGame : virtual public View {

public:
    ViewGame();

    virtual ~ViewGame();

// METHODS
//
    int treatEvent() override;
    int treatEventSFML() override;

    void showViewTerminal() override;
    void showViewSFML() override;

    bool initSFML();
};


#endif // VIEWGAME_H_INCLUDED
