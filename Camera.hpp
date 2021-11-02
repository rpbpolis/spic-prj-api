#ifndef CAMERA_H_
#define CAMERA_H_

#include "GameObject.hpp"
#include "Color.hpp"

namespace spic {

    /**
     * @brief Class representing a point of view towards the game scene.
     * @spicapi
     */
    class Camera : public GameObject {
        private:
            Color backgroundColor;
            double aspectWidth;
            double aspectHeight;
    };

}

#endif // CAMERA_H_
