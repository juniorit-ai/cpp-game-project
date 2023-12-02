#include "juniorit/GameCraft/Sprite.h"
#include "juniorit/GameCraft/Game.h"   
#include "juniorit/GameCraft/utils.h"
#include <SDL2/SDL_image.h>
#include <cassert>

Sprite::Sprite(const std::string& imagePath) {
    // Load image and create texture
    SDL_Renderer* renderer = (SDL_Renderer*)Game::getInstance()->renderer;
    SDL_Surface* surface = IMG_Load(getResourceFilePath(imagePath).c_str());
    width = surface->w;
    height = surface->h;
    assert(surface);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    assert(texture);

    // Initialize other properties
    top = left = 0.0f;
    scale = 1.0f;
    angle = 0.0f;
    center = {0, 0};
    flip = FLIP_NONE;
    frameIndex = 0;
    reDraw = true;
}

Sprite::Sprite(const std::string& imagePath, const std::vector<Rect>& frames) 
    : Sprite(imagePath) {
    this->frames = frames;
}

Sprite::~Sprite() {
    if (texture) {
        SDL_DestroyTexture((SDL_Texture*)texture);
    }
}

void Sprite::setPosition(float top, float left) {
    this->top = top;
    this->left = left;
    reDraw = true;
}

void Sprite::setScale(float scale) {
    this->scale = scale;
    reDraw = true;
}

void Sprite::setAngle(float angle) {
    this->angle = angle;
    reDraw = true;
}

void Sprite::setCenter(const Point& center) {
    this->center = center;
    reDraw = true;
}

void Sprite::setFlip(FlipMode flipMode) {
    this->flip = flipMode;
    reDraw = true;
}

void Sprite::setFrame(int frameIndex) {
    assert(frameIndex >= 0 && frameIndex < static_cast<int>(frames.size()));
    this->frameIndex = frameIndex;
    reDraw = true;
}

void Sprite::onUpdate(int ticks) {
    // Update logic for the sprite (animations, movements, etc.)
}

static SDL_RendererFlip getSDLFlip(FlipMode flip) {
    switch (flip) {
        case FLIP_HORIZONTAL:
            return SDL_FLIP_HORIZONTAL;
        case FLIP_VERTICAL:
            return SDL_FLIP_VERTICAL;
        case FLIP_DIAGONAL:
            return static_cast<SDL_RendererFlip>(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
        default:
            return SDL_FLIP_NONE;
    }
}

void Sprite::onDraw() {
    Game* game = Game::getInstance();
    SDL_Renderer* renderer = static_cast<SDL_Renderer*>(game->renderer);

    SDL_Rect dstRect = { static_cast<int>(left), static_cast<int>(top), 0, 0 };
    SDL_Rect srcRect;
    SDL_Rect* srcPtr = nullptr;

    if (!frames.empty()) {
        srcRect = { frames[frameIndex].x, frames[frameIndex].y, frames[frameIndex].w, frames[frameIndex].h };
        srcPtr = &srcRect;
        dstRect.w = srcRect.w * scale;
        dstRect.h = srcRect.h * scale;
    } else {
        // If frames is empty, use the entire texture
        //SDL_QueryTexture((SDL_Texture*)texture, nullptr, nullptr, &dstRect.w, &dstRect.h);
        dstRect.w = width;
        dstRect.h = height;

        dstRect.w *= scale;
        dstRect.h *= scale;
    }

    SDL_RenderCopyEx(renderer, (SDL_Texture*)texture, srcPtr, &dstRect, angle, reinterpret_cast<SDL_Point*>(&center), getSDLFlip(flip));
    reDraw = false;
}


void Sprite::onKeyboard(Event event, int keyCode) {
    // Keyboard event handling
}

void Sprite::onMouse(Event event, Point& point) {
    // Mouse event handling
}
