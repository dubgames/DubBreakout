#ifndef INPUT_H
#define INPUT_H

#include "SDL2/SDL.h"

extern bool isLeftPressed, isRightPressed, isUpPressed, isDownPressed, isSpacePressed, isQuitPressed;
extern bool isCheatInfiniteLives, isCheatDestroyAllBlocks;
void handle_input();

#endif
