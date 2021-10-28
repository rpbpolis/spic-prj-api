#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "Vector2.hpp"

namespace spic {
    /**
     * @brief Instances of this class represent specific 2D transformations.
     */
    struct Transform {
        Vector2 position; // Translation (shift)
        double rotation; // Rotation, in radians
        double scale; // Multiplication factor
    };
}

#endif // TRANSFORM_H_