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

    void displayMaze();
    
    void displayMazeCase();
    
    void displayGameOver();
    
    void displayWin();
    
    void displayBullets();

    bool initSFML() override;
    
    void displayBackGround();
    
    void displayInMazeCase(const unsigned int x, const unsigned int y, const std::string spriteName, const unsigned int width, const unsigned int height);
    
    bool initButtons() override;
};

#endif // VIEWGAME_H_INCLUDED
