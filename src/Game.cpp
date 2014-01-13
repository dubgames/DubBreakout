#include "Game.h"

int score = 0, lives = INITIAL_LIVES, level = 1, targetScore = NUMBER_OF_BLOCKS;
bool isScoreNeedingUpdate = true;
bool isGameOver = false;

void updateGameState(std::vector<struct sprite*> *blocks, struct sprite *ball, struct sprite *paddle, Uint32 time_diff) {
    
    if (isCheatDestroyAllBlocks) {
        for (struct sprite *block : *blocks) {
            if (block->isVisible) {
                block->isVisible = false;
                ++score;
                break;
            }
        }
        isScoreNeedingUpdate = true;
    }
    
    if (isSpacePressed && !isGameOver) {
        ball->velocityX = BALL_INITIAL_VELOCITYX;
        ball->velocityY = BALL_INITIAL_VELOCITYY;
    } else if (isSpacePressed && isGameOver) {
        *ball = getBall();
        *blocks = getBlocks();
        score = 0;
        lives = INITIAL_LIVES;
        isGameOver = false;
    }
    
    float time_passed = time_diff / 1000.;
    updatePaddle(paddle, time_passed, isLeftPressed, isRightPressed);
    updateBall(ball, time_passed);
    
    if (hasCollidedWithTopLeftRight(ball)) {
        playSideHitSound();
    }
    
    if (hasCollidedWithPaddle(ball, paddle)) {
        playPaddleHitSound();
    }
    
    if (hasCollidedWithBlock(ball, blocks, level)) {
        ++score;
        isScoreNeedingUpdate = true;
        playBlockHitSound();
    }
    
    if (score != 0 && score == targetScore) {
        ++level;
        targetScore += NUMBER_OF_BLOCKS;
        *blocks = getBlocks();
        *ball = getBall();
        isCheatDestroyAllBlocks = false;
    }
    
    if (hasFallenOffBottom(ball)) {
        if (!isCheatInfiniteLives) {
            lives--;
            isScoreNeedingUpdate = true;
            if (lives == 0) {
                level = 1;
                isGameOver = true;
            }
        }
    }

}