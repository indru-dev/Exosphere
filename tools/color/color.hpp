#pragma once


namespace ege {

struct Color {
    float r, g, b, a;


    constexpr Color(float red = 0, float green = 0, float blue = 0, float alpha = 1.0) : r(red), g(green), b(blue), a(alpha) {};
};

static constexpr Color RED(1, 0, 0);
static constexpr Color GREEN(0, 1, 0);
static constexpr Color BLUE(0, 0, 1);
static constexpr Color WHITE(1, 1, 1);
static constexpr Color BLACK(0, 0, 0);
static constexpr Color CLEAR(0, 0, 0, 0);

}
