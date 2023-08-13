#include <raylib.h>
#include <iostream>

#include "tictactoe/game.h"

//
void resetBoard(int** board);
int determine_placement_X(float mousePosX, float width);
int determine_placement_Y(float mousePosY, float height);

Game::Game(int playerNum) {
    resetBoard(board);
    winningPlayer = 0;
    playerNum = playerNum;
    gameFinished = false;
}

void Game::ResetGame(int playerNum)
{
    resetBoard(board);
    winningPlayer = 0;
    playerNum = playerNum;
    gameFinished = false;
}

void Game::PlayPiece(Vector2 mousePos, float width, float height)
{
    int x = determine_placement_X(mousePos.x, width);
    int y = determine_placement_Y(mousePos.y, height);

    if (board[y][x] == 0)
    {
        board[y][x] = playerNum;
        playerNum = getNextPlayerNum(playerNum);
    }
    else
        return;
}

void Game::DetermineWinner()
{
    for (size_t i = 0; i < 3; i++)
    {
        int vertical = 0;
        int horizontal = 0;
        int diagonal = 0;
        for (size_t j = 0; j < 3; j++)
        {
            if (board[i][j] != 0)
                horizontal += board[i][j];
            else
                horizontal += 10;
            if (board[j][i] != 0)
                vertical += board[j][i];
            else
                vertical += 10;
            if (i == 0)
            {
                if (board[j][j] != 0)
                    diagonal += board[j][j];
                else
                    diagonal += 10;
            }
            if (i == 2)
            {
                if (board[i - j][j] != 0)
                    diagonal += board[i - j][j];
                else
                    diagonal += 10;
            }
        }
        if (horizontal == 3 || vertical == 3 || diagonal == 3)
            winningPlayer = 1;
        if (horizontal == 6 || vertical == 6 || diagonal == 6)
            winningPlayer = 2;
    }
    if (winningPlayer != 0)
        gameFinished = true;
}

void resetBoard(int** board)
{
    board = new int *[3];
    for (size_t i = 0; i < 3; i++)
    {
        board[i] = new int[3];
        for (size_t j = 0; j < 3; j++)
        {
            board[i][j] = 0;
        }
    }
}

int getNextPlayerNum(int playerNum)
{
    if (playerNum == 1)
        return 2;
    else if (playerNum == 2)
        return 1;
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