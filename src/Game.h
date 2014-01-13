#ifndef GAME_H
#define GAME_H

#include "Constants.h"
#include "Input.h"
#include "Paddle.h"
#include "Ball.h"
#include "main.h"

extern int score, lives, level, targetScore;
extern bool isScoreNeedingUpdate, isGameOver;

void updateGameState(std::vector<struct sprite*> *blocks, struct sprite *ball, struct sprite *paddle, Uint32 time_diff);
    
#endif
