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
    boardBounds.x = GetDisplayWidth() / 4;
    boardBounds.y = GetDisplayHeight() / 4;
    boardBounds.width = GetDisplayWidth() / 2;
    boardBounds.height = GetDisplayHeight() / 2;

    for (size_t i = 0; i < 9; i++)
    {
        boardSquaresBounds[i].x = boardBounds.x + (((i % 3) / 3) * boardBounds.width);
        boardSquaresBounds[i].y = boardBounds.y + (((i < 6 ? (i < 3 ? 0 : 1) : 2) / 3) * boardBounds.height);
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
}

void GameDisplay::PrintGamePieces(int **board)
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (board[i][j] == 1)
            {

                int top_point = boardSquaresBounds[(i * 3) + j].y;
                int bottom_point = boardSquaresBounds[(i * 3) + j].y + boardSquaresBounds[(i * 3) + j].height;
                int left_point = boardSquaresBounds[(i * 3) + j].x;
                int right_point = boardSquaresBounds[(i * 3) + j].x + boardSquaresBounds[(i * 3) + j].width;

                DrawLine(left_point, top_point, right_point, bottom_point, BLACK);
                DrawLine(right_point, top_point, left_point, bottom_point, BLACK);
            }
            else if (board[i][j] == 2)
            {
                float radius = std::min(boardSquaresBounds[(i * 3) + j].width, boardSquaresBounds[(i * 3) + j].height);
                int centerX = boardSquaresBounds[(i * 3) + j].x + (boardSquaresBounds[(i * 3) + j].width / 2);
                int centerY = boardSquaresBounds[(i * 3) + j].y + (boardSquaresBounds[(i * 3) + j].height / 2);
                DrawCircleLines(centerX, centerY, radius, BLACK);
            }
        }
    }
}

void GameDisplay::PrintBoardLines()
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

void GameDisplay::PrintWinningMessage(int winningPlayer)
{
    DrawRectangleRec(winnerDisplay, BLACK);
    DrawRectangleLines((int)winnerDisplay.x, (int)winnerDisplay.y, (int)winnerDisplay.width, (int)winnerDisplay.height, BLACK);
    DrawText(TextFormat("Player %i Wins!", winningPlayer), (int)(winnerDisplay.x + winnerDisplay.width / 2 - MeasureText(TextFormat("Player %i Wins!", winningPlayer), 10) / 2), (int)winnerDisplay.y + 11, 10, MAROON);
}

void GameDisplay::PrintPlayAgainMessage()
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