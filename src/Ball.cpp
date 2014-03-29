#include "Ball.h"

bool blockHitsAllowed = true;

bool isContained(float x, float y, sprite *sprite) {
    x -= sprite->x;
    y -= sprite->y;
    return x >= 0 && x <=sprite->width && y >= 0 && y <= sprite->height;
}

bool Ball_hasHitWall(sprite *ball) {
    if (ball->velocityY < 0 && ball->y < SCORES_HEIGHT + BUFFER_HEIGHT) {
        ball->velocityY = -ball->velocityY;
        blockHitsAllowed = true;
        return true;
    }
    
    if (ball->velocityX < 0 && ball->x <= 0) {
        ball->velocityX = -ball->velocityX;
        return true;
    }

    if (ball->velocityX > 0 && ball->x + ball->width >= SCREEN_WIDTH) {
        ball->velocityX = -ball->velocityX;
        return true;
    }
    
    return false;
}

bool Ball_hasFallenOffBottom(sprite *ball) {
    return ball->velocityY > 0 && ball->y + ball->height >= SCREEN_HEIGHT;
}

bool Ball_hasHitPaddle(sprite *ball, sprite *paddle) {    
    if (ball->velocityY > 0) {
        if (isContained(ball->x, ball->y, paddle)
            || isContained(ball->x + ball->width, ball->y, paddle)
            || isContained(ball->x + ball->width, ball->y + ball->height, paddle)
            || isContained(ball->x, ball->y + ball->height, paddle)) {
            ball->velocityY = -ball->velocityY;
            float x = ball->x - (paddle->x + PADDLE_WIDTH/2);
            if (x <= 0 && x > -VELOCITYX_PADDLE_RANGE) x = -VELOCITYX_PADDLE_RANGE;
            if (x > 0 && x < VELOCITYX_PADDLE_RANGE) x = VELOCITYX_PADDLE_RANGE;
            ball->velocityX = VELOCITYX_MULTIPLIER * x;
            blockHitsAllowed = true;
            return true;
        }
    }
    return false;
}

bool Ball_hasHitBlock(sprite *ball, std::vector<sprite*> *blocks, int level) {    
    if (blockHitsAllowed) {
		for (int i = 0; i < blocks->size(); ++i) {
			sprite *block = (*blocks)[i];
            if (block->isVisible) {
                if (isContained(ball->x, ball->y, block)
                    || isContained(ball->x + ball->width, ball->y, block)
                    || isContained(ball->x + ball->width, ball->y + ball->height, block)
                    || isContained(ball->x, ball->y + ball->height, block)) {
                    
                    block->isVisible = false;
                    ball->velocityY = Constants_getBallVelocity(ball, block, level);
                    blockHitsAllowed = false;
                    return true;
                }                
            }
        }
    }
    return false;
}

void Ball_update(sprite *ball, float timeDifferenceSeconds) {
    ball->x += ball->velocityX * timeDifferenceSeconds;
    ball->y += ball->velocityY * timeDifferenceSeconds;
}

