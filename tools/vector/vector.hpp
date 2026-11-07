#pragma once

namespace ege {

template  <typename T>
struct Vector2 {

    T x;
    T y;

    Vector2(T X = 0, T Y = 0) : x(X), y(Y) {};

};

// Basic Types
using Vector2u = Vector2<unsigned int>;
using Vector2f = Vector2<float>;
using Vector2i = Vector2<int>;

}