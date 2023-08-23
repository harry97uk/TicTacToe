#ifndef MENU_H
#define MENU_H

#include "tictactoe/menu_display.h"
#include "tictactoe/game.h"

class Menu
{
private:
    MenuDisplay menuDisplay;
    int menuButtonClicked = -1;
public:
    Menu();

    void RunMenu();
    int ButtonClicked() {return menuButtonClicked;}
};


#endif // !MENU_H