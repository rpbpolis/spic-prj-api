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

Color::Color(const double red, const double green, const double blue, const double alpha)
        : r{red}, g{green}, b{blue}, a{alpha} {}

Color::Color(const double red, const double green, const double blue)
        : Color(red, green, blue, 1.0)
