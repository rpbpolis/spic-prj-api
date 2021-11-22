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
             * @param forceDirection A point, used as a vector to indicate direction
             *        and magnitude of the force to be applied.
             * @spicapi
             */
            void AddForce(const Point& forceDirection);

            void Mass(double newMass);
            [[nodiscard]] double Mass() const;

            void GravityScale(double newGravityScale);
            [[nodiscard]] double GravityScale() const;

            void BodyTypeRB(spic::BodyType bodyType);
            [[nodiscard]] spic::BodyType BodyTypeRB() const;

            RigidBody(double mass, double gravityScale, spic::BodyType bodyType);
        private:
            double mass;
            double gravityScale;
            BodyType bodyType;
    };

}

#endif // RIGIDBODY_H_
