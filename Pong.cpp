#include "SDL2/SDL.h"
#include <iostream>

static const int WIDTH = 1280;
static const int HEIGHT = 720;

int main(int argc, char const *argv[])
{
    SDL_Window *win = NULL;
    SDL_Renderer *render = NULL;

    static bool isRunning = true;

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
        std::cerr << "Error intitializing SDL" << std::endl;
        return -1;
    }
    
    win = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    if(win == NULL) {
        std::cerr << "Error creating window: " << SDL_GetError() << std::endl;
        return -1;
    }
    
    render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(render == NULL) {
        std::cerr << "Error creating renderer: " << SDL_GetError() << endl;
    }
    
    //core game loop begins     
    while(isRunning) {
        
    }

    SDL_Delay(10000);
    SDL_DestroyRenderer();
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
