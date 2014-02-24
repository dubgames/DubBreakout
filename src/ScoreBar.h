#ifndef SCORE_BAR_H
#define SCORE_BAR_H

#include "IncludeSDL.h"

void ScoreBar_create();
void ScoreBar_destroy();
void ScoreBar_render(SDL_Renderer *renderer, bool update, int score, int lives, int level);

#endif
