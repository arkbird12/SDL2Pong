#include "SDL2/SDL.h"
#include <iostream>

static const int WIDTH = 1280;
static const int HEIGHT = 720;

int main(int argc, char const *argv[])
{
    SDL_Window *win = NULL;
    SDL_Renderer *render = NULL;
    SDL_Event event;

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
        std::cerr << "Error creating renderer: " << SDL_GetError() << std::endl;
    }
    
    SDL_SetRenderDrawColor(render, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(render);
    SDL_RenderPresent(render);

    //core game loop begins     
    while(isRunning) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                isRunning = false;
            }
            if(event.type == SDL_KEYDOWN) {
                isRunning = false;
            }
        }
    }

    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
