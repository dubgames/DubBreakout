
#include "Sprite.h"

SDL_Rect* getRect(struct sprite *s) {
    s->rect = { (int) s->x, (int) s->y, (int) s->width, (int) s->height };
    return &s->rect;
}

void renderSprite(SDL_Renderer *renderer, struct sprite sprite) {
    if (sprite.isVisible) {
        SDL_Color c = sprite.color;
        SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, 0xFF);
        SDL_RenderFillRect(renderer, getRect(&sprite));
    }
}

