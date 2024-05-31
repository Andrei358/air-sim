#include<headers/sim.h>
#include<headers/shapes.h>
#include<headers/particle.h>
#include<vector>

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

void draw_particles(SDL_Renderer * renderer, const std::vector<Particle<double>>& particles){
    for (auto x: particles){
        DrawDisk(renderer, x.getPosition().getX(), x.getPosition().getY(), 20);
    }
}


void Sim::run() {
    float t = 0.0;
    float dt = 0.5;

    std::vector<Particle<double>> v;
    v.push_back(Particle<double>(10, Vector2D<double>(100,100), Vector2D<double>(10,10)));
    v.push_back(Particle<double>(10, Vector2D<double>(300,400), Vector2D<double>(-10,-4)));
    v.push_back(Particle<double>(10, Vector2D<double>(200,150), Vector2D<double>(-4,7)));

    while (_simState != SimState::EXIT) {
        handleEvents();

        //draw background
        SDL_SetRenderDrawColor(renderer, 242, 230, 202, 255);
        SDL_RenderClear(renderer);

        //draw edges
        SDL_SetRenderDrawColor(renderer, 22, 2, 22, 255);
        draw_edges(renderer);
        
        //draw particles
        draw_particles(renderer, v);

        //present renderer
        SDL_RenderPresent(renderer);

        for (auto& x: v)
            x.update(dt);

        SDL_Delay(30);
    }
}

void Sim::handleEvents() {
    SDL_Event evnt;
    SDL_PollEvent(&evnt);

    switch(evnt.type) {
        case SDL_QUIT:
            _simState = SimState::EXIT;
            break; //why????????
    }
}