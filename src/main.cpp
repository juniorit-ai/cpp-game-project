#include "juniorit/GameCraft/Game.h"
#include "FirstScene.h"
#include <iostream>

/*
Any C++ executable program must have one main function, and it can only have one main function.
The main function serves as the entry point for your C++ program, called by the Linux system to initiate code execution.
*/

int main(int argc, char *argv[])
{
    std::string name = "JuniorIT GameCraft App";

    int width = 1280;
    int height = 512;

    std::cout << name << " starts; Scene width: " << width << ", height: " << height << std::endl;

    // Create the game engine instance
    Game *game = Game::getInstance();

    game->init(name, width, height);

    Scene *scene = new FirstScene();

    game->addScene(scene);

    game->setCurrentScene(scene);

    // Start to run the main game loop
    game->run();

    delete game;

    return 0;
}