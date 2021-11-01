#ifndef COMPONENT_H_
#define COMPONENT_H_

namespace spic {

    /**
     * @brief Base class for all components.
     */
    class Component {
        public:

            Component();
            /**
             * @brief Getter for active status.
             * @return true if active, false otherwise.
             */
            bool Active() const { return active; }

            /**
             * @brief flag New active status.
             */
            void Active(bool flag) { active = flag; }

        private:
        #include "Component_private.hpp"
    };

}

#endif // COMPONENT_H_
