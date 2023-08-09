#include <iostream>
#include <raylib.h>
#include <algorithm>

#include "tictactoe/print_board.h"

void PrintGamePieces(int **board, float width, float height)
{
    Vector2 piece_pos = {width, height};

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (board[i][j] == 1)
            {
                int top_point = piece_pos.y + (height / 5);
                int bottom_point = piece_pos.y - (height / 5);
                int left_point = piece_pos.x - (width / 5);
                int right_point = piece_pos.x + (width / 5);

                DrawLine(left_point, top_point, right_point, bottom_point, BLACK);
                DrawLine(right_point, top_point, left_point, bottom_point, BLACK);
            }
            else if (board[i][j] == 2)
            {
                float radius = std::min(width, height);
                DrawCircleLines((int)piece_pos.x, (int)piece_pos.y, radius/5, BLACK);
            }
            piece_pos.x += width/2;
        }
        piece_pos.y += height/2;
        piece_pos.x = width;
    }
}

void PrintBoardLines(float width, float height, float widthOffset, float heightOffset)
{
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