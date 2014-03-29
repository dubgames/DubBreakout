#include "Input.h"

#include <vector>

bool Input_releaseBall = false, Input_quit = false;
float Input_paddleHorizontal[4];
int Input_numPlayers = 1;

bool Input_hasInfiniteLives = false; // dgdqd
bool Input_isSkippingLevel = false; // dgkfb

std::vector<SDL_GameController *> controllers;

const int JOYSTICK_SDL_MAX = 32767;
const int JOYSTICK_SDL_MIN = 32768;
const int JOYSTICK_DEADZONE = 6000;
const int JOYSTICK_MAXXEDZONE = 4000;
const int JOY_UNUSED = JOYSTICK_DEADZONE + JOYSTICK_MAXXEDZONE;
const float JOYSTICK_MAX = JOYSTICK_SDL_MAX - JOY_UNUSED;
const float JOYSTICK_MIN = JOYSTICK_SDL_MIN - JOY_UNUSED;

int cheat_index = 0;

bool cheat_increment(int index) {
    if (cheat_index == index) {
        cheat_index++;
        return true;
    } else {
        cheat_index = 0;
        return false;
    }
}

void controllers_remove() {
    for (int i = 0; i < controllers.size(); ++i) {
        if (!SDL_GameControllerGetAttached(controllers[i])) {
            SDL_GameControllerClose(controllers[i]);
            controllers.erase(controllers.begin() + i);
        }
    }
}

void controllers_add() {
    for (int i = (int) controllers.size(); i < SDL_NumJoysticks(); ++i) {
        if (SDL_IsGameController(i)) {
            controllers.push_back(SDL_GameControllerOpen(i));
        }
    }
}

void controllers_addAndRemove() {
    int controllers_attached = SDL_NumJoysticks();
    if (controllers_attached > controllers.size()) {
        controllers_add();
    } else if (controllers_attached < controllers.size()) {
        controllers_remove();
    }
    Input_numPlayers = controllers.size() > 1 ? (int) controllers.size() : 1;
}

void checkPlayInput() {
    Input_paddleHorizontal[0] = 0;
    Input_releaseBall = false;

    controllers_addAndRemove();

    // controllers
    for (int i = 0; i < controllers.size(); ++i) {
        const Uint8 button = SDL_GameControllerGetButton(controllers[i], SDL_GameControllerGetButtonFromString("a"));
        if (button) {
            Input_releaseBall = true;
        }

        const Sint16 xaxis = SDL_GameControllerGetAxis(controllers[i], SDL_GameControllerGetAxisFromString("leftx"));
        if (abs(xaxis) > JOYSTICK_DEADZONE) {
            if (xaxis > 0) {
                Input_paddleHorizontal[i] += (xaxis - JOYSTICK_DEADZONE) / JOYSTICK_MAX;
                if (Input_paddleHorizontal[i] > 1.f) {
                    Input_paddleHorizontal[i] = 1.f;
                }
            } else {
                Input_paddleHorizontal[i] += (xaxis + JOYSTICK_DEADZONE) / JOYSTICK_MIN;
                if (Input_paddleHorizontal[i] < -1.f) {
                    Input_paddleHorizontal[i] = -1.f;
                }
            }
        } else {
            Input_paddleHorizontal[i] = 0;
        }
    }

    // keyboard
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_RIGHT]) {
        Input_paddleHorizontal[0] = 1.;
    } else if (state[SDL_SCANCODE_LEFT]) {
        Input_paddleHorizontal[0] = -1.;
    }

    if (state[SDL_SCANCODE_SPACE]) {
        Input_releaseBall = true;
    }

    if (state[SDL_SCANCODE_ESCAPE]) {
        Input_quit = true;
    }
}

void checkQuitAndCheats() {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        switch (e.type) {
            case SDL_QUIT:
                Input_quit = true;
                break;

            case SDL_KEYUP:
                // cheats
                switch (e.key.keysym.sym) {
                    case SDLK_d:
                        switch (cheat_index) {
                            case 0:
                            case 2:
                                cheat_index++;
                                break;
                            case 4:
                                Input_hasInfiniteLives = true;
                                cheat_index = 0;
                                break;
                            default:
                                cheat_index = 0;
                                break;
                        }
                        break;
                    case SDLK_g:
                        cheat_increment(1);
                        break;
                    case SDLK_q:
                        cheat_increment(3);
                        break;
                    case SDLK_k:
                        cheat_increment(2);
                        break;
                    case SDLK_f:
                        cheat_increment(3);
                        break;
                    case SDLK_b:
                        if (cheat_increment(4)) {
                            Input_isSkippingLevel = true;
                            cheat_index = 0;
                        }
                        break;
                    default:
                        cheat_index = 0;
                        break;
                }
        }
    }
}

void Input_handle() {
    checkPlayInput();
    checkQuitAndCheats();
}