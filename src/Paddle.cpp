#include "Paddle.h"

const int MIN_PADDLE_X = -PADDLE_WIDTH / 2;
const int MAX_PADDLE_X = SCREEN_WIDTH - PADDLE_WIDTH / 2;

void Paddle_update(sprite *paddle, float timeDifferenceSeconds, float pressure) {
    
    // Horizontal velocity
    paddle->velocityX = pressure * PADDLE_VELOCITY;
    
    // Position
    paddle->x += paddle->velocityX * timeDifferenceSeconds;
    paddle->y += paddle->velocityY * timeDifferenceSeconds;
    
    // Constrain X to screen
    if (paddle->x < MIN_PADDLE_X) {
        paddle->x = MIN_PADDLE_X;
    } else if (paddle->x > MAX_PADDLE_X) {
        paddle->x = MAX_PADDLE_X;
    }

}

