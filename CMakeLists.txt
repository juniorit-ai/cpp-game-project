cmake_minimum_required(VERSION 3.10)

project(MyGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -gsource-map -Wno-unused-command-line-argument -Wno-limited-postlink-optimizations -s -O3 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS=['png'] --preload-file ../res@res")

set(CMAKE_EXECUTABLE_SUFFIX ".js")

include_directories(
    libs/GameCraft/include
    libs/GameCraft/src
    src
)

# Set the list of source files
set(SOURCE_FILES
    libs/GameCraft/src/Game.cpp
    libs/GameCraft/src/Scene.cpp
    libs/GameCraft/src/Sprite.cpp
    libs/GameCraft/src/utils.cpp
    src/FirstScene.cpp
    src/main.cpp
)

# Create the executable
add_executable(index ${SOURCE_FILES})

install(FILES
    .build/index.js
    .build/index.wasm
    .build/index.data
    .build/index.wasm.map
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/web)