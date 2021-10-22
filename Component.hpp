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
             */
            bool Active() const { return active; }

            /**
             * @brief flag New active status.
             */
            void Active(bool flag) { active = flag; }

            /**
             * @brief The parent of this component
             * @param parent the current parent
             */
            std::shared_ptr<GameObject> Parent() const { return _parent; }

            /**
             * @brief The parent of this component
             * @param parent the new parent
             */
            void Parent(std::shared_ptr<GameObject> parent) { _parent = parent; }

        private:
            /**
             * @brief Active status.
             */
            bool active;
            std::shared_ptr<GameObject> _parent;
    };

}

#endif // COMPONENT_H_
