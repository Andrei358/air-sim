#ifndef INCLUDE_HEADERS_VECTORS_H
#define INCLUDE_HEADERS_VECTORS_H

template<class Scalar> class Vector2D;
template<class Scalar> Vector2D<Scalar> operator+(Scalar a, const Vector2D<Scalar>& v);

template<class Scalar>
class Vector2D {
    public:
        Vector2D();
        Vector2D(Scalar a, Scalar b);

        void setX(Scalar a);
        void setY(Scalar b);

        Scalar getX();
        Scalar getY();

        Scalar dot(const Vector2D<Scalar>& v);
        // Vector2D cross(Vector2D v);
        Scalar norm();
        
        Vector2D<Scalar> operator+(const Vector2D<Scalar>& v);
        Vector2D<Scalar> operator-(const Vector2D<Scalar>& v);

        Vector2D<Scalar> operator+(Scalar a);
        Vector2D<Scalar> operator-(Scalar a);

        friend Vector2D<Scalar> operator+<>(Scalar a, const Vector2D<Scalar>& v);        
        
    private:
        Scalar x, y;  

};

#endif 