#ifndef RIGIDBODY_H_
#define RIGIDBODY_H_

#include "Component.hpp"
#include "Point.hpp"

namespace spic {

    /**
     * @brief Enumeration for different rigid body types
     * @spicapi
     */
    enum class BodyType {
        staticBody,
        kinematicBody,
        dynamicBody
    };

    /**
     * @brief A component representing a rigid body.
     * @spicapi
     */
    class RigidBody : public Component {
        public:
            /**
             * @brief Constructor
             * @param mass The mass of the rigid body
             * @param gravityScale The scale of the gravity of the rigid body
             * @param bodyType The type of the rigid body
             * @sharedapi
             */
            RigidBody(double mass, double gravityScale, const BodyType& bodyType);

            /**
             * @brief Apply force to this rigid body.
             * @param forceDirection A point, used as a vector to indicate direction
             *        and magnitude of the force to be applied.
             * @spicapi
             */
            void AddForce(const Point& forceDirection);

            /**
             * @brief The type of this body.
             * @return The current value.
             * @sharedapi
             */
            BodyType Type() const;

             /**
              * @brief The type of this body.
              * @param newBodyType The desired value.
              * @sharedapi
              */
            void Type(BodyType newBodyType);

            /**
             * @brief The mass of this body.
             * @return The current value.
             * @sharedapi
             */
            double Mass() const;

            /**
             * @brief The mass of this body.
             * @param newMass The desired value.
             * @sharedapi
             */
            void Mass(double newMass);

            /**
             * @brief The gravity scale of this body.
             * @return The current value.
             * @sharedapi
             */
            double GravityScale() const;

            /**
             * @brief The gravity scale of this body.
             * @param newMass The desired value.
             * @sharedapi
             */
            void GravityScale(double newGravityScale);

        private:
            double mass;
            double gravityScale;
            BodyType bodyType;
    };

}

#endif // RIGIDBODY_H_
