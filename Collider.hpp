#ifndef COLLIDER2D_H_
#define COLLIDER2D_H_

#include "Component.hpp"

#if __has_include("Collider_includes.hpp")
#include "Collider_includes.hpp"
#endif

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
         */
        bool IsTrigger() const;

        /**
         * @brief Set if the collider is a trigger
         * @param newIsTrigger A new value to define if the collider is a trigger
         */
        void IsTrigger(bool newIsTrigger);

    private:
#if __has_include("Collider_private.hpp")
#include "Collider_private.hpp"
#endif
    };

}

#endif // COLLIDER2D_H_
