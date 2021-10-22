#ifndef CAMERA_H_
#define CAMERA_H_

#include "GameObject.hpp"
#include "Color.hpp"

namespace spic {

    /**
     * @brief Class representing a point of view towards the game scene.
     */
    class Camera : public GameObject {
        public:
            /**
             * @brief Constructor.
             * @param backgroundColor The background color of the horizon in the camera.
             * @param aspectWidth The aspect width of the camera.
             * @param aspectHeight The aspect width of the camera.
             */
            Camera(const Color& backgroundColor, double aspectWidth, double aspectHeight);

        private:
            Color backgroundColor;
            double aspectWidth;
            double aspectHeight;
    };

}

#endif // CAMERA_H_
