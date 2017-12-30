#include "Sound.h"
#include "IncludeSDL.h"
#include "System.h"

Mix_Chunk *paddleHitSound, *sideHitSound, *blockHitSound;


void playSound(Mix_Chunk *sound) {
    if (Mix_PlayChannel(-1, sound, 0) < 0) {
        log_error("Unable to play sound");
    }
}

void Sound_playPaddleHit() {
    playSound(paddleHitSound);
}

void Sound_playSideHit() {
    playSound(sideHitSound);
}

void Sound_playBlockHit() {
    playSound(blockHitSound);
}

bool load(Mix_Chunk **chunk, const char *file) {
    *chunk = Mix_LoadWAV(file);
    if (*chunk == NULL) {
        log_error(file);
        return false;
    }
    return true;
}

void Sound_load() {
    load(&paddleHitSound, "assets/paddle.ogg");
    load(&sideHitSound, "assets/thump.wav");
    load(&blockHitSound, "assets/beep.ogg");
}

void Sound_unload() {
    Mix_FreeChunk(paddleHitSound);
    Mix_FreeChunk(blockHitSound);
    Mix_FreeChunk(sideHitSound);
}