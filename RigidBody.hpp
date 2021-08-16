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
             * @brief Apply force to this rigid body.
             */
            void AddForce(const Point& forceDirection);

        private:
            double mass;
            double gravityScale;
            BodyType bodyType;
    };

}

#endif // RIGIDBODY_H_
