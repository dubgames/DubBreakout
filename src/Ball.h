#ifndef BALL_H
#define BALL_H

#include "Constants.h"
#include "Sprite.h"
#include <vector>

bool hasCollidedWithTopLeftRight(struct sprite *ball);
bool hasFallenOffBottom(struct sprite *ball);
bool hasCollidedWithPaddle(struct sprite *ball, struct sprite *paddle);
bool hasCollidedWithBlock(struct sprite *ball, std::vector<struct sprite*> *blocks, int level);

void updateBall(struct sprite *ball, float time_passed);

#endif