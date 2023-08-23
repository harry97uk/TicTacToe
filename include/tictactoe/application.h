#ifndef APPLICATION_H
#define APPLICATION_H

#include "tictactoe/menu.h"
#include "tictactoe/game.h"

class Application
{
private:
    Menu menu;
    Game game;
    int pageNumber = -1;
public:
    Application();

    void RunApplication();
};

#endif // !APPLICATION_H