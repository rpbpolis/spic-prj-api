#ifndef TIME_H_
#define TIME_H_

namespace spic {

    namespace Time {
        long PreviousTime;
        float DeltaTime;
        double TimeScale;

        float GetFps();
        void CalculateDeltaTime();
    }

}

#endif // TIME_H_
