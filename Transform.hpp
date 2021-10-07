#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "Point.hpp"

namespace spic {
    /**
     * @brief Instances of this class represent specific 2D transformations.
     */
    struct Transform {
        Point position; // Translation (shift).
        double rotation; // Rotation, in radians.
        double scale; // multiplication factor
    };
}

#endif // TRANSFORM_H_
