#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "Point.hpp"

namespace spic {

    /**
     * @brief Instances of this class represent specific 2D transformations.
     */
    class Transform {
        public:
            /**
             * @brief Constructor.
             * @param pos Translation (shift).
             * @param rot Ratotion, in radians.
             * @param scale Scale (multiplication factor).
             */
            Transform(const Point& pos, double rot, double scale);

        private:
            Point position;
            double rotation;
            double scale;
    };

}

#endif // TRANSFORM_H_
