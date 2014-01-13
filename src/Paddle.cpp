#include "Paddle.h"

bool paddle_canGoLeft(struct sprite *paddle) {
    return paddle->x >= -paddle->width / 2;
}

bool paddle_canGoRight(struct sprite *paddle) {
    return paddle->x <= SCREEN_WIDTH - paddle->width / 2;
}

void updatePaddle(struct sprite *paddle, float time_passed, bool isLeftPressed, bool isRightPressed) {
   
    // Velocity
    if (isLeftPressed && !isRightPressed && paddle_canGoLeft(paddle)) {
        paddle->velocityX  = -PADDLE_VELOCITY;
    } else if (!isLeftPressed && isRightPressed && paddle_canGoRight(paddle)) {
        paddle->velocityX  = PADDLE_VELOCITY;
    } else {
        paddle->velocityX  = 0;
    }
    
    // Position
    paddle->x += paddle->velocityX * time_passed;
    paddle->y += paddle->velocityY * time_passed;
}

