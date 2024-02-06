#ifndef JUNIORIT_GAMECRAFT_GAME_H
#define JUNIORIT_GAMECRAFT_GAME_H

#include "juniorit/GameCraft/Scene.h"
#include "juniorit/GameCraft/Types.h"
#include <vector>

const int GAME_FPS = 60;

class Game {
public:
    void* renderer;
    void* window;
    
    void init(std::string name, int width, int height);
    void addScene(Scene* scene);
    void removeScene(Scene* scene);
    void setCurrentScene(Scene* scene);
    void onUpdate(); 
    void onKeyboard(Event event, int keyCode);
    void onMouse(Event event, Point point);
    void triggerQuitEvent();
    void processEvents();
    void run(); // Main game loop
    ~Game();

    static Game* getInstance();

private:
    
    int width;
    int height;
    std::vector<Scene*> scenes;
    Scene* currentScene;

    static Game* instance;

    Game();
};

#endif // JUNIORIT_GAMECRAFT_GAME_H
