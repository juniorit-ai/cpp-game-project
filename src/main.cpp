#include "juniorit/GameCraft/Game.h"
#include "FirstScene.h"
#include <iostream>

int main(int argc, char *argv[])
{
    int width = 1280;
    int height = 512;

    std::cout << "Game starts; Scene width: " << width << ", height: " << height << ".\n";

    Game *game = Game::getInstance();

    game->init(width, height);

    Scene *scene = new FirstScene();

    game->addScene(scene);

    game->setCurrentScene(scene);

    game->run();

    delete game;

    return 0;
}