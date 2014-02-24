#ifndef INPUT_H
#define INPUT_H

#include "IncludeSDL.h"

extern int Input_numPlayers;
extern bool Input_releaseBall, Input_quit;
extern bool Input_hasInfiniteLives, Input_isSkippingLevel;
extern float Input_paddleHorizontal[4];
void Input_handle();

#endif
