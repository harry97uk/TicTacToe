#ifndef GAME_H
#define GAME_H

#include <raylib.h>

#include "tictactoe/game_display.h"

class Game
{
private:
    int playerNum;
    int winningPlayer = -1;
    bool gameFinished;
    bool shouldExitGame = false;
    int **board;
    GameDisplay gameDisplay;

    void ResetBoard();

public:
    Game(int initPlayerNum);
    ~Game();

    void RunGame();

    void ResetGame(int initPlayerNum);
    void PlayPiece(Vector2 boardPosition);
    void DetermineWinner();
    void ResetShouldGameExit() { shouldExitGame = false;}

    int **GetBoard() { return board; }
    bool IsGameFinished() { return gameFinished; }
    bool ShouldGameExit() { return shouldExitGame; }
    int GetWinningPlayer() { return winningPlayer; }
};

#endif // !GAME_H