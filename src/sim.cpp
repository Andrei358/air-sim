#include<headers/sim.h>
#include<headers/shapes.h>
#include<headers/particle.h>
#include<headers/wall.h>
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

void draw_edges(SDL_Renderer * renderer, const std::vector<Wall<double>>& walls){
    for (auto x: walls){
        Vector2D<double> p1 = x.getCoords().first;
        Vector2D<double> p2 = x.getCoords().second;
        SDL_RenderDrawLine(renderer, p1.getX(), p1.getY(), p2.getX(), p2.getY());
    }
}

void draw_particles(SDL_Renderer * renderer, const std::vector<Particle<double>>& particles){
    for (auto x: particles){
        DrawDisk(renderer, x.getPosition().getX(), x.getPosition().getY(), 15);
    }
}

bool particles_collision_detection(Particle<double> p1, Particle<double> p2){
    Vector2D<double> dist_vector = p1.getPosition() - p2.getPosition();
    double dist = dist_vector.norm();

    return (dist <= 2 * 15);
}

bool particle_wall_collision_detection(Particle<double> p, Wall<double> w){
    Vector2D<double> diff =  w.getCoords().first - p.getPosition();
    Vector2D<double> n = (w.getCoords().second - w.getCoords().first) / (w.getCoords().second - w.getCoords().first).norm();
    double dist = (diff - (diff.dot(n)) * n).norm();

    return (dist <= 15);
}

void handle_collisions(std::vector<Particle<double>>& particles, std::vector<Wall<double>>& walls){
    int n_particles = particles.size();
    int n_walls = walls.size();

    for (int i = 0; i < n_particles; ++i){
        for(int j = i + 1; j < n_particles; ++j){
            if (particles_collision_detection(particles[i], particles[j]))
                collision(particles[i], particles[j]);
        }
    }

    for (int i = 0; i < n_particles; ++i){
        for(int j = 0; j < n_walls; ++j){
            if (particle_wall_collision_detection(particles[i], walls[j]))
                collision(particles[i], walls[j]);
        }
    }
}

void Sim::run() {
    float t = 0.0;
    float dt = 2.0;

    std::vector<Particle<double>> particles;
    particles.push_back(Particle<double>(10, Vector2D<double>(100,100), Vector2D<double>(10,10)));
    particles.push_back(Particle<double>(10, Vector2D<double>(300,400), Vector2D<double>(-10,-4)));
    particles.push_back(Particle<double>(10, Vector2D<double>(270,350), Vector2D<double>(-4,7)));
    particles.push_back(Particle<double>(10, Vector2D<double>(130,200), Vector2D<double>(10,-3)));
    particles.push_back(Particle<double>(10, Vector2D<double>(220,690), Vector2D<double>(-10,-4)));
    particles.push_back(Particle<double>(10, Vector2D<double>(520,415), Vector2D<double>(4,11)));
    particles.push_back(Particle<double>(10, Vector2D<double>(280,200), Vector2D<double>(12,8)));
    particles.push_back(Particle<double>(10, Vector2D<double>(400,190), Vector2D<double>(-10,3.5)));
    particles.push_back(Particle<double>(10, Vector2D<double>(120,315), Vector2D<double>(4,7)));
    
    std::vector<Wall<double>> walls;
    walls.push_back(Wall<double>(Vector2D<double>(30, 30), Vector2D<double>(770, 30), 0));
    walls.push_back(Wall<double>(Vector2D<double>(30, 30), Vector2D<double>(30, 770), 0));
    walls.push_back(Wall<double>(Vector2D<double>(770, 30), Vector2D<double>(770, 770), 0));
    walls.push_back(Wall<double>(Vector2D<double>(30, 770), Vector2D<double>(770, 770), 0));

    while (_simState != SimState::EXIT) {
        handleEvents();

        //draw background
        SDL_SetRenderDrawColor(renderer, 242, 230, 202, 255);
        SDL_RenderClear(renderer);

        //draw edges
        SDL_SetRenderDrawColor(renderer, 22, 2, 22, 255);
        draw_edges(renderer, walls);
        
        //draw particles
        draw_particles(renderer, particles);

        //present renderer
        SDL_RenderPresent(renderer);

        handle_collisions(particles, walls);

        for (auto& x: particles)
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