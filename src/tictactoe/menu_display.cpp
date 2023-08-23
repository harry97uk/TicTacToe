#include <raylib.h>

#include "tictactoe/menu_display.h"
#include "button.h"

MenuDisplay::MenuDisplay(float initWidth, float initHeight) : Display(initWidth, initHeight)
{
    Button play;
    Button settings;
    Button exitApplication;

    play.SetButtonText("Play");
    settings.SetButtonText("Settings");
    exitApplication.SetButtonText("Exit Application");

    menuButtons.push_back(play);
    menuButtons.push_back(settings);
    menuButtons.push_back(exitApplication);

    ResizeMenuDisplay();
}

void MenuDisplay::ResizeMenuDisplay()
{
    SetDisplayWidth(GetScreenWidth());
    SetDisplayHeight(GetScreenHeight());

    for (size_t i = 0; i < menuButtons.size(); i++)
    {
        menuButtons[i].SetButtonBounds(GetDisplayWidth()/4, (GetDisplayHeight()*(i+1))/(menuButtons.size()+1), GetDisplayWidth()/4, 30.0f);
    }
    
}

void MenuDisplay::DrawTitle()
{
}

void MenuDisplay::DrawMenuButtons()
{
    for (size_t i = 0; i < menuButtons.size(); i++)
    {
        bool mouseHoverButton = CheckCollisionPointRec(GetMousePosition(), menuButtons[i].GetButtonBounds());

        DrawRectangleRec(menuButtons[i].GetButtonBounds(), (mouseHoverButton) ? SKYBLUE : LIGHTGRAY);
        DrawRectangleLines((int)menuButtons[i].GetButtonBounds().x, (int)menuButtons[i].GetButtonBounds().y, (int)menuButtons[i].GetButtonBounds().width, (int)menuButtons[i].GetButtonBounds().height, (mouseHoverButton) ? BLUE : GRAY);
        DrawText(menuButtons[i].GetButtonText(), (int)(menuButtons[i].GetButtonBounds().x + menuButtons[i].GetButtonBounds().width / 2 - MeasureText(menuButtons[i].GetButtonText(), 10) / 2), (int)menuButtons[i].GetButtonBounds().y + 11, 10, (mouseHoverButton) ? DARKBLUE : DARKGRAY);
    }
}

int MenuDisplay::MenuButtonClicked()
{
    Vector2 mousePosition = GetMousePosition();

    for (size_t i = 0; i < menuButtons.size(); i++)
    {
        if (CheckCollisionPointRec(mousePosition, menuButtons[i].GetButtonBounds()) && IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            return i;
    }

    return -1;
}