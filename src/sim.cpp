#include<headers/sim.h>
#include<headers/shapes.h>



template<class Scalar>
Vector2D<Scalar>::Vector2D() {
    x = 1;
    y = 1;
}


Sim::Sim(const char* title, int x, int y, int w, int h, Uint32 flags) {
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(title, x, y, w, h, flags);
    renderer = SDL_CreateRenderer(window, -1, 0);

    /*SDL_SetRenderDrawColor(renderer, 242, 230, 202, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 22, 2, 22, 255);
    DrawCircle(renderer, 400, 400, 100);
    DrawDisk(renderer, 530, 400, 100);
    SDL_RenderPresent(renderer);*/

    _simState = SimState::PLAY;
};

void draw_edges(SDL_Renderer * renderer){
    SDL_RenderDrawLine(renderer, 30, 30, 770, 30);
    SDL_RenderDrawLine(renderer, 30, 30, 30, 770);
    SDL_RenderDrawLine(renderer, 770, 30, 770, 770);
    SDL_RenderDrawLine(renderer, 30, 770, 770, 770);
}


void Sim::run() {
    float t = 0.0;
    float dt = 0.1;
    float xspeed = 10;
    float yspeed = 20;
    float x = 400;
    float y = 400;

    while (_simState != SimState::EXIT) {
        handleEvents();
        SDL_SetRenderDrawColor(renderer, 242, 230, 202, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 22, 2, 22, 255);
        draw_edges(renderer);
        DrawDisk(renderer, x, y, 50);
        SDL_RenderPresent(renderer);
        x = x + xspeed*dt;
        y = y + yspeed*dt;
        std::cout<<x<<std::endl;
        SDL_Delay(30);
    }
}

void Sim::handleEvents() {
    SDL_Event evnt;
    SDL_PollEvent(&evnt);

    switch(evnt.type) {
        case SDL_QUIT:
            _simState = SimState::EXIT;
            break;
    }
}