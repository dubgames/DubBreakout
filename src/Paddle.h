#ifndef PADDLE_H
#define PADDLE_H

#include "Sprite.h"
#include "Constants.h"

void updatePaddle(struct sprite *paddle, float time_passed, bool isLeftPressed, bool isRightPressed);
    
#endif
