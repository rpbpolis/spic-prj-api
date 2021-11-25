#include "Color.hpp"

using namespace spic;

Color Color::_white   {1.0, 1.0, 1.0, 1.0};
Color Color::_red     {1.0, 0.0, 0.0, 1.0};
Color Color::_green   {0.0, 1.0, 0.0, 1.0};
Color Color::_blue    {0.0, 0.0, 1.0, 1.0};
Color Color::_cyan    {0.0, 1.0, 1.0, 1.0};
Color Color::_magenta {1.0, 0.0, 1.0, 1.0};
Color Color::_yellow  {1.0, 1.0, 0.0, 1.0};
Color Color::_black   {0.0, 0.0, 0.0, 1.0};
// ... more standard colors here

Color::Color(double red, double green, double blue, double alpha)
    : r {red}, g {green}, b {blue}, a {alpha} {}

double Color::R() {
    return r;
}

void Color::R(double newR) {
    r = newR;
}

double Color::G() {
    return g;
}

void Color::G(double newG) {
    g = newG;
}

double Color::B() {
    return b;
}

void Color::B(double newB) {
    b = newB;
}

double Color::A() {
    return a;
}

void Color::A(double newA) {
    a = newA;
}
