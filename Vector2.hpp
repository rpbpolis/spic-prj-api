#ifndef VECTOR2_H_
#define VECTOR2_H_

namespace spic {

    /**
     * @brief Struct representing both a 2D point and a 2D vector.
     */
    struct Vector2 {
        float x;
        float y;

        static const Vector2& Up();
        static const Vector2& Right();
        static const Vector2& Down();
        static const Vector2& Left();
    };
}

#endif // VECTOR2_H_
