#ifndef COLLIDER2D_H_
#define COLLIDER2D_H_

#include "Component.hpp"
#include "Vector2.hpp"

namespace spic {

    /**
     * @brief The base class for all colliders.
     */
    class Collider : public Component {
    public:
        Vector2 offset;
    private:
    #include "Collider_private.hpp"
    };

}

#endif // COLLIDER2D_H_
