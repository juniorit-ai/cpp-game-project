#include "FirstScene.h"
#include <cmath>
#include <iostream>
#include <cassert>

FirstScene::FirstScene() : sprite(nullptr), background(nullptr), timeLapse(0)
{
    background = new Sprite("background.png");
    assert(background != nullptr);

    sprite = new Sprite("t-rex.png");
    assert(sprite != nullptr);

    this->addChild(background);
    this->addChild(sprite);

    sprite->setPosition(100, 200);
}

FirstScene::~FirstScene()
{
    delete sprite;
}

void FirstScene::onUpdate(int ticks)
{
    Scene::onUpdate(ticks);

    timeLapse += ticks;
    double frequency = M_PI / 1000.0;
    double scale = 1 + 0.01 * sin(timeLapse * frequency);
    sprite->setScale(scale);
}

void FirstScene::onKeyboard(Event event, int keyCode)
{
    Scene::onKeyboard(event, keyCode);
}

void FirstScene::onMouse(Event event, Point point)
{
    Scene::onMouse(event, point);
}