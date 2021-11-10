#ifndef CAMERA_H_
#define CAMERA_H_

#include "GameObject.hpp"
#include "Color.hpp"

#if __has_include("Camera_includes.hpp")
#include "Camera_includes.hpp"
#endif

namespace spic {

    /**
     * @brief Class representing a point of view towards the game scene.
     * @spicapi
     */
    class Camera : public GameObject {
        public:
            /**
             * @brief Constructor.
             * @param name The name of the game object.
             * @param layer The layer of the game object.
             * @param backgroundColor The background color of the horizon in the camera.
             * @param aspectWidth The aspect width of the camera.
             * @param aspectHeight The aspect width of the camera.
             * @sharedapi
             */
            Camera(const std::string& name, int layer, const Color& backgroundColor,
                   double aspectWidth, double aspectHeight);

            /**
             * Get the current background color.
             *
             * @return the current background color.
             * @sharedapi
             */
            const Color& BackgroundColor() const;

            /**
             * Set a new background color.
             *
             * @sharedapi
             */
            void BackgroundColor(const Color& newBackgroundColor);

            /**
             * Get the aspect width of the camera.
             *
             * @return the aspect width of the camera.
             * @sharedapi
             */
            double AspectWidth() const;

            /**
             * Set the new aspect width of the camera.
             *
             * @sharedapi
             */
            void AspectWidth(double newAspectWidth);

            /**
             * Get the aspect height of the camera.
             *
             * @return the aspect height of the camera.
             * @sharedapi
             */
            double AspectHeight() const;

            /**
             * Set the new aspect height of the camera.
             *
             * @sharedapi
             */
            void AspectHeight(double newAspectHeight);

            /**
             * Tell the camera to start rendering the current scene.
             *
             * @sharedapi
             */
            void Render() const;

        private:
            Color backgroundColor;
            double aspectWidth;
            double aspectHeight;
    };

}

#endif // CAMERA_H_
