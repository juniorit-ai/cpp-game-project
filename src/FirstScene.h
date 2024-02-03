#ifndef JUNIORIT_GAMECRAFT_FIRSTSCENE_H
#define JUNIORIT_GAMECRAFT_FIRSTSCENE_H

#include "juniorit/GameCraft/Scene.h"
#include "juniorit/GameCraft/Sprite.h"

class FirstScene : public Scene
{
public:
    FirstScene();

    ~FirstScene() override;

    void onUpdate(int ticks) override;

    void onKeyboard(Event event, int keyCode) override;

    void onMouse(Event event, Point point) override;

private:
    Sprite *sprite;
    Sprite *background;
    int timeLapse;
};

#endif // JUNIORIT_GAMECRAFT_FIRSTSCENE_H