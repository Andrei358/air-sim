#include<headers/wall.h>

template<class Scalar>
Wall<Scalar>::Wall(Vector2D<Scalar> part1, Vector2D<Scalar> part2, Scalar t) {
    p1 = part1;
    p2 = part2;
    thickness = t;
}

template<class Scalar>
std::pair<Vector2D<Scalar>, Vector2D<Scalar>> Wall<Scalar>::getCoords(){
    return {p1, p2};
}


template class Wall<float>;   //why???????????
template class Wall<double>;