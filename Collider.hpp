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
        explicit Collider(bool trigger);

        explicit Collider(bool trigger, double offsetX, double offsetY);

        explicit Collider(bool trigger, bool givesFeedback, double offsetX, double offsetY);
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

        /**
         * @brief Get if the collider should always trigger
         * @return True if the collider should always trigger
         */
        bool GivesFeedback() const;

        /**
         * @brief Set if the collider should always trigger
         * @param newGivesFeedback A new value to define if the collider should always trigger
         */
        void GivesFeedback(bool newGivesFeedback);

        /**
         * Get the X-axis offset of the collider from the origin point
         * @return the X-axis offset of the collider from the origin point
         */
        double OffsetX() const;

        /**
         * Get the Y-axis offset of the collider from the origin point
         * @return the Y-axis offset of the collider from the origin point
         */
        double OffsetY() const;


    private:
        bool isTrigger;
        double offsetX;
        double offsetY;
        bool givesFeedback;
    };

}

#endif // COLLIDER2D_H_
