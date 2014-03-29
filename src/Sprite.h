#ifndef SPRITE_H
#define SPRITE_H

#include "IncludeSDL.h"

typedef struct sprite {
    float x, y, velocityX, velocityY, width, height;
    bool isVisible;
    SDL_Rect rect;
    SDL_Color color;
} sprite;

#endif