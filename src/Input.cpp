#include "Input.h"

bool isLeftPressed = false, isRightPressed = false, isUpPressed = false, isDownPressed = false, isSpacePressed = false, isQuitPressed = false;

bool isCheatInfiniteLives = false; // dgdqd
bool isCheatDestroyAllBlocks = false; // dgkfb

int cheatIndex = 0;

bool incrementCheat(int index) {
    if (cheatIndex == index) {
        cheatIndex++;
        return true;
    } else {
        cheatIndex = 0;
        return false;
    }
}

void handle_input() {
    SDL_Event e;
    while (SDL_PollEvent( &e ) != 0) {
        switch (e.type) {
            case SDL_QUIT:
                isQuitPressed = true;
                break;
            case SDL_KEYDOWN:
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        isUpPressed = true;
                        break;                        
                    case SDLK_DOWN:
                        isDownPressed = true;
                        break;
                    case SDLK_LEFT:
                        isLeftPressed = true;
                        break;
                    case SDLK_RIGHT:
                        isRightPressed = true;
                        break;
                    case SDLK_SPACE:
                        isSpacePressed = true;
                        break;
                    case SDLK_ESCAPE:
                        isQuitPressed = true;
                        break;
                }
                break;
            case SDL_KEYUP:
                // paddle
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        isUpPressed = false;
                        break;
                    case SDLK_DOWN:
                        isDownPressed = false;
                        break;
                    case SDLK_LEFT:
                        isLeftPressed = false;
                        break;
                    case SDLK_RIGHT:
                        isRightPressed = false;
                        break;
                    case SDLK_SPACE:
                        isSpacePressed = false;
                        break;
                }
                
                // cheats
                switch (e.key.keysym.sym) {
                    case SDLK_d:
                        switch (cheatIndex) {
                            case 0:
                            case 2:
                                cheatIndex++;
                                break;
                            case 4:
                                isCheatInfiniteLives = true;
                                cheatIndex = 0;
                                break;
                            default:
                                cheatIndex = 0;
                                break;
                        }
                        break;
                    case SDLK_g:
                        incrementCheat(1);
                        break;
                    case SDLK_q:
                        incrementCheat(3);
                        break;
                    case SDLK_k:
                        incrementCheat(2);
                        break;
                    case SDLK_f:
                        incrementCheat(3);
                        break;
                    case SDLK_b:
                        if (incrementCheat(4)) {
                            isCheatDestroyAllBlocks = true;
                            cheatIndex = 0;
                        }
                        break;
                    default:
                        cheatIndex = 0;
                        break;
                }
        }
    }
}