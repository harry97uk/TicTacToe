#ifndef GAME_DISPLAY_H
#define GAME_DISPLAY_H

#include <raylib.h>
#include "display.h"

class GameDisplay : public Display
{
private:
    Rectangle boardBounds;
    Rectangle boardSquaresBounds[9];
    Rectangle winnerDisplay;
    Rectangle playAgainDisplay;

public:
    GameDisplay(float initWidth, float initHeight);

    void ResizeGameDisplay();

    void PrintGamePieces(int **board);
    void PrintBoardLines();
    void PrintWinningMessage(int winningPlayer);
    void PrintPlayAgainMessage();

    bool PlayAgainClicked();
};

#endif // !GAME_DISPLAY_H