#include <iostream>
#include <raylib.h>
#include <algorithm>

#include "tictactoe/game_display.h"

GameDisplay::GameDisplay(float initWidth, float initHeight) : Display(initWidth, initHeight)
{
    ResizeGameDisplay();
}

void GameDisplay::ResizeGameDisplay()
{
    SetDisplayWidth(GetScreenWidth());
    SetDisplayHeight(GetScreenHeight());

    boardBounds.x = GetDisplayWidth() / 4;
    boardBounds.y = GetDisplayHeight() / 4;
    boardBounds.width = GetDisplayWidth() / 2;
    boardBounds.height = GetDisplayHeight() / 2;

    for (int i = 0; i < 9; i++)
    {
        boardSquaresBounds[i].x = boardBounds.x + (((i % 3) / 3.0f) * boardBounds.width);
        boardSquaresBounds[i].y = boardBounds.y + (((i < 6 ? (i < 3 ? 0 : 1) : 2) / 3.0f) * boardBounds.height);
        boardSquaresBounds[i].width = boardBounds.width / 3;
        boardSquaresBounds[i].height = boardBounds.height / 3;
    }

    playAgainDisplay.x = GetDisplayWidth() / 8;
    playAgainDisplay.y = GetDisplayHeight() / 8;
    playAgainDisplay.width = GetDisplayWidth() / 4;
    playAgainDisplay.height = 30.0f;

    winnerDisplay.x = (GetDisplayWidth() * 5) / 8;
    winnerDisplay.y = GetDisplayHeight() / 8;
    winnerDisplay.width = GetDisplayWidth() / 4;
    winnerDisplay.height = 30.0f;

    exitToMenu.SetButtonText("Exit");
    exitToMenu.SetButtonBounds((GetDisplayWidth() / 4), (GetDisplayHeight() * 7) / 8, GetDisplayWidth() / 4, 30.0f);
}

void GameDisplay::DrawGame(int **board, int winningPlayer, bool gameFinished)
{
    ClearBackground(RAYWHITE);

    DrawBoardLines();

    DrawGamePieces(board);

    if (gameFinished)
    {
        DrawWinningMessage(winningPlayer);

        DrawPlayAgainMessage();
    }
}

void GameDisplay::DrawGamePieces(int **board)
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (board[i][j] == 1)
            {

                int top_point = boardSquaresBounds[(i * 3) + j].y + (boardSquaresBounds[(i * 3) + j].height * 0.1);
                int bottom_point = boardSquaresBounds[(i * 3) + j].y + (boardSquaresBounds[(i * 3) + j].height * 0.9);
                int left_point = boardSquaresBounds[(i * 3) + j].x + (boardSquaresBounds[(i * 3) + j].width * 0.1);
                int right_point = boardSquaresBounds[(i * 3) + j].x + (boardSquaresBounds[(i * 3) + j].width * 0.9);

                DrawLine(left_point, top_point, right_point, bottom_point, BLACK);
                DrawLine(right_point, top_point, left_point, bottom_point, BLACK);
            }
            else if (board[i][j] == 2)
            {
                float radius = std::min(boardSquaresBounds[(i * 3) + j].width / 2, boardSquaresBounds[(i * 3) + j].height / 2) * 0.8;
                int centerX = boardSquaresBounds[(i * 3) + j].x + (boardSquaresBounds[(i * 3) + j].width / 2);
                int centerY = boardSquaresBounds[(i * 3) + j].y + (boardSquaresBounds[(i * 3) + j].height / 2);
                DrawCircleLines(centerX, centerY, radius, BLACK);
            }
        }
    }
}

void GameDisplay::DrawBoardLines()
{
    float width = boardBounds.width;
    float height = boardBounds.height;
    float widthOffset = boardBounds.x;
    float heightOffset = boardBounds.y;

    Vector2 leftVerticalLine1 = {(width / 3) + widthOffset, heightOffset};
    Vector2 leftVerticalLine2 = {(width / 3) + widthOffset, height + heightOffset};

    Vector2 rightVerticalLine1 = {((width / 3) * 2) + widthOffset, heightOffset};
    Vector2 rightVerticalLine2 = {((width / 3) * 2) + widthOffset, height + heightOffset};

    Vector2 upperHorizontalLine1 = {widthOffset, (height / 3) + heightOffset};
    Vector2 upperHorizontalLine2 = {width + widthOffset, (height / 3) + heightOffset};

    Vector2 lowerHorizontalLine1 = {widthOffset, ((height / 3) * 2) + heightOffset};
    Vector2 lowerHorizontalLine2 = {width + widthOffset, ((height / 3) * 2) + heightOffset};

    DrawLineBezier(leftVerticalLine1, leftVerticalLine2, (float)5, BLACK);
    DrawLineBezier(rightVerticalLine1, rightVerticalLine2, (float)5, BLACK);
    DrawLineBezier(upperHorizontalLine1, upperHorizontalLine2, (float)5, BLACK);
    DrawLineBezier(lowerHorizontalLine1, lowerHorizontalLine2, (float)5, BLACK);
}

void GameDisplay::DrawWinningMessage(int winningPlayer)
{
    DrawRectangleRec(winnerDisplay, BLACK);
    DrawRectangleLines((int)winnerDisplay.x, (int)winnerDisplay.y, (int)winnerDisplay.width, (int)winnerDisplay.height, BLACK);

    const char *winningText;
    if (winningPlayer == 0)
        winningText = "Draw!";
    else
        winningText = TextFormat("Player %i Wins!", winningPlayer);

    DrawText(winningText, (int)(winnerDisplay.x + winnerDisplay.width / 2 - MeasureText(winningText, 10) / 2), (int)winnerDisplay.y + 11, 10, MAROON);
}

void GameDisplay::DrawPlayAgainMessage()
{
    bool mouseHoverPlayAgain = CheckCollisionPointRec(GetMousePosition(), playAgainDisplay);

    DrawRectangleRec(playAgainDisplay, (mouseHoverPlayAgain) ? SKYBLUE : LIGHTGRAY);
    DrawRectangleLines((int)playAgainDisplay.x, (int)playAgainDisplay.y, (int)playAgainDisplay.width, (int)playAgainDisplay.height, (mouseHoverPlayAgain) ? BLUE : GRAY);
    DrawText("Play Again?", (int)(playAgainDisplay.x + playAgainDisplay.width / 2 - MeasureText("Play Again?", 10) / 2), (int)playAgainDisplay.y + 11, 10, (mouseHoverPlayAgain) ? DARKBLUE : DARKGRAY);
}

bool GameDisplay::PlayAgainClicked()
{
    Vector2 mousePosition = GetMousePosition();
    return (CheckCollisionPointRec(mousePosition, playAgainDisplay) && IsMouseButtonReleased(MOUSE_BUTTON_LEFT));
}

bool GameDisplay::ExitGameClicked()
{
    Vector2 mousePosition = GetMousePosition();
    return (CheckCollisionPointRec(mousePosition, exitToMenu.GetButtonBounds()) && IsMouseButtonReleased(MOUSE_BUTTON_LEFT));
}

Vector2 GameDisplay::BoardSquareClicked()
{
    Vector2 mousePosition = GetMousePosition();
    Vector2 boardCoords = {-1, -1};

    for (size_t i = 0; i < 9; i++)
    {
        if (CheckCollisionPointRec(mousePosition, boardSquaresBounds[i]))
        {
            boardCoords.x = i % 3;
            boardCoords.y = (i < 6 ? (i < 3 ? 0 : 1) : 2);
            return boardCoords;
        }
    }

    return boardCoords;
}
