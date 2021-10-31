#ifndef CIRCLECOLLIDER_H_
#define CIRCLECOLLIDER_H_

#include "Collider.hpp"

namespace spic {

    /**
     * @brief A collider which represents a circular collision area.
     */
    class CircleCollider : public Collider {
        public:
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
