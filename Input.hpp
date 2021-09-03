#ifndef INPUT_H_
#define INPUT_H_

#include "Point.hpp"
#include <string>

namespace spic {

    /**
     * @brief Some convenient input functions.
     */
    namespace Input {

        /**
         * @brief Enumeration for different mouse buttons.
         */
        enum class MouseButton {
            left,
            middle,
            right
        };

        /**
         * @brief Is any key or mouse button currently held down? (Read Only)
         */
        bool AnyKey();

        /**
         * @brief Returns true the first frame the user hits any key or mouse button. (Read Only)
         */
        bool AnyKeyDown();

        /**
         * @brief The current mouse position in pixel coordinates. (Read Only)
         */
        const Point MousePosition();

        /**
         * @brief Returns the value of the virtual axis identified by axisName.
         */
        double GetAxis();

        /**
         * @brief Returns true while the user holds down the key identified by name.
         */
        bool GetKey(const std::string& name);

        /**
         * @brief Returns true during the frame the user starts pressing down the key identified by name.
         */
        bool GetKeyDown(const std::string& name);

        /**
         * @brief Returns true during the frame the user releases the key identified by name.
         */
        bool GetKeyUp(const std::string& name);

        /**
         * @brief Returns whether the given mouse button is held down.
         */
        bool GetMouseButton(MouseButton which);

        /**
         * @brief Returns true during the frame the user pressed the given mouse button.
         */
        bool GetMouseButtonDown(MouseButton which);

        /**
         * @brief Returns true during the frame the user releases the given mouse button.
         */
        bool GetMouseButtonUp(MouseButton which);

    }

}

#endif // INPUT_H_
