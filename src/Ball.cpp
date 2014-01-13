#include "Ball.h"

bool block_collisions_allowed = true;

bool isPointContained(float x, float y, struct sprite *sprite) {
    x -= sprite->x;
    y -= sprite->y;
    return x >= 0 && x <=sprite->width && y >= 0 && y <= sprite->height;
}

bool hasCollidedWithTopLeftRight(struct sprite *ball) {
    if (ball->velocityY < 0 && ball->y < SCORES_HEIGHT + BUFFER_HEIGHT) {
        ball->velocityY = -ball->velocityY;
        block_collisions_allowed = true;
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

bool hasFallenOffBottom(struct sprite *ball) {
    if (ball->velocityY > 0 && ball->y + ball->height >= SCREEN_HEIGHT) {
        ball->x = BALL_INITIAL_X;
        ball->y = BALL_INITIAL_Y;
        ball->velocityY = 0;
        ball->velocityX = 0;
        return true;
    }
    return false;
}

bool hasCollidedWithPaddle(struct sprite *ball, struct sprite *paddle) {
    // Collision with paddle
    if (ball->velocityY > 0) {
        if (isPointContained(ball->x, ball->y, paddle)
            || isPointContained(ball->x + ball->width, ball->y, paddle)
            || isPointContained(ball->x + ball->width, ball->y + ball->height, paddle)
            || isPointContained(ball->x, ball->y + ball->height, paddle)) {
            ball->velocityY = -ball->velocityY;
            float x = ball->x - (paddle->x + PADDLE_WIDTH/2);
            if (x <= 0 && x > -VELOCITYX_PADDLE_RANGE) x = -VELOCITYX_PADDLE_RANGE;
            if (x > 0 && x < VELOCITYX_PADDLE_RANGE) x = VELOCITYX_PADDLE_RANGE;
            ball->velocityX = VELOCITYX_MULTIPLIER * x;
            block_collisions_allowed = true;
            return true;
        }
    }
    return false;
}

bool hasCollidedWithBlock(struct sprite *ball, std::vector<struct sprite*> *blocks, int level) {
    // Collision with block
    if (block_collisions_allowed) {
        for (struct sprite *block : *blocks) {
            if (block->isVisible) {
                if (isPointContained(ball->x, ball->y, block)
                    || isPointContained(ball->x + ball->width, ball->y, block)
                    || isPointContained(ball->x + ball->width, ball->y + ball->height, block)
                    || isPointContained(ball->x, ball->y + ball->height, block)) {
                    
                    block->isVisible = false;
                    ball->velocityY = getBallVelocity(ball, block, level);
                    block_collisions_allowed = false;
                    return true;
                }
                
            }
        }
    }
    return false;
}

void updateBall(struct sprite *ball, float time_passed) {
    ball->x += ball->velocityX * time_passed;
    ball->y += ball->velocityY * time_passed;
}

