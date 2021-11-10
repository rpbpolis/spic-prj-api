#ifndef DEBUG_H_
#define DEBUG_H_

#include "Point.hpp"
#include "Color.hpp"
#include <string>

namespace spic {

    /**
     * @brief Some convenient debugging functions.
     * @spicapi
     */
    namespace Debug {

        /**
         * @brief Draws a colored line between specified start and end points.
         * @param start The starting point.
         * @param end The end point.
         * @param color The line color, defaults to white.
         * @spicapi
         */
        void DrawLine(const Point& start, const Point& end, const Color& color = Color::white());

        /**
         * @brief Logs a message to the Console.
         * @param message The message to write.
         * @spicapi
         */
        void Log(const std::string& message, const std::string& file = __builtin_FILE(), int line = __builtin_LINE());

        /**
         * @brief A variant of Debug.Log that logs an error message to the console.
         * @param message The message to write.
         * @spicapi
         */
        void LogError(const std::string& error, const std::string& file = __builtin_FILE(), int line = __builtin_LINE());

        /**
         * @brief A variant of Debug.Log that logs a warning message to the console.
         * @param message The message to write.
         * @spicapi
         */
        void LogWarning(const std::string& warning, const std::string& file = __builtin_FILE(), int line = __builtin_LINE());

    }

}

#endif // DEBUG_H_
