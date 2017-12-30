#include "Game.h"

int Game_score = 0, Game_lives = INITIAL_LIVES, Game_level = 1, Game_targetScore = NUMBER_OF_BLOCKS;
bool Game_scoreUpdated = true;
bool Game_isOver = false, isDead = true;

void Game_update(std::vector<sprite *> *blocks, sprite *ball, sprite *paddles[], Uint32 timeDifferenceMillis) {

    if (Input_isSkippingLevel) {
        for (int i = 0; i < blocks->size(); ++i) {
            sprite *block = (*blocks)[i];
            if (block->isVisible) {
                block->isVisible = false;
                ++Game_score;
                break; // so that they don't all disappear at once
            }
        }
        Game_scoreUpdated = true;
    }

    if (Input_releaseBall && !Game_isOver && isDead) {
        isDead = false;
        ball->velocityX = BALL_INITIAL_VELOCITYX;
        ball->velocityY = BALL_INITIAL_VELOCITYY;
    } else if (Input_releaseBall && Game_isOver) {
        *ball = Constants_getBall();
        *blocks = Constants_getBlocks();
        Game_score = 0;
        Game_lives = INITIAL_LIVES;
        Game_isOver = false;
    }

    float timeDifferenceSeconds = timeDifferenceMillis / 1000.;

    for (int i = 0; i == 0 || i < Input_numPlayers; i++) {
        Paddle_update(paddles[i], timeDifferenceSeconds, Input_paddleHorizontal[i]);
    }

    Ball_update(ball, timeDifferenceSeconds);

    if (Ball_hasHitWall(ball)) {
        Sound_playSideHit();
    }

    for (int i = 0; i == 0 || i < Input_numPlayers; i++) {
        if (Ball_hasHitPaddle(ball, paddles[i])) {
            Sound_playPaddleHit();
        }
    }

    if (Ball_hasHitBlock(ball, blocks, Game_level)) {
        ++Game_score;
        Game_scoreUpdated = true;
        Sound_playBlockHit();
    }

    if (Game_score != 0 && Game_score == Game_targetScore) {
        ++Game_level;
        isDead = true;
        Game_targetScore += NUMBER_OF_BLOCKS;
        *blocks = Constants_getBlocks();
        *ball = Constants_getBall();
        Input_isSkippingLevel = false;
    }

    if (Ball_hasFallenOffBottom(ball)) {
        isDead = true;
        ball->x = BALL_INITIAL_X;
        ball->y = BALL_INITIAL_Y;
        ball->velocityY = 0;
        ball->velocityX = 0;
        if (!Input_hasInfiniteLives) {
            Game_lives--;
            Game_scoreUpdated = true;
            if (Game_lives == 0) {
                Game_level = 1;
                Game_isOver = true;
            }
        }
    }

}