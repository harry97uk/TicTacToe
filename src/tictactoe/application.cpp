#include "tictactoe/application.h"

Application::Application() : menu(), game(rand() % (1) + 1)
{
}

void Application::RunApplication()
{
    switch (pageNumber)
    {
    case -1:
        menu.RunMenu();
        if (menu.ButtonClicked() != -1)
            pageNumber = menu.ButtonClicked();
        break;
    case 0:
        game.RunGame();
        if (game.ShouldGameExit())
            pageNumber = 0;
        game.ResetShouldGameExit();
        break;

    default:
        break;
    }
}