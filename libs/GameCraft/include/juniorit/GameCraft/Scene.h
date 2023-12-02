#ifndef JUNIORIT_GAMECRAFT_SCENE_H
#define JUNIORIT_GAMECRAFT_SCENE_H

#include <vector>
#include "juniorit/GameCraft/Sprite.h" 
#include "juniorit/GameCraft/Types.h"

class Scene {
public:
    Scene();
    void addChild(Sprite* sprite);
    void removeChild(Sprite* sprite);
    virtual void onUpdate(int ticks);
    virtual void onDraw();
    virtual void onKeyboard(Event event, int keyCode);
    virtual void onMouse(Event event, Point point);
    virtual ~Scene();

private:
    bool reDraw;
    std::vector<Sprite*> children;
};

#endif // JUNIORIT_GAMECRAFT_SCENE_H
