#include <raylib.h>
#include <iostream>

#include "tictactoe/game.h"

int determine_placement_X(float mousePosX, float width);
int determine_placement_Y(float mousePosY, float height);

bool PlayPiece(int **board, Vector2 mousePos, int playerNum, float width, float height)
{
    int x = determine_placement_X(mousePos.x, width);
    int y = determine_placement_Y(mousePos.y, height);

    printf("X is %d \n", x);
    printf("Y is %d \n", y);
    printf("Board at position is %d \n", board[y][x]);

    if (board[y][x] == 0)
    {
        board[y][x] = playerNum;
        return true;
    }
    else
        return false;
}

int determine_placement_X(float mousePosX, float width)
{
    if (mousePosX < (width * 5) / 12)
        return 0;
    else if (mousePosX < (width * 7) / 12)
        return 1;
    return 2;
}

int determine_placement_Y(float mousePosY, float height)
{
    if (mousePosY < (height * 5) / 12)
        return 0;
    else if (mousePosY < (height * 7) / 12)
        return 1;
    return 2;
}