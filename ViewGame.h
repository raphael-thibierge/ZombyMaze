#ifndef VIEWGAME_H_INCLUDED
#define VIEWGAME_H_INCLUDED
#include "View.h"

class ViewGame : virtual public View {

private:
    unsigned int _cptSprites;

public:

    ViewGame();

    virtual ~ViewGame();

// METHODS
//

    int treatEventSFML() override;

    void showViewSFML() override;

    void displayPlayer();

    void displayEnnemies();

    void displayTrace();

    void displayMaze();

    bool initSFML();
};

#endif // VIEWGAME_H_INCLUDED
