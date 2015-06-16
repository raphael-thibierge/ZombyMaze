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
    
    void displayGameOver();
    
    void displayWin();

    bool initSFML();
    
    void displayBackGround();
    
    void displayInMazeCase(const unsigned int x, const unsigned int y, const std::string spriteName, const unsigned int width, const unsigned int height);
};

#endif // VIEWGAME_H_INCLUDED
