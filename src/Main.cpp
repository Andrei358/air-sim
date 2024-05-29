//#include<headers/sim.h>
#include<headers/vectors.h>
#include<iostream>

int main(int argc, char* argv[]){
    int screenWidth = 800;
    int screenHeight = 800;


    //Sim sim("Simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);

    //sim.run();

    Vector2D<double> a(1.0, 3.0), b;
    std::cout<<a<<std::endl;

    b = 2.0 + a;
    std::cout<<b<<std::endl;

    std::cout<<2.0 + a - 2.0<<std::endl;

    std::cout<<a.norm()<<std::endl;

    // a = (float)3.0 + a;

    // std::cout<<a.getX()<<" "<<a.getY()<<std::endl;
    
    return 0;
}

// int operator+<>(int a, int b) {
//     return 3;
// }