#include "System.h"
#include "ScoreBar.h"
#include "Game.h"

const int FRAMES_PER_SECOND = 60;
const Uint32 TIME_PER_FRAME = 1000 / FRAMES_PER_SECOND;

SDL_Window *window;
SDL_Renderer *renderer;
Uint32 start_time = 0, timeDifferenceMillis, time_taken;


void log_error(const char* in) {
    printf("Error: %s", in);
    const char* sdlError = SDL_GetError();
    if (sdlError != NULL) {
        printf("\nSDL Error: %s", sdlError);
    }
    printf("\n");
}


SDL_Window* System_createWindow(int width, int height) {
    SDL_Window *window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        log_error("Window didn't create");
    }
    return window;
}

bool System_init(int width, int height) {
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER) < 0) {
        log_error("SDL Init failed");
        return false;
    }
    
    if (!SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1")) {
        log_error("SDL Set VSYNC failed");
    }
    
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        log_error("IMG Init failed");
        return false;
    }
    
    if (TTF_Init() < 0) {
        log_error("TTF Init failed");
        return false;
    }
    
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        log_error("Mix_OpenAudio failed");
        return false;
    }
    
    window = System_createWindow(width, height);
    if (window == NULL) {
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Rect viewport = { 0, 0, width, height };
    SDL_RenderSetViewport(renderer, &viewport);
    
	ScoreBar_create();
    Sound_load();

    return true;
}

void System_quit() {
    Sound_unload();
	ScoreBar_destroy();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

Uint32 System_startFrame() {
	if (start_time == 0) start_time = SDL_GetTicks();
	timeDifferenceMillis = SDL_GetTicks() - start_time;
	start_time = SDL_GetTicks();
	return timeDifferenceMillis;
}

void System_endFrame() {
	// Cap frame rate
	time_taken = SDL_GetTicks() - start_time;
	if (time_taken < TIME_PER_FRAME) {
		SDL_Delay(TIME_PER_FRAME - time_taken);
	}
}

void System_clearScreen() {
	SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);
	SDL_RenderClear(renderer);
}

SDL_Rect* getRect(sprite *s) {    
    s->rect.x = s->x;
    s->rect.y = s->y;
    s->rect.w = s->width;
    s->rect.h = s->height;
    return &s->rect;
}

void System_renderSprite(sprite *sprite) {
	 if (sprite->isVisible) {
        SDL_Color c = sprite->color;
        SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, 0xFF);
        SDL_RenderFillRect(renderer, getRect(sprite));
    }
}

void System_present() {	
	SDL_RenderSetScale(renderer, 1.f, 1.f);
	SDL_RenderPresent(renderer);
}

void System_render(sprite* topbar, sprite* ball, std::vector<sprite*> *blocks, sprite* paddles[]) {
	System_clearScreen();

	System_renderSprite(topbar);        

	for (int i = 0; i < blocks->size(); ++i) {
		sprite *block = (*blocks)[i];
		if (block->isVisible) {
			System_renderSprite(block);
		}
	}

	for (int i = 0; i == 0 || i < Input_numPlayers; i++) {
		System_renderSprite(paddles[i]);
	}
	System_renderSprite(ball);

	ScoreBar_render(renderer, Game_scoreUpdated, Game_score, Game_lives, Game_level);
	Game_scoreUpdated = false;

	System_present();
}
