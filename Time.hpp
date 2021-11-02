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
             * @spicapi
             */
            static double DeltaTime();

            /**
             * @brief The scale at which time passes.
             * @return time scale value
             * @spicapi
             */
            static double TimeScale();

            /**
             * @brief The scale at which time passes.
             * @param newTimeScale The new value for the time scale.
             * @spicapi
             */
            static void TimeScale(double newTimeScale);

        private:
            static double deltaTime;
            static double timeScale;
    };

}

#endif // TIME_H_
