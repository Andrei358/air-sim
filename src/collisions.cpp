#include<headers/vectors.h>
#include<headers/wall.h>
#include<headers/particle.h>
#include<utility>

template<class Scalar>
Vector2D<Scalar> collision(Particle<Scalar> &p, Wall<Scalar> &w) {
    Vector2D<Scalar> diff = w.p1 - p.position;
    Vector2D<Scalar> n = (w.p2 - w.p1) / (w.p2 - w.p1).norm();
    Vector2D<Scalar> normal = diff - (diff.dot(n)) * n;

    Vector2D<Scalar> new_vel = p.velocity - (Scalar)1.0 * normal;

    p.velocity = new_vel;

    return new_vel;
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

template std::pair<Vector2D<float>, Vector2D<float>> collision<float>(Particle<float> &a, Particle<float> &b);
template std::pair<Vector2D<double>, Vector2D<double>> collision<double>(Particle<double> &a, Particle<double> &b);

template Vector2D<float> collision<float>(Particle<float> &p, Wall<float> &w);
template Vector2D<double> collision<double>(Particle<double> &p, Wall<double> &w);
