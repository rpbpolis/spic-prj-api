#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "Vector2.hpp"

namespace spic {
    /**
     * @brief Instances of this class represent specific 2D transformations.
     */
    class Transform {
    public:
        Transform(const Vector2& pos, double rot, double scale);
        void LookAt(const Vector2& pos);
    private:
    #include "Transform_private.hpp"
    };
}

#endif // TRANSFORM_H_