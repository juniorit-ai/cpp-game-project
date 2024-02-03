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
    void setPosition(double top, double left);
    void setScale(double scale);
    void setAngle(double angle);
    void setCenter(const Point& center);
    void setFlip(FlipMode Mode);
    void setFrame(int frame);
    void onUpdate(int ticks);
    void onDraw();
    void onKeyboard(Event event, int keyCode);
    void onMouse(Event event, Point& point);
    ~Sprite();

private:
    double top;
    double left;
    int width;
    int height;
    double scale;
    double angle;
    Point center;
    FlipMode flip;
    void* texture;
    std::vector<Rect> frames;
    int frameIndex;
};

#endif // JUNIORIT_GAMECRAFT_SPRITE_H
