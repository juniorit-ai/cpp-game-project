// Types.h
#ifndef JUNIORIT_GAMECRAFT_TYPES_H
#define JUNIORIT_GAMECRAFT_TYPES_H

enum Event { KEYDOWN, KEYUP, MOUSEWHEEL, MOUSEBUTTONDOWN, MOUSEBUTTONUP, MOUSEMOTION, UNKNOWN };

enum FlipMode {
    FLIP_NONE = 0,
    FLIP_HORIZONTAL = 1,
    FLIP_VERTICAL = 2,
    FLIP_DIAGONAL = 3 // both horizontal and vertical
};

struct Point {
    int x; // The x coordinate of the point
    int y; // The y coordinate of the point
};

struct Rect {
    int x; // the x location of the rectangle's upper left corner
    int y; // the y location of the rectangle's upper top corner
    int w; // the width of the rectangle
    int h; // the height of the rectangle
};

#endif // JUNIORIT_GAMECRAFT_TYPES_H
