#include<headers/sim.h>
//#define private public

#include<headers/vectors.h>
#include<headers/particle.h>
#include<iostream>


int main(int argc, char* argv[]){
    int screenWidth = 800;
    int screenHeight = 800;


    Sim sim("Simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);

    sim.run();

    return 0;
}

// int operator+<>(int a, int b) {
//     return 3;
// }

// Particle<double> a(100, Vector2D<double>(100,100), Vector2D<double>(10,0));
// Particle<double> b(50, Vector2D<double>(110,100), Vector2D<double>(-10,10));

// std::cout<<a.velocity<<" "<<a.energy()<<" "<<a.momentum()<<std::endl;
// std::cout<<b.velocity<<" "<<b.energy()<<" "<<b.momentum()<<std::endl;
// collision(a,b);
// std::cout<<a.velocity<<" "<<a.energy()<<" "<<a.momentum()<<std::endl;
// std::cout<<b.velocity<<" "<<b.energy()<<" "<<b.momentum()<<std::endl;
// //std::cout<<collision(a, b).first<<" "<<collision(a, b).second;
