#include <iostream>
#include <raylib.h>

#include "tictactoe/print_board.h"
#include "tictactoe/game.h"

int main()
{
    int screenWidth = 800;
    int screenHeight = 650;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Tic Tac Toe");

    int playerNum = 1;
    Vector2 mousePosition = {-100.0f, -100.0f};
    int **board;
    board = new int *[3];
    for (size_t i = 0; i < 3; i++)
    {
        board[i] = new int[3];
        for (size_t j = 0; j < 3; j++)
        {
            board[i][j] = 0;
        }
    }

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsWindowResized())
        {
            screenWidth = GetScreenWidth();
            screenHeight = GetScreenHeight();
        }
        mousePosition = GetMousePosition();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            printf("Mouse Position is: %f, %f\n", mousePosition.x, mousePosition.y);
            bool playable = PlayPiece(board, mousePosition, playerNum, (float)screenWidth, (float)screenHeight);
            printf("Is playable: %d \n", playable);
            if (playerNum == 1 && playable)
                playerNum = 2;
            else if (playerNum == 2 && playable)
                playerNum = 1;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        PrintBoardLines((float)screenWidth / 2, (float)screenHeight / 2, (float)screenWidth / 4, (float)screenHeight / 4);

        PrintGamePieces(board, (float)screenWidth / 3, (float)screenHeight / 3);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
