#include<headers/vectors.h>
#include<math.h>

template<class Scalar>
Vector2D<Scalar>::Vector2D() {
    x = 0;
    y = 0;
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
Vector2D<Scalar> Vector2D<Scalar>::operator+(const Vector2D<Scalar>& v) {
    return Vector2D<Scalar>(x + v.x, y + v.y);
}

template<class Scalar>
Vector2D<Scalar> Vector2D<Scalar>::operator-(const Vector2D<Scalar>& v) {
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
Vector2D<Scalar> Vector2D<Scalar>::operator*(Scalar a) {
    return Vector2D<Scalar>(a * x, a * y);
}

template<class Scalar>
Vector2D<Scalar> Vector2D<Scalar>::operator/(Scalar a) {
    return Vector2D<Scalar>(x / a, y / a);
}


template<class Scalar>
Vector2D<Scalar> operator+(Scalar a, const Vector2D<Scalar>& v) {
    return Vector2D<Scalar>(a + v.x, a + v.y);
}

template<class Scalar>
Vector2D<Scalar> operator-(Scalar a, const Vector2D<Scalar>& v) {
    return Vector2D<Scalar>(a - v.x, a - v.y);
}

template<class Scalar>
Vector2D<Scalar> operator*(Scalar a, const Vector2D<Scalar>& v) {
    return Vector2D<Scalar>(a * v.x, a * v.y);
}

template<class Scalar>
Vector2D<Scalar> operator/(Scalar a, const Vector2D<Scalar>& v) {
    return Vector2D<Scalar>(a / v.x, a / v.y);
}

template<class Scalar>
Scalar Vector2D<Scalar>::dot(const Vector2D<Scalar>& v) {
    return x * v.x + y * v.y;
}

template<class Scalar>
Scalar Vector2D<Scalar>::cross(const Vector2D<Scalar>& v){
    return x * v.y - y * v.x;
}

template<class Scalar>
Scalar Vector2D<Scalar>::norm() {
    return sqrt(x * x + y * y);
}

template<class Scalar>
Scalar Vector2D<Scalar>::norm2() {
    return x * x + y * y;
}

template<class Scalar> 
std::ostream& operator<<(std::ostream& stream, const Vector2D<Scalar>& v){
    stream<<v.x<<" "<<v.y;
    return stream;
}


template class Vector2D<float>;
template class Vector2D<double>;

template Vector2D<float> operator+<float>(float a, const Vector2D<float>& v);
template Vector2D<double> operator+<double>(double a, const Vector2D<double>& v);

template Vector2D<float> operator-<float>(float a, const Vector2D<float>& v);
template Vector2D<double> operator-<double>(double a, const Vector2D<double>& v);

template Vector2D<float> operator*<float>(float a, const Vector2D<float>& v);
template Vector2D<double> operator*<double>(double a, const Vector2D<double>& v);

template Vector2D<float> operator/<float>(float a, const Vector2D<float>& v);
template Vector2D<double> operator/<double>(double a, const Vector2D<double>& v);

template std::ostream& operator<< <float>(std::ostream& stream, const Vector2D<float>& v);
template std::ostream& operator<< <double>(std::ostream& stream, const Vector2D<double>& v);