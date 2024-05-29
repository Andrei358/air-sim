//#include<headers/sim.h>
#include<headers/vectors.h>
#include<iostream>

int main(int argc, char* argv[]){
    int screenWidth = 800;
    int screenHeight = 800;


    //Sim sim("Simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);

    //sim.run();

    Vector2D<float> a(1.0, 3.0), b;
    std::cout<<a.getX()<<" "<<a.getY()<<std::endl;

    b = (float)2.0 + a;
    std::cout<<b.getX()<<" "<<b.getY()<<std::endl;

    a = a + (float)-2.0;
    std::cout<<a.getX()<<" "<<a.getY()<<std::endl;

    std::cout<<a.norm()<<std::endl;

    // a = (float)3.0 + a;

    // std::cout<<a.getX()<<" "<<a.getY()<<std::endl;
    
    return 0;
}

// int operator+<>(int a, int b) {
//     return 3;
// }