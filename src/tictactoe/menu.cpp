#include <raylib.h>
#include "tictactoe/menu.h"

Menu::Menu() : menuDisplay(GetScreenWidth(), GetScreenHeight())
{
}

void Menu::RunMenu()
{
    if (IsWindowResized())
        menuDisplay.ResizeMenuDisplay();

    menuButtonClicked = menuDisplay.MenuButtonClicked();

    BeginDrawing();

    ClearBackground(RAYWHITE);

    menuDisplay.DrawMenuButtons();

    EndDrawing();
}
