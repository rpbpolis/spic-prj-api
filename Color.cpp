#include "Color.hpp"

using namespace spic;

Color Color::_white {1.0, 1.0, 1.0, 1.0};
// ... more standard colors here

Color::Color(double r, double g, double b, double a) : red {r}, green {g}, blue {b}, alpha {a} {}
