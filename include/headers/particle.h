#ifndef INCLUDE_HEADERS_PARTICLE_H
#define INCLUDE_HEADERS_PARTICLE_H

#include<headers/vectors.h>
#include<utility>

template<class Scalar> class Particle;
template<class Scalar> std::pair<Vector2D<Scalar>, Vector2D<Scalar>> collision(Particle<Scalar> a, Particle<Scalar> b);

template<class Scalar>
class Particle {
    public:
        Particle(Scalar m, Vector2D<Scalar> p, Vector2D<Scalar> v);

        Scalar energy();
        Scalar momentum();
        
        friend std::pair<Vector2D<Scalar>, Vector2D<Scalar>> collision <>(Particle<Scalar> a, Particle<Scalar> b);

    private:
        Scalar mass;
        Vector2D<Scalar> position;
        Vector2D<Scalar> velocity;
};

#endif 