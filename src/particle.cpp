#include<headers/particle.h>

template<class Scalar>
Particle<Scalar>::Particle(Scalar m, Vector2D<Scalar> p, Vector2D<Scalar> v) {
    mass = m;
    position = p;
    velocity = v;
}

template<class Scalar>
Vector2D<Scalar> Particle<Scalar>::getPosition(){
    return position;
}

template<class Scalar>
Scalar Particle<Scalar>::energy() {
    return mass * velocity.norm() * velocity.norm();
}

template<class Scalar>
Vector2D<Scalar> Particle<Scalar>::momentum() {
    return mass * velocity;
}

template<class Scalar>
void Particle<Scalar>::update(Scalar dt){
    position = position + velocity * dt;
}

template class Particle<float>;   //why???????????
template class Particle<double>;
