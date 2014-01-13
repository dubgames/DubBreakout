#include "main.h"

float screen_scale = 1.f;
Mix_Chunk *paddleHitSound, *sideHitSound, *blockHitSound;

void log_error(const char* in) {
    printf("Error: %s", in);
    const char* sdlError = SDL_GetError();
    if (sdlError != NULL) {
        printf("\nSDL Error: %s", sdlError);
    }
    printf("\n");
}

SDL_Window* create_window() {
    SDL_Window *window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        log_error("Window didn't create");
    }
    return window;
}

bool init() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
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
    return true;
}

void destroy() {
    TTF_Quit();
  	Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

void playSound(Mix_Chunk *sound) {
    if (Mix_PlayChannel(-1, sound, 0) < 0) {
        log_error("Unable to play sound");
    }
}

void playPaddleHitSound() {
    playSound(paddleHitSound);
}

void playSideHitSound() {
    playSound(sideHitSound);
}

void playBlockHitSound() {
    playSound(blockHitSound);
}

bool loadSound(Mix_Chunk **chunk, const char *file) {
    *chunk = Mix_LoadWAV(file);
    if (*chunk == NULL) {
        log_error(file);
        return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    bool isInitFine = init();
    SDL_Window *window = create_window();
    
    if (!isInitFine || window == NULL) {
        return -1;
    }
    
    // Create renderer and set view port
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Rect viewport = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
    SDL_RenderSetViewport(renderer, &viewport);
    
    TTF_Font *font = TTF_OpenFont("assets/ATARCE__.TTF", 50);
    if (font == NULL) {
        log_error("Font failed to load!");
        return -1;
    }
    
    SDL_Surface *scoreSurface = NULL;
    SDL_Texture *scoreTexture = NULL;
    SDL_Rect scoreSrcRect, scoreDstRect;
    char scoreBuffer[9];
  
    loadSound(&paddleHitSound, "assets/paddle.ogg");
    loadSound(&sideHitSound, "assets/thump.wav");
    loadSound(&blockHitSound, "assets/beep.ogg");
    
    struct sprite paddle = getPaddle(), ball = getBall(), topbar = getTopBar();
   
    std::vector<struct sprite*> blocks = getBlocks();
    
    Uint32 start_time = SDL_GetTicks(), time_diff = SDL_GetTicks(), time_taken;
    
    while (!isQuitPressed) {
        time_diff = SDL_GetTicks() - start_time;
        start_time = SDL_GetTicks();
        
        handle_input();
        
        updateGameState(&blocks, &ball, &paddle, time_diff);
        
        // Clear screen to white
        SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);
        SDL_RenderClear(renderer);

        renderSprite(renderer, topbar);
        
        // Render elements on screen
        for (struct sprite *block : blocks) {
            if (block->isVisible) {
                renderSprite(renderer, *block);
            }
        }
        renderSprite(renderer, paddle);
        renderSprite(renderer, ball);
        
        if (isScoreNeedingUpdate) {
            isScoreNeedingUpdate = false;
            sprintf(scoreBuffer, "%03d %d %2d", score, lives, level);
            
            if (scoreSurface != NULL) {
                SDL_FreeSurface(scoreSurface);
                scoreSurface = NULL;
            }
            scoreSurface = TTF_RenderText_Solid(font, scoreBuffer, GRAY);
            
            if (scoreTexture != NULL) {
                SDL_DestroyTexture(scoreTexture);
                scoreTexture = NULL;
            }
            scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
            
            scoreSrcRect = { 0, 0, scoreSurface->w, scoreSurface->h };
            scoreDstRect = { 600, 5, scoreSurface->w, scoreSurface->h };
        }
        

        SDL_RenderCopy(renderer, scoreTexture, &scoreSrcRect, &scoreDstRect);
        
        
        // Set scale and render
        SDL_RenderSetScale(renderer, screen_scale, screen_scale);
        SDL_RenderPresent(renderer);
        
        
        // Cap frame rate
        time_taken = SDL_GetTicks() - start_time;
        if (time_taken < TIME_PER_FRAME) {
            SDL_Delay(TIME_PER_FRAME - time_taken);
        }
    }
    
    for (struct sprite *block : blocks) {
        free(block);
    }
    
    TTF_CloseFont(font);
    Mix_FreeChunk(paddleHitSound);
    Mix_FreeChunk(blockHitSound);
    Mix_FreeChunk(sideHitSound);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    destroy();
    return 0;
}
