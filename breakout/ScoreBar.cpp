#include "ScoreBar.h"
#include "System.h"
#include "Constants.h"

TTF_Font *font;

bool loadFont(const char *filename, int size) {
    font = TTF_OpenFont(filename, size);
    if (font == NULL) {
        log_error("Font failed to load!");
        return false;
    }
    return true;
}

void closeFont() {
    TTF_CloseFont(font);
}

SDL_Surface *scoreSurface = NULL;
SDL_Texture *scoreTexture = NULL;
SDL_Rect scoreSrcRect, scoreDstRect;
char scoreBuffer[9];

void freeMemory() {
    if (scoreSurface != NULL) {
        SDL_FreeSurface(scoreSurface);
        scoreSurface = NULL;
    }
    if (scoreTexture != NULL) {
        SDL_DestroyTexture(scoreTexture);
        scoreTexture = NULL;
    }
}

void ScoreBar_render(SDL_Renderer *renderer, bool update, int score, int lives, int level) {
    if (update) {
        sprintf(scoreBuffer, "%03d %d %2d", score, lives, level);

        freeMemory();
        scoreSurface = TTF_RenderText_Solid(font, scoreBuffer, GRAY);
        scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);

        scoreSrcRect.x = 0;
        scoreSrcRect.y = 0;
        scoreSrcRect.w = scoreSurface->w;
        scoreSrcRect.h = scoreSurface->h;

        scoreDstRect.x = 600;
        scoreDstRect.y = 5;
        scoreDstRect.w = scoreSurface->w;
        scoreDstRect.h = scoreSurface->h;
    }

    SDL_RenderCopy(renderer, scoreTexture, &scoreSrcRect, &scoreDstRect);
}

void ScoreBar_create() {
    loadFont("assets/ATARCE__.TTF", 50);
}

void ScoreBar_destroy() {
    closeFont();
    freeMemory();
}