#ifndef MENU_DISPLAY_H
#define MENU_DISPLAY_H

#include <vector>
#include <raylib.h>
#include "display.h"
#include "button.h"

class MenuDisplay : public Display
{
private:
    std::vector<Button> menuButtons;
public:
    MenuDisplay(float initWidth, float initHeight);

    void ResizeMenuDisplay();
    void DrawTitle();
    void DrawMenuButtons();
    int MenuButtonClicked();
};


#endif // !MENU_DISPLAY_H