#include "sprite.h"
#include "graphics.h"
#include "global.h"

Sprite::Sprite(){}

Sprite::Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY,
    int width, int height, float posX, float posY) : 
        x(posX),
        y(posY) {
    this -> sourceRect.x = sourceX;
    this -> sourceRect.y = sourceY;
    this -> sourceRect.w = width;
    this -> sourceRect.h = height;

    this -> spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));

    if(this -> spriteSheet == NULL) {
        printf("\nError Unable to Load Image");
    }
}

Sprite::~Sprite(){};

void Sprite::draw(Graphics &graphics, int x, int y) {
    SDL_Rect destinationRect = {x, y, this -> sourceRect.w * global :: SPRITE_SCALE, 
    this -> sourceRect.h * global :: SPRITE_SCALE};
    graphics.blitSurface(this -> spriteSheet, &this -> sourceRect, &destinationRect);

}

void Sprite::update() {}