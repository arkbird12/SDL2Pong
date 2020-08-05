#include "SDL2/SDL.h"
#include <iostream>

static const int WIDTH = 1280;
static const int HEIGHT = 720;

void drawBoard(SDL_Renderer *render);

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
    
    drawBoard(render);

    //core game loop begins     
    while(isRunning) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                isRunning = false;
            }
            if(event.type == SDL_KEYDOWN) {
                isRunning = false;
            }
            if(event.type == SDL_MOUSEBUTTONUP) {
                isRunning = false;
            }
        }
    }

    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}

void drawBoard(SDL_Renderer *render) {
    //renders background color
    SDL_RenderClear(render);
    SDL_SetRenderDrawColor(render, 0, 0, 0, SDL_ALPHA_OPAQUE);

    //renders "net"
    SDL_SetRenderDrawColor(render, 255, 255, 255, SDL_ALPHA_OPAQUE);

    SDL_RenderDrawLine(render, 0, 70, WIDTH, 70);

    for (int y = 70; y < HEIGHT; y++) { //leave 70px gap to keep score and time 
        if (y % 5) {
            SDL_RenderDrawPoint(render, WIDTH / 2, y);
        }
    }

    //renders

    SDL_RenderPresent(render);


}
