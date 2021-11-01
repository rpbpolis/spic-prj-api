#ifndef COLLIDER2D_H_
#define COLLIDER2D_H_

#include <vector>
#include "Component.hpp"
#include "Vector2.hpp"

namespace spic {

    /**
     * @brief The base class for all colliders.
     */
    class Collider : public Component {
    public:
        Collider(std::vector<int> collideLayers, Vector2 offset);
        Vector2 offset;
    private:
    #include "Collider_private.hpp"
    };

}

#endif // COLLIDER2D_H_
