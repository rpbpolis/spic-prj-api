#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "Point.hpp"

namespace spic {

    /**
     * @brief Instances of this class represent specific 2D transformations.
     */
    class Transform {
        private:
            Point position;
            double rotation;
            double scale;
    };

}

#endif // TRANSFORM_H_
