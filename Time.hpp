#ifndef TIME_H_
#define TIME_H_

namespace spic {

    /**
     * @brief Class representing game time.
     */
    class Time {
        public:
            /**
             * @brief The interval in seconds from the last frame to the current one (Read Only)
             */
            static float GetDeltaTime();

            /**
            * @brief The current amount of frames that are ran every second
            */
            static float GetFps();

            /**
             * @brief The scale at which time passes.
             * @return time scale value
             */
            static double GetTimeScale();

            /**
             * @brief The scale at which time passes.
             * @param The new value for the time scale.
             */
            static void SetTimeScale(double newTimeScale);

        private:
        #include "Time_private.hpp"
    };

}

#endif // TIME_H_
