#ifndef SPRITE_H
#define SPRITE_H

#include "SDL2/SDL.h"

struct sprite {
    float x, y, velocityX, velocityY, width, height;
    SDL_Rect rect;
    struct texture *texture;
    bool isVisible;
    SDL_Color color;
};

SDL_Rect* getRect(struct sprite *s);
void renderSprite(SDL_Renderer *renderer, struct sprite sprite);

#endif