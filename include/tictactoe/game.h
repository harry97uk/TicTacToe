#ifndef GAME_H
#define GAME_H

#include <raylib.h>

class Game
{
private:
    int playerNum = 1;
    int winningPlayer;
    bool gameFinished;
    int **board;

public:
    Game(int playerNum);

    void ResetGame(int playerNum);
    void PlayPiece(Vector2 mousePos, float width, float height);
    void DetermineWinner();

    int **GetBoard() { return board; }
    bool IsGameFinished() { return gameFinished; }
    int GetWinningPlayer() { return winningPlayer; }
};

#endif // !GAME_H