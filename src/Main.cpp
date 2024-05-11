#include<headers/sim.h>
//#include<headers/vectors.h>
#include<iostream>



int main(int argc, char* argv[]){
    int screenWidth = 800;
    int screenHeight = 800;


    Sim sim("Simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);

    sim.run();

    Vector2D<double> a;

    /*std::cout<<a.getX()<<" "<<a.getY()<<std::endl;

    a = 3.0 + a;

    std::cout<<a.getX()<<" "<<a.getY()<<std::endl;
    */

    return 0;
}