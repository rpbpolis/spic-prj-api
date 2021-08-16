#ifndef DEBUG_H_
#define DEBUG_H_

#include "Point.hpp"
#include "Color.hpp"
#include <string>

namespace spic {

    /**
     * @brief Some convenient debugging functions.
     */
    namespace Debug {

        /**
         * @brief Draws a colored line between specified start and end points.
         */
        void DrawLine(const Point& start, const Point& end, const Color& color = Color::white());

        /**
         * @brief Logs a message to the Console.
         */
        void Log(const std::string& message);

        /**
         * @brief A variant of Debug.Log that logs an error message to the console.
         */
        void LogError(const std::string& error);

        /**
         * @brief A variant of Debug.Log that logs a warning message to the console.
         */
        void LogWarning(const std::string& warning);

    }

}

#endif // DEBUG_H_
