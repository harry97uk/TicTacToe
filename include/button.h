#ifndef BUTTON_H
#define BUTTON_H

#include <raylib.h>

class Button
{
private:
    const char *buttonText;
    Rectangle buttonBounds;
public:
    Button();

    void SetButtonText(const char *newButtonText) {buttonText = newButtonText;}
    void SetButtonBounds(float x, float y, float width, float height) {buttonBounds = {x, y, width, height};}

    const char * GetButtonText() {return buttonText;}
    Rectangle GetButtonBounds() {return buttonBounds;}

};

#endif // BUTTON_H