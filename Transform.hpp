#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "Point.hpp"

namespace spic {
    /**
     * @brief Instances of this class represent specific 2D transformations.
     * @spicapi
     */
    struct Transform {
        Point position{0, 0}; // Translation (shift)
        double rotation{0}; // Rotation, in degrees
        double scale{1.0}; // Multiplication factor
    };
}

#endif // TRANSFORM_H_
