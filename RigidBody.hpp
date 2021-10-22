#ifndef RIGIDBODY_H_
#define RIGIDBODY_H_

#include "Component.hpp"
#include "Point.hpp"

namespace spic {

    /**
     * @brief Enumeration for different rigid body types
     */
    enum class BodyType {
        staticBody,
        kinematicBody,
        dynamicBody
    };

    /**
     * @brief A component representing a rigid body.
     */
    class RigidBody : public Component {
        public:
            /**
             * @brief Constructor
             * @param mass The mass of the rigid body
             * @param gravityScale The scale of the gravity of the rigid body
             * @param bodyType The type of the rigid body
             */
            RigidBody(double mass, double gravityScale, const BodyType& bodyType);
            
            /**
             * @brief Apply force to this rigid body.
             * @param forceDirection A point, used as a vector to indicate direction
             *        and magnitude of the force to be applied.
             */
            void AddForce(const Point& forceDirection);

        private:
            double mass;
            double gravityScale;
            BodyType bodyType;
    };

}

#endif // RIGIDBODY_H_
