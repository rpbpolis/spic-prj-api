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
             */
            double Radius() const;

            /**
             * @brief Set the collider's radius
             * @param newRadius The desired radius
             */
            void Radius(double newRadius);

        private:
        #include "CircleCollider_private.hpp"
    };

}

#endif // CIRCLECOLLIDER_H_
