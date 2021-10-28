#ifndef CAMERA_H_
#define CAMERA_H_

#include "GameObject.hpp"
#include "Color.hpp"

namespace spic {

    /**
     * @brief Class representing a point of view towards the game scene.
     */
    class Camera : public GameObject {
        private:
        #include "Camera_private.hpp"
    };

}

#endif // CAMERA_H_
