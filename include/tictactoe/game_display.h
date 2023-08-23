#ifndef GAME_DISPLAY_H
#define GAME_DISPLAY_H

#include <raylib.h>
#include "display.h"
#include "button.h"

class GameDisplay : public Display
{
private:
    Rectangle boardBounds;
    Rectangle boardSquaresBounds[9];
    Rectangle winnerDisplay;
    Rectangle playAgainDisplay;
    Button exitToMenu;

    void DrawGamePieces(int **board);
    void DrawBoardLines();
    void DrawWinningMessage(int winningPlayer);
    void DrawPlayAgainMessage();

public:
    GameDisplay(float initWidth, float initHeight);

    void ResizeGameDisplay();
    void DrawGame(int** board, int winningPlayer, bool gameFinished);

    bool PlayAgainClicked();
    bool ExitGameClicked();
    Vector2 BoardSquareClicked();
};

#endif // !GAME_DISPLAY_H