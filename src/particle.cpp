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

template<class Scalar>
std::pair<Vector2D<Scalar>, Vector2D<Scalar>> collision(Particle<Scalar> &a, Particle<Scalar> &b) {
    Vector2D<Scalar> va, vb;
    Scalar inner_a, inner_b;
    Scalar norm_a, norm_b;
    Vector2D<Scalar> diff_pos_a, diff_pos_b;
    Vector2D<Scalar> diff_vel_a, diff_vel_b;

    diff_pos_a = a.position - b.position;
    diff_pos_b = b.position - a.position;

    diff_vel_a = a.velocity - b.velocity;
    diff_vel_b = b.velocity - a.velocity;

    inner_a = diff_vel_a.dot(diff_pos_a);
    inner_b = diff_vel_b.dot(diff_pos_b);

    norm_a = diff_pos_a.norm2();
    norm_b = diff_pos_b.norm2();

    va = a.velocity - ((2 * b.mass) / (a.mass + b.mass) * (inner_a / norm_a)) * diff_pos_a;
    vb = b.velocity - ((2 * a.mass) / (b.mass + a.mass) * (inner_b / norm_b)) * diff_pos_b;

    a.velocity = va;
    b.velocity = vb;

    return {va, vb};
}


template class Particle<float>;   //why???????????
template class Particle<double>;

template std::pair<Vector2D<float>, Vector2D<float>> collision<float>(Particle<float> &a, Particle<float> &b);
template std::pair<Vector2D<double>, Vector2D<double>> collision<double>(Particle<double> &a, Particle<double> &b);
