//
//  ViewsController.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 11/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "ViewsController.h"
#include "ViewIntroduction.h"


using namespace std;

//
// CONSTRUCTOR AND DESTRUCTOR
//
ViewsController::ViewsController(sf::RenderWindow* window) : _mainWindow(window)
{

    
    _allViews.insert(make_pair("Game", &_game));
    _allViews.insert(make_pair("Introduction", new ViewIntroduction()));
    _allViews.insert(make_pair("MainMenu", new ViewMainMenu()));
    _allViews.insert(make_pair("Level", new ViewLevel()));
    _allViews.insert(make_pair("Theme", new ViewTheme()));
    _mainWindow = window;

}

bool ViewsController::init(GameModel *modele){
    //initisilisation of the controller and views
    _modele = modele;
    _quit = false;
    
    for (auto view : _allViews)
    {
        if (!view.second->init(_modele, _mainWindow))
        {
            cout << view.first << endl;
            return false;
        }
    }
    // at beginning of the program, it's the introduction view
    _view = _allViews["Introduction"];
    return true;
}


ViewsController::~ViewsController(){
    _modele = nullptr;
    _view = nullptr;
    _mainWindow = nullptr;
    _allViews.clear();
}


//
// METHODS
//
bool ViewsController::treatEvent(){
    //return true if the player doesn't quit the game

    // switch between the different views

    // return of the treatment in active view
    switch (_view->treatEventSFML()) {

        case 1:// every things is ok
            break;

        case 0: // quit active vie
            if (_view != _allViews["MainMenu"])
                _view = _allViews["MainMenu"];
            else forceQuit();
            break;

            // change of view
            //
        case -1:
             _view = _allViews["Introduction"];
            break;

        case -2:
            _view = _allViews["Game"];
            _view->initSFML();
            break;
            
        case -3 :
            _view = _allViews["MainMenu"];
            break;
        
        case -4 :
            _view = _allViews["Level"];
            break;
            
        case -5:
            _view = _allViews["Theme"];
            break;

        case 111:
            forceQuit();
            break;

        default:
            break;
    }

    return !_quit;
}

void ViewsController::showView(){
    //show active view

    if (_mainWindow != nullptr && _modele != nullptr && _view != nullptr)
    {
        _view->showViewSFML();
    }
    else
        cout << __FUNCTION__ << " modele, fenfetre ou vue active inexistante" << endl;
}

void ViewsController::changeView(string view){
    // change active view
    _view = _allViews[view];
}

void ViewsController::quit(){
    // qui the game
    _quit = true;
}

void ViewsController::forceQuit()
{
    _quit = true;

}


void ViewsController::playMusic(bool loop)
{
/*
    _music.SetLoop(loop);
    _music.SetVolume(10);
    _music.Play();
*/
}
