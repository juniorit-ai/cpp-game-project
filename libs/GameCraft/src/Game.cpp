#include "juniorit/GameCraft/Game.h"
#include <cassert>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

// Singleton instance
Game* Game::instance = nullptr;

// Constructor
Game::Game() : window(nullptr), renderer(nullptr), width(640), height(480), currentScene(nullptr) {}

// Singleton instance accessor
Game* Game::getInstance() {
    if (instance == nullptr) {
        instance = new Game();
    }
    return instance;
}

// Initialize the game
void Game::init(int width, int height) {
    this->width = width;
    this->height = height;

    assert(SDL_Init(SDL_INIT_VIDEO) == 0);
    window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    assert(window != nullptr);

    renderer = SDL_CreateRenderer(static_cast<SDL_Window*>(window), -1, SDL_RENDERER_ACCELERATED);
    assert(renderer != nullptr);
}

// Add a scene
void Game::addScene(Scene* scene) {
    scenes.push_back(scene);
    if (currentScene == nullptr) {
        setCurrentScene(scene);
    }
}

// Remove a scene
void Game::removeScene(Scene* scene) {
    scenes.erase(std::remove(scenes.begin(), scenes.end(), scene), scenes.end());
    if (currentScene == scene) {
        currentScene = nullptr;
    }
}

// Set the current scene
void Game::setCurrentScene(Scene* scene) {
    auto it = std::find(scenes.begin(), scenes.end(), scene);
    assert(it != scenes.end());
    currentScene = *it;
}

// Main game loop
void Game::run() {
#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop_arg([](void* arg) {
        static_cast<Game*>(arg)->onUpdate();
    }, this, 0, 1);
#else
    bool running = true;
    while (running) {
        onUpdate();
    }
#endif
}

// Process SDL events and update the current scene
void Game::onUpdate() {
    int frameStart = SDL_GetTicks();
    int ticks = 1000 / GAME_FPS;
    processEvents();

    if (currentScene != nullptr) {
        currentScene->onUpdate(ticks);
        currentScene->onDraw();
    }

    int frameTime = SDL_GetTicks() - frameStart;
    if (ticks > frameTime) {
        SDL_Delay(ticks - frameTime);
    }
}

// Map SDL events to game events
static Event eventMap(Uint32 eventType) {
    switch (eventType) {
        case SDL_KEYDOWN:
            return KEYDOWN;
        case SDL_KEYUP:
            return KEYUP;
        case SDL_MOUSEBUTTONDOWN:
            return MOUSEBUTTONDOWN;
        case SDL_MOUSEBUTTONUP:
            return MOUSEBUTTONUP;
        case SDL_MOUSEMOTION:
            return MOUSEMOTION;
        default:
            return UNKNOWN;
    }
}

// Process SDL events
void Game::processEvents() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_KEYDOWN:
            case SDL_KEYUP: {
                int sdlKeyCode = e.key.keysym.sym;
                if (sdlKeyCode == SDLK_ESCAPE) {
                    triggerQuitEvent();
                    return;
                }
                onKeyboard(eventMap(e.type), sdlKeyCode);
                break;
            }
            case SDL_MOUSEWHEEL: {
                Point point = {e.wheel.x, e.wheel.y};
                onMouse(eventMap(e.type), point);
                break;
            }
            case SDL_MOUSEMOTION:
            case SDL_MOUSEBUTTONUP:
            case SDL_MOUSEBUTTONDOWN: {
                Point point = {e.motion.x, e.motion.y};
                onMouse(eventMap(e.type), point);
                break;
            }
            case SDL_QUIT:
#ifdef __EMSCRIPTEN__
                emscripten_cancel_main_loop();
#else
                running = false;
#endif
                break;
            default:
                break;
        }
    }
}

// Trigger SDL_QUIT event
void Game::triggerQuitEvent() {
    SDL_Event event;
    event.type = SDL_QUIT;
    SDL_PushEvent(&event);
}

// Keyboard event handling
void Game::onKeyboard(Event event, int keyCode) {
    if (currentScene) {
        currentScene->onKeyboard(event, keyCode);
    }
}

// Mouse event handling
void Game::onMouse(Event event, Point point) {
    if (currentScene) {
        currentScene->onMouse(event, point);
    }
}

// Destructor
Game::~Game() {
    // Clean up scenes
    for (auto& scene : scenes) {
        delete scene;
    }
    scenes.clear();

    // Destroy SDL renderer and window
    if (renderer) {
        SDL_DestroyRenderer(static_cast<SDL_Renderer*>(renderer));
        renderer = nullptr;
    }

    if (window) {
        SDL_DestroyWindow(static_cast<SDL_Window*>(window));
        window = nullptr;
    }

    // Quit SDL subsystems
    SDL_Quit();

    // Log message
    std::cout << "Game destroyed" << std::endl;

    // Set the instance pointer to nullptr (important for singleton)
    instance = nullptr;
}


