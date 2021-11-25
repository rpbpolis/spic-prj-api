#ifndef BOXCOLLIDER_H_
#define BOXCOLLIDER_H_

#include "Collider.hpp"

namespace spic {

    /**
     * @brief A collider which represents a rectangular collision area.
     * @spicapi
     */
    class BoxCollider : public Collider {
        public:
            /**
             * @brief Constructor.
             * @deprecated Do not use
             * @sharedapi
             */
            BoxCollider();

            /**
             * @brief Constructor.
             * @param width The width for the box collider.
             * @param height The height for the box collider.
             * @param trigger Is the collider a trigger.
             * @sharedapi
             */
            BoxCollider(double width, double height, bool trigger);

            /**
             * @brief Constructor.
             * @param width The width for the box collider.
             * @param height The height for the box collider.
             * @param trigger Is the collider a trigger.
             * @param offsetX The X-axis offset of the collider from the origin point.
             * @param offsetY The Y-axis offset of the collider from the origin point.
             */
            BoxCollider(double width, double height, bool trigger, double offsetX, double offsetY);

            /**
             * @brief Constructor.
             * @param width The width for the box collider.
             * @param height The height for the box collider.
             * @param trigger Is the collider a trigger.
             * @param offsetX The X-axis offset of the collider from the origin point.
             * @param offsetY The Y-axis offset of the collider from the origin point.
             * @param givesFeedback A value to define if the collider should always trigger
             */
            BoxCollider(double width, double height, bool trigger, double offsetX, double offsetY, bool givesFeedback);

            /**
             * @brief The collider's width
             * @return The current width
             * @spicapi
             */
            double Width() const { return width; }

            /**
             * @brief The collider's width
             * @param newWidth The desired width
             * @spicapi
             */
            void Width(double newWidth) { width = newWidth; }

            /**
             * @brief The collider's height
             * @return The current height
             * @spicapi
             */
            double Height() const { return height; }

            /**
             * @brief The collider's height
             * @param newHeight The desired height
             * @spicapi
             */
            void Height(double newHeight) { height = newHeight; }

        private:
            double width;
            double height;
    };

}

#endif // BOXCOLLIDER_H_
