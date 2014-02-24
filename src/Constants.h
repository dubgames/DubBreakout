#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "Sprite.h"
#include <vector>

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 730;
const int BUFFER_HEIGHT = 60;
const int SCORES_HEIGHT = BUFFER_HEIGHT;
const int TOP_PADDING = 100 + BUFFER_HEIGHT + SCORES_HEIGHT;
const int BOTTOM_PADDING = 14;
const int BLOCK_HEIGHT = 25;
const int BLOCK_WIDTH = 60;
const int BALL_WIDTH = 16;
const int COLUMNS = 18;
const int ROWS = 6;
const int NUMBER_OF_BLOCKS = ROWS * COLUMNS;
const int PADDLE_WIDTH = 113;
const int PADDLE_HEIGHT = 16;
const float BALL_INITIAL_VELOCITYX = 350;
const float BALL_INITIAL_VELOCITYY = 350;
const float BALL_INITIAL_X = 20;
const float BALL_INITIAL_Y = TOP_PADDING + ROWS * BLOCK_HEIGHT + 20;
const float PADDLE_VELOCITY = 1000;
const int INITIAL_LIVES = 5;
const float VELOCITYX_MULTIPLIER = 10;
const float VELOCITYX_PADDLE_RANGE = 20;

const SDL_Color BLUE = { 0x42, 0x49, 0xC8 };
const SDL_Color GREEN = { 0x48, 0xA0, 0x48 };
const SDL_Color YELLOW = { 0xA2, 0xA2, 0x2A };
const SDL_Color BROWN = { 0xB4, 0x7A, 0x30 };
const SDL_Color ORANGE = { 0xC6, 0x6C, 0x3A };
const SDL_Color RED = { 0xC8, 0x48, 0x48 };
const SDL_Color GRAY = { 0x8E, 0x8E, 0x8E };


inline sprite Constants_getTopBar() {
    sprite topbar;
    topbar.x = 0;
    topbar.y = SCORES_HEIGHT;
    topbar.width = SCREEN_WIDTH;
    topbar.height = BUFFER_HEIGHT;
    topbar.color = GRAY;
    topbar.isVisible = true;
    return topbar;
}

inline sprite* Constants_getPaddle(SDL_Color color) {
    sprite *paddle = (sprite*)malloc(sizeof(sprite));
    paddle->width = PADDLE_WIDTH;
    paddle->height = PADDLE_HEIGHT;
    paddle->x = SCREEN_WIDTH / 2;
    paddle->y = SCREEN_HEIGHT - PADDLE_HEIGHT - BOTTOM_PADDING;
    paddle->color = color;
    paddle->isVisible = true;
    paddle->velocityX = 0;
    paddle->velocityY = 0;
    return paddle;
}

inline sprite Constants_getBall() {
    sprite ball;
    ball.width = BALL_WIDTH;
    ball.height = BALL_WIDTH;
    ball.x = BALL_INITIAL_X;
    ball.y = BALL_INITIAL_Y;
    ball.color = RED;
    ball.velocityX = 0;
    ball.velocityY = 0;
    ball.isVisible = true;
    return ball;
}

inline std::vector<sprite*> Constants_getBlocks() {
    SDL_Color colors[ROWS] = { RED, ORANGE, BROWN, YELLOW, GREEN, BLUE };
    std::vector<sprite*> blocks;
    for (int row = ROWS-1; row >= 0; --row) {
        for (int column = 0; column < COLUMNS; ++column) {
            sprite *block = (sprite*) malloc(sizeof(sprite));
            block->x = column * BLOCK_WIDTH;
            block->y = TOP_PADDING + row * BLOCK_HEIGHT;
            block->width = BLOCK_WIDTH;
            block->height = BLOCK_HEIGHT;
            block->isVisible = true;
            block->color = colors[row];
            blocks.push_back(block);
        }
    }
    return blocks;
}

inline float Constants_getBallVelocity(sprite *ball, sprite *block, int level) {
    int row = ((ROWS * BLOCK_HEIGHT - (block->y - TOP_PADDING)) / BLOCK_HEIGHT);
    float rowMultiplier;
    switch (row) {
        case 6:
            rowMultiplier = 1.55;
        case 5:
            rowMultiplier = 1.45;
            break;
        case 4:
            rowMultiplier = 1.35;
            break;
        case 3:
            rowMultiplier = 1.25;
            break;
        case 2:
            rowMultiplier = 1.15;
            break;
        default:
            rowMultiplier = 1;
    }
    float levelMultiplier = .1 * (level - 1);
    float direction = 1;
    if (ball->velocityY > 0) {
        direction = -1;
    }
    return direction * (rowMultiplier + levelMultiplier) * BALL_INITIAL_VELOCITYY;
}

#endif
