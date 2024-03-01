#include "FirstScene.h"
#include <cmath>
#include <iostream>
#include <cassert>

/*
The first scene of the game. We will update this file to implement our game logic.
*/

int timeLapse = 0;

Sprite *sprite = nullptr;

// Initialize FirstScene object
FirstScene::FirstScene()
{
    // The images are located in the 'res' folder.
    
    sprite = new Sprite("t-rex.png");
    assert(sprite != nullptr);
    this->addChild(sprite);

    sprite->setPosition(100, 200);
}

FirstScene::~FirstScene()
{
    delete sprite;
}

// This method is called by the main game loop every frame, approximately 60 times per second in our game project.
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