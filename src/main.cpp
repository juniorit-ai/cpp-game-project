#include "juniorit/GameCraft/Game.h"
#include "FirstScene.h"
#include <iostream>

int main(int argc, char *argv[]) {
    int width = 1280;
    int height = 512;

    std::cout << "Game starts; Scene width: " << width << ", height: " << height << ".\n";

    // Access the singleton instance of the Game
    Game* game = Game::getInstance();

    // Initialize the game instance
    game->init(width, height);

    // Create the first scene of the game, which contains the major game logic
    Scene* scene = new FirstScene();  // Assuming FirstScene is derived from Scene

    // Add the scene to the game
    game->addScene(scene);

    // Set the scene as the current scene in the game
    game->setCurrentScene(scene);

    // Start the game loop
    game->run();

    delete game;
    
    return 0;
}
