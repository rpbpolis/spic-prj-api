#ifndef BEHAVIOURSCRIPT_H_
#define BEHAVIOURSCRIPT_H_

#include "Component.hpp"
#include "Collider.hpp"

namespace spic {

    class BehaviourScript : public Component {
        public:
            /**
             * @brief TODO
             * @spicapi
             */
            virtual void OnStart();

            /**
             * @brief TODO
             * @spicapi
             */
            virtual void OnUpdate();

            /**
             * @brief Sent when another object enters a trigger collider
             *        attached to this object (2D physics only).
             * @spicapi
             */
            virtual void OnTriggerEnter2D(const Collider& collider);

            /**
             * @brief Sent when another object leaves a trigger collider
             *        attached to this object (2D physics only).
             * @spicapi
             */
            virtual void OnTriggerExit2D(const Collider& collider);

            /**
             * @brief Sent each frame where another object is within a trigger
             *        collider attached to this object (2D physics only).
             * @spicapi
             */
            virtual void OnTriggerStay2D(const Collider& collider);
    };

}

#endif // BEHAVIOURSCRIPT_H_
