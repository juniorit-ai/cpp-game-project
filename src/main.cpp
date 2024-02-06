#include "juniorit/GameCraft/Game.h"
#include "FirstScene.h"
#include <iostream>

int main(int argc, char *argv[])
{
    std::string name = "JuniorIT GameCraft App";

    int width = 1280;
    int height = 512;

    std::cout << name << " starts; Scene width: " << width << ", height: " << height << ".\n";

    Game *game = Game::getInstance();

    game->init(name, width, height);

    Scene *scene = new FirstScene();

    game->addScene(scene);

    game->setCurrentScene(scene);

    game->run();

    delete game;

    return 0;
}