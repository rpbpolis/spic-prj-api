#ifndef SPIC_PRJ_API_CD_CONFIG_HPP
#define SPIC_PRJ_API_CD_CONFIG_HPP

#include <string>

namespace spic {

    /**
     * @brief A struct representing the engine configuration
     */
    struct Config {

        /**
         * @brief The title of the application window
         */
        std::string windowTitle;

        /**
         * @brief The desired width of the application window
         */
        int windowWidth;

        /**
         * @brief The desired height of the application window
         */
        int windowHeight;

        /**
         * @brief A boolean flag if the window should be fullscreen
         */
        bool fullscreen;

    };

}

#endif
