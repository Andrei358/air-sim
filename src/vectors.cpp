#include<headers/vectors.h>

template<class Scalar>
Vector2D<Scalar>::Vector2D() {
    x = 0.0;
    y = 0.0;
}

template<class Scalar>
Vector2D<Scalar>::Vector2D(Scalar a, Scalar b) {
    x = a;
    y = b;
}

template<class Scalar>
void Vector2D<Scalar>::setX(Scalar a) {
    x = a;
}

template<class Scalar>
void Vector2D<Scalar>::setY(Scalar b) {
    y = b;
}

template<class Scalar>
Scalar Vector2D<Scalar>::getX() {
    return x;
}

template<class Scalar>
Scalar Vector2D<Scalar>::getY() {
    return y;
}

template<class Scalar>
Vector2D<Scalar> Vector2D<Scalar>::operator+(Vector2D v) {
    return Vector2D<Scalar>(x + v.x, y + v.y);
}

template<class Scalar>
Vector2D<Scalar> Vector2D<Scalar>::operator-(Vector2D v) {
    return Vector2D<Scalar>(x - v.x, y - v.y);
}

template<class Scalar>
Vector2D<Scalar> Vector2D<Scalar>::operator+(Scalar a) {
    return Vector2D<Scalar>(a + x, a + y);
}

template<class Scalar>
Vector2D<Scalar> Vector2D<Scalar>::operator-(Scalar a) {
    return Vector2D<Scalar>(x - a, y - a);
}

template<class Scalar>
Vector2D<Scalar> operator+(Scalar a, Vector2D<Scalar> v) {
    return Vector2D<Scalar>(a + v.x, a + v.y);
}

template<class Scalar>
Scalar Vector2D<Scalar>::dot(Vector2D v) {
    return x * v.x + y * v.y;
}

/*
template<class Scalar>
Vector2D Vector2D::cross(Vector2D v);
*/

template<class Scalar>
Scalar Vector2D<Scalar>::norm() {
    return x * x + y * y;
}