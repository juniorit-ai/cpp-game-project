#ifndef JUNIORIT_GAMECRAFT_SPRITE_H
#define JUNIORIT_GAMECRAFT_SPRITE_H

#include <string>
#include "juniorit/GameCraft/Types.h"
#include <vector>
#include <string>

class Sprite {
public:
    bool reDraw;

    Sprite(const std::string& image);
    Sprite(const std::string& image, const std::vector<Rect>& frames);
    void setPosition(float top, float left);
    void setScale(float scale);
    void setAngle(float angle);
    void setCenter(const Point& center);
    void setFlip(FlipMode Mode);
    void setFrame(int frame);
    void onUpdate(int ticks);
    void onDraw();
    void onKeyboard(Event event, int keyCode);
    void onMouse(Event event, Point& point);
    ~Sprite();

private:
    float top;
    float left;
    int width;
    int height;
    float scale;
    float angle;
    Point center;
    FlipMode flip;
    void* texture;
    std::vector<Rect> frames;
    int frameIndex;
};

#endif // JUNIORIT_GAMECRAFT_SPRITE_H
