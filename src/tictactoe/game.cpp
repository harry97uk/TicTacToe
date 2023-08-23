#include <raylib.h>
#include <iostream>

#include "tictactoe/game.h"
#include "tictactoe/game_display.h"

// Declarations
int getNextPlayerNum(int playerNum);

Game::Game(int initPlayerNum) : gameDisplay(GetScreenWidth(), GetScreenHeight())
{
    // Allocate memory for the dynamic 2D array
    board = new int *[3]; // Create an array of int pointers

    for (size_t i = 0; i < 3; i++)
    {
        board[i] = new int[3]; // Create an int array for each row
        for (size_t j = 0; j < 3; j++)
        {
            board[i][j] = 0; // Initialize with default value
        }
    }

    ResetGame(initPlayerNum);
}

Game::~Game()
{
    // Deallocate memory for the dynamic 2D array
    for (size_t i = 0; i < 3; i++)
    {
        delete[] board[i]; // Delete the int array for each row
    }
    delete[] board; // Delete the array of int pointers
}

void Game::RunGame()
{

    if (IsWindowResized())
        gameDisplay.ResizeGameDisplay();

    if (gameDisplay.ExitGameClicked())
        shouldExitGame = true;

    if (!IsGameFinished() && IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
        Vector2 boardPieceClickedCoords = gameDisplay.BoardSquareClicked();

        if (boardPieceClickedCoords.x != -1 && boardPieceClickedCoords.y != -1)
            PlayPiece(boardPieceClickedCoords);
    }

    DetermineWinner();

    if (IsGameFinished() && gameDisplay.PlayAgainClicked())
        ResetGame(rand() % (1) + 1);

    BeginDrawing();

    gameDisplay.DrawGame(GetBoard(), GetWinningPlayer(), IsGameFinished());

    EndDrawing();
}

void Game::ResetGame(int initPlayerNum)
{
    ResetBoard();
    winningPlayer = -1;
    playerNum = initPlayerNum;
    gameFinished = false;
}

void Game::PlayPiece(Vector2 boardPosition)
{
    int x = boardPosition.x;
    int y = boardPosition.y;

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
    bool isDraw = true;
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
            {
                isDraw = false;
                horizontal += 10;
            }

            if (board[j][i] != 0)
                vertical += board[j][i];
            else
            {
                isDraw = false;
                vertical += 10;
            }

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
    if (isDraw && winningPlayer == -1)
        winningPlayer = 0;

    if (winningPlayer != -1)
        gameFinished = true;
}

void Game::ResetBoard()
{
    for (size_t i = 0; i < 3; i++)
    {
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
    else
        return 1;
}
