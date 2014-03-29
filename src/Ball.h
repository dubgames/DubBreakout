#ifndef BALL_H
#define BALL_H

#include "Constants.h"
#include "Sprite.h"
#include <vector>

bool Ball_hasHitWall(sprite *ball);

bool Ball_hasFallenOffBottom(sprite *ball);

bool Ball_hasHitPaddle(sprite *ball, sprite *paddle);

bool Ball_hasHitBlock(sprite *ball, std::vector<sprite *> *blocks, int level);

void Ball_update(sprite *ball, float timeDifferenceSeconds);

#endif