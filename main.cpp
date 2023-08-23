#include <iostream>
#include <raylib.h>

#include "tictactoe/application.h"

int main()
{
    int screenWidth = 800;
    int screenHeight = 650;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Tic Tac Toe");
    SetWindowMinSize(400, 400);

    Application app;
    
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        app.RunApplication();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
