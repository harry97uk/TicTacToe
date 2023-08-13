#include <iostream>
#include <raylib.h>

#include "tictactoe/game_display.h"
#include "tictactoe/game.h"

int main()
{
    int screenWidth = 800;
    int screenHeight = 650;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Tic Tac Toe");
    SetWindowMinSize(400, 400);

    GameDisplay gameDisplay(screenWidth, screenHeight);

    Vector2 mousePosition = {-100.0f, -100.0f};

    Game game(rand() % (1) + 1);

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsWindowResized())
        {
            gameDisplay.SetDisplayWidth(GetScreenWidth());
            gameDisplay.SetDisplayHeight(GetScreenHeight());
            gameDisplay.ResizeGameDisplay();
        }

        mousePosition = GetMousePosition();

        if (!game.IsGameFinished() && IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            game.PlayPiece(mousePosition, (float)screenWidth, (float)screenHeight);

        game.DetermineWinner();

        if (game.IsGameFinished() && gameDisplay.PlayAgainClicked())
            game.ResetGame(rand() % (1) + 1);

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        gameDisplay.PrintBoardLines();

        gameDisplay.PrintGamePieces(game.GetBoard());

        if (game.IsGameFinished())
        {
            gameDisplay.PrintWinningMessage(game.GetWinningPlayer());

            gameDisplay.PrintPlayAgainMessage();
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
