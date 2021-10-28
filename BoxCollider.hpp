#ifndef BOXCOLLIDER_H_
#define BOXCOLLIDER_H_

#include "Collider.hpp"

namespace spic {

    /**
     * @brief A collider which represents a rectangular collision area.
     */
    class BoxCollider : public Collider {
        public:
            /**
             * @brief The collider's width
             * @return The current width
             */
            double Width() const { return width; }

            /**
             * @brief The collider's width
             * @param newWidth The desired width
             */
            void Width(double newWidth) { width = newWidth; }

            /**
             * @brief The collider's height
             * @return The current height
             */
            double Height() const { return height; }

            /**
             * @brief The collider's height
             * @param newHeight The desired height
             */
            void Height(double newHeight) { height = newHeight; }

        private:
        #include "BoxCollider_private.hpp"
    };
}

#endif // BOXCOLLIDER_H_
