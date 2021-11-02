#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <memory>

namespace spic {

    class GameObject;

    /**
     * @brief Base class for all components.
     */
    class Component {
        public:
            /**
             * @brief Getter for active status.
             * @return true if active, false otherwise.
             * @spicapi
             */
            bool Active() const { return active; }

            /**
             * @brief flag New active status.
             * @spicapi
             */
            void Active(bool flag) { active = flag; }

            /**
             * @brief The parent of this component
             * @param parent the current parent
             */
            std::weak_ptr<spic::GameObject> GameObject() const { return _gameObject; }

            /**
             * @brief The parent of this component
             * @param parent the new parent
             */
            void GameObject(std::weak_ptr<spic::GameObject> gameObject) { _gameObject = gameObject; }

        private:
            /**
             * @brief Active status.
             */
            bool active;
            std::weak_ptr<spic::GameObject> _gameObject;
    };

}

#endif // COMPONENT_H_
