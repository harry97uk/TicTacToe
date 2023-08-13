#ifndef DISPLAY_H
#define DISPLAY_H

class Display
{
private:
    float width;
    float height;

public:
    Display(float initWidth, float initHeight);

    void SetDisplayWidth(float newWidth) {width = newWidth;}
    void SetDisplayHeight(float newHeight) {height = newHeight;}

    float GetDisplayWidth() {return width;}
    float GetDisplayHeight() {return height;}
};

#endif // !DISPLAY_H