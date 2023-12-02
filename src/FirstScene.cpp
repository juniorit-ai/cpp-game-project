#include "FirstScene.h"
#include <cmath>
#include <iostream>
#include <cassert>

FirstScene::FirstScene() : sprite(nullptr), background(nullptr), timeLapse(0) {

    background = new Sprite("background.png");
    assert(background != NULL);

    sprite = new Sprite("t-rex.png");  
    assert(sprite != NULL);

    this->addChild(background);
    this->addChild(sprite);

    sprite->setPosition(100, 200);
    
}

FirstScene::~FirstScene() {
    delete sprite;  // Ensure proper cleanup of the dynamically allocated sprite
}

void FirstScene::onUpdate(int ticks) {
    Scene::onUpdate(ticks);  // Calling the base class update

    timeLapse += ticks;
    float frequency = M_PI / 1000.0;
    float scale = 1 + 0.01 * sin(timeLapse * frequency);
    sprite->setScale(scale);
}

void FirstScene::onKeyboard(Event event, int keyCode) {
    Scene::onKeyboard(event, keyCode);  // Delegating to base class

    // Handle keyboard events specific to FirstScene
}

void FirstScene::onMouse(Event event, Point point) {
    Scene::onMouse(event, point);  // Delegating to base class


    // Handle mouse events specific to FirstScene
}
