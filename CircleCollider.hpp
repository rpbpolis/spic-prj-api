#ifndef CIRCLECOLLIDER_H_
#define CIRCLECOLLIDER_H_

#include "Collider.hpp"

namespace spic {

    /**
     * @brief A collider which represents a circular collision area.
     * @spicapi
     */
    class CircleCollider : public Collider {
        public:
            /**
             * @brief Constructor.
             * @deprecated Do not use
             * @sharedapi
             */
            CircleCollider();

            /**
             * @brief Constructor.
             * @param radius The radius for the circle collider.
             * @param trigger Is the collider a trigger.
             * @sharedapi
             */
            CircleCollider(double radius, bool trigger);

            /**
             * @brief Constructor.
             * @param radius The radius for the circle collider.
             * @param trigger Is the collider a trigger.
             * @param offsetX The X-axis offset of the collider from the origin point.
             * @param offsetY The Y-axis offset of the collider from the origin point.
             */
            CircleCollider(double radius, bool trigger, double offsetX, double offsetY);

            /**
             * @brief Get the collider's radius
             * @return The radius
             * @spicapi
             */
            double Radius() const { return radius; }

            /**
             * @brief Set the collider's radius
             * @param newRadius The desired radius
             * @spicapi
             */
            void Radius(double newRadius) { radius = newRadius; }

        private:
            double radius;
    };

}

#endif // CIRCLECOLLIDER_H_
