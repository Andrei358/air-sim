#ifndef INCLUDE_HEADERS_WALL_H
#define INCLUDE_HEADERS_WALL_H

#include<headers/vectors.h>
#include<headers/particle.h>
#include<utility>

template<class Scalar> class Wall;
template<class Scalar> class Particle;
template<class Scalar> Vector2D<Scalar> collision(Particle<Scalar> &a, Wall<Scalar> &b);

template<class Scalar>
class Wall {
    public:
        Wall(Vector2D<Scalar> part1, Vector2D<Scalar> part2, Scalar t);

        std::pair<Vector2D<Scalar>, Vector2D<Scalar>> getCoords();

        // Vector2D<Scalar> momentum();

        // void update(Scalar dt);

        friend Vector2D<Scalar> collision <>(Particle<Scalar> &a, Wall<Scalar> &b);
        
    private:
        Vector2D<Scalar> p1;
        Vector2D<Scalar> p2;
        Scalar thickness;

};

#endif 