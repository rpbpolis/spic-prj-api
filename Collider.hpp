#ifndef COLLIDER2D_H_
#define COLLIDER2D_H_

#include "Component.hpp"

namespace spic {

    /**
     * @brief The base class for all colliders.
     * @spicapi
     */
    class Collider : public Component {
    public:

        /**
         * @brief Get if the collider is a trigger
         * @return True if the collider is a trigger, false if not
         * @sharedapi
         */
        bool IsTrigger() const;

        /**
         * @brief Set if the collider is a trigger
         * @param newIsTrigger A new value to define if the collider is a trigger
         * @sharedapi
         */
        void IsTrigger(bool newIsTrigger);

    private:
        bool isTrigger;
    };

}

#endif // COLLIDER2D_H_
