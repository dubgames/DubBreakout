#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <vector>
#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "SDL2_mixer/SDL_mixer.h"
#include "Sprite.h"
#include "Constants.h"
#include "Input.h"
#include "Game.h"
#include <string.h>

const int FRAMES_PER_SECOND = 60;
const int TIME_PER_FRAME = 1000 / FRAMES_PER_SECOND;

void playPaddleHitSound();
void playSideHitSound();
void playBlockHitSound();

#endif
