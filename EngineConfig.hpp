#ifndef ENGINECONFIG_H_
#define ENGINECONFIG_H_

#include "WindowConfig.hpp"

namespace spic {

    /**
     * @brief A struct representing the engine configuration.
     * @sharedapi
     */
    struct EngineConfig {

        /**
         * @brief The sub config for the window.
         */
        WindowConfig window;

    };

}

#endif // ENGINECONFIG_H_
