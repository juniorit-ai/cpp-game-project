#include "juniorit/GameCraft/Scene.h"
#include "juniorit/GameCraft/Game.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Scene::Scene() : reDraw(false) {}

Scene::~Scene() {
    for (auto sprite : children) {
        delete sprite;
    }
}

void Scene::addChild(Sprite* sprite) {
    children.push_back(sprite);
}

void Scene::removeChild(Sprite* sprite) {
    children.erase(std::remove(children.begin(), children.end(), sprite), children.end());
}

void Scene::onUpdate(int ticks) {
    for (auto sprite : children) {
        sprite->onUpdate(ticks);
        if (sprite->reDraw) {
            reDraw = true;
        }
    }
}

void Scene::onDraw() {
    if (!reDraw) {
        return;
    }

    Game* game = Game::getInstance();
    SDL_Renderer* renderer = static_cast<SDL_Renderer*>(game->renderer);
    SDL_RenderClear(renderer);

    for (auto sprite : children) {
        sprite->onDraw();
    }

    SDL_RenderPresent(renderer);
    reDraw = false;
}

void Scene::onKeyboard(Event event, int keyCode) {
    for (auto sprite : children) {
        sprite->onKeyboard(event, keyCode);
    }
}

void Scene::onMouse(Event event, Point point) {
    for (auto sprite : children) {
        sprite->onMouse(event, point);
    }
}
