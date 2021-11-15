#ifndef BEHAVIOURSCRIPT_H_
#define BEHAVIOURSCRIPT_H_

#include "Component.hpp"
#include <memory>
#include "GameObject.hpp"

namespace spic {

    class BehaviourScript : public Component {
        public:
            /**
             * @brief Called only once, often used to initialize values used by the script.
             *        Only called if gameobject is active
             * @spicapi
             */
            virtual void OnStart();

            /**
             * @brief called every tick
             *        Only called if gameobject is active
             * @spicapi
             */
            virtual void OnUpdate();

            /**
             * @brief Sent when another object enters a trigger collider
             *        attached to this object (2D physics only).
             * @spicapi
             */
            virtual void OnTriggerEnter2D(std::shared_ptr<spic::GameObject> gameObject);

            /**
             * @brief Sent when another object leaves a trigger collider
             *        attached to this object (2D physics only).
             * @spicapi
             */
            virtual void OnTriggerExit2D(std::shared_ptr<spic::GameObject> gameObject);

            /**
             * @brief Sent each frame where another object is within a trigger
             *        collider attached to this object (2D physics only).
             * @spicapi
             */
            virtual void OnTriggerStay2D(std::shared_ptr<spic::GameObject> gameObject);

            /**
             * @brief Whether the script has been started.
             * @param started desired value
             * @sharedapi
             */
            void Started(bool started);

            /**
             * @brief Whether the script has been started.
             * @return current value
             * @sharedapi
             */
            bool Started() const;

        private:
            bool started;
    };

}

#endif // BEHAVIOURSCRIPT_H_
