#include<headers/particle.h>
#include<headers/vectors.h>

template<class precision>
Particle<precision>::Particle(precision m, Vector2D<precision> p, Vector2D<precision> v) {
    mass = m;
    position = p;
    velocity = v;
}

template<class precision>
precision Particle<precision>::energy() {
    return mass * velocity.norm() * velocity.norm();
}

template<class precision>
precision Particle<precision>::momentum() {
    return mass * velocity.norm();
}

template<class precision>
std::pair<Vector2D<precision>, Vector2D<precision>> collision(Particle<precision> a, Particle<precision> b) {
    Vector2D<precision> va, vb;
    Vector2D<precision> inner_a, inner_b;
    Vector2D<precision> norm_a, norm_b;
    Vector2D<precision> diff_pos_a, diff_pos_b;
    Vector2D<precision> diff_vel_a, diff_vel_b;

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