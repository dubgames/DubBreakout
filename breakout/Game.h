#ifndef GAME_H
#define GAME_H

#include "Constants.h"
#include "Input.h"
#include "Paddle.h"
#include "Ball.h"
#include "Sound.h"

extern int Game_score, Game_lives, Game_level, Game_targetScore;
extern bool Game_scoreUpdated, Game_isOver;

void Game_update(std::vector<sprite *> *blocks, sprite *ball, sprite *paddles[], Uint32 timeDifferenceMillis);

#endif
