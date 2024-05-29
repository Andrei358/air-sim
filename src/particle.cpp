#include<headers/particle.h>

template<class Scalar>
Particle<Scalar>::Particle(Scalar m, Vector2D<Scalar> p, Vector2D<Scalar> v) {
    mass = m;
    position = p;
    velocity = v;
}

template<class Scalar>
Scalar Particle<Scalar>::energy() {
    return mass * velocity.norm() * velocity.norm();
}

template<class Scalar>
Scalar Particle<Scalar>::momentum() {
    return mass * velocity.norm();
}

template<class Scalar>
std::pair<Vector2D<Scalar>, Vector2D<Scalar>> collision(Particle<Scalar> a, Particle<Scalar> b) {
    Vector2D<Scalar> va, vb;
    Vector2D<Scalar> inner_a, inner_b;
    Vector2D<Scalar> norm_a, norm_b;
    Vector2D<Scalar> diff_pos_a, diff_pos_b;
    Vector2D<Scalar> diff_vel_a, diff_vel_b;

    diff_pos_a = a.position - b.position;
    diff_pos_b = b.position - a.position;

    diff_vel_a = a.velocity - b.velocity;
    diff_vel_b = b.velocity - a.velocity;

    inner_a = diff_vel_a.dot(diff_pos_a);
    inner_b = diff_vel_b.dot(diff_pos_b);

    norm_a = diff_pos_a.norm();
    norm_b = diff_pos_b.norm();

    va = a.velocity - ((2 * b.mass) / (a.mass + b.mass) * (inner_a / norm_a)) * diff_pos_a;
    vb = b.velocity - ((2 * a.mass) / (b.mass + a.mass) * (inner_b / norm_b)) * diff_pos_b;

    return {va, vb};
}