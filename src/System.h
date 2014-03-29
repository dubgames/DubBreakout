#ifndef SYSTEM_H
#define SYSTEM_H

#include "IncludeSDL.h"
#include <vector>
#include "Sprite.h"

bool System_init(int width, int height);

void System_quit();

Uint32 System_startFrame();

void System_endFrame();

void System_render(sprite *topbar, sprite *ball, std::vector<sprite *> *blocks, sprite *paddles[]);

void log_error(const char *in);


#endif
