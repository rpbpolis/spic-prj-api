#ifndef WINDOWCONFIG_H_
#define WINDOWCONFIG_H_

#include <string>

namespace spic {

    /**
     * @brief A struct representing the window configuration
     * @sharedapi
     */
    struct WindowConfig {

        /**
         * @brief The title of the application window
         */
        std::string title;

        /**
         * @brief The desired width of the application window
         */
        int width;

        /**
         * @brief The desired height of the application window
         */
        int height;

        /**
         * @brief A boolean flag if the window should be fullscreen
         */
        bool fullscreen;

    };

}

#endif // WINDOWCONFIG_H_
