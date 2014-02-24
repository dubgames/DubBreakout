#include "Sprite.h"
#include "Constants.h"
#include "Input.h"
#include "Game.h"
#include "System.h"

int main(int argc, char* argv[]) {
    bool isInitOk = System_init(SCREEN_WIDTH, SCREEN_HEIGHT);
  
    if (!isInitOk) {
        return -1;
    }
           
    sprite ball = Constants_getBall(), topbar = Constants_getTopBar();
    sprite* paddles[4];
    paddles[0] = Constants_getPaddle(RED);
    paddles[1] = Constants_getPaddle(BLUE);
    paddles[2] = Constants_getPaddle(GREEN);
    paddles[3] = Constants_getPaddle(YELLOW);
   
    std::vector<sprite*> blocks = Constants_getBlocks();
              
    while (!Input_quit) {
        Uint32 timeDifferenceMillis = System_startFrame();        
        
        Input_handle();
                
        Game_update(&blocks, &ball, paddles, timeDifferenceMillis);
        
	System_render(&topbar, &ball, &blocks, paddles);
        
	System_endFrame();
    }
    
    for (int i = 0; i < 4; i++) {
        free(paddles[i]);
    }
    for (int i = 0; i < blocks.size(); ++i) {
	free(blocks[i]);
    }
    
    System_quit();
    return 0;
}
