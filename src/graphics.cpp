#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "graphics.h"
#include "global.h"


Graphics::Graphics()
{
    SDL_CreateWindowAndRenderer(global::SCREEN_WIDTH, global::SCREEN_HEIGHT, 0, &_window, &_renderer);
    SDL_SetWindowTitle(_window, "Cavestory");
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(_window);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath) {
    if(this -> spriteSheets.count(filePath) == 0) {
        spriteSheets[filePath] = IMG_Load(filePath.c_str());
    }

    return spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* source, SDL_Rect* sourceRect, SDL_Rect* targetRect) {
    SDL_RenderCopy(this -> _renderer, source, sourceRect, targetRect);
}

void Graphics::flip() {
    SDL_RenderPresent(this -> _renderer);
}

void Graphics::clear() {
    SDL_RenderClear(this -> _renderer);
}

SDL_Renderer* Graphics::getRenderer() {
    return this -> _renderer;
}


