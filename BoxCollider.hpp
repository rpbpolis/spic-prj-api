#ifndef BOXCOLLIDER_H_
#define BOXCOLLIDER_H_

#include "Collider.hpp"

namespace spic {

    /**
     * @brief A collider which represents a rectangular collision area.
     */
    class BoxCollider : public Collider {
        public:

            BoxCollider(double width, double height, std::vector<int> collideLayers, Vector2 offset) : Collider(collideLayers, offset);
            /**
             * @brief The collider's width
             * @return The current width
             */
            double GetWidth();

            /**
             * @brief The collider's width
             * @param newWidth The desired width
             */
            void SetWidth(double newWidth);

            /**
             * @brief The collider's height
             * @return The current height
             */
            double GetHeight();

            /**
             * @brief The collider's height
             * @param newHeight The desired height
             */
            void SetHeight(double newHeight);

        private:
        #include "BoxCollider_private.hpp"
    };
}

#endif // BOXCOLLIDER_H_
