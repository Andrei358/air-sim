#ifndef INCLUDE_HEADERS_SIM_H
#define INCLUDE_HEADERS_SIM_H

#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

enum class SimState {PLAY, EXIT};

class Sim {
    public:
        Sim(const char* title, int x, int y, int w, int h, Uint32 flags);
        void run();

    private:
        void handleEvents();

        SDL_Window* window;
        SDL_Renderer* renderer;

        SimState _simState;
};

#endif 