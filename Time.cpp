#include "Time.hpp"

using namespace spic;

double Time::deltaTime {1.0f / 60.0f};
double Time::timeScale {1.0f};

double Time::DeltaTime() {
    return deltaTime;
}

double Time::TimeScale() {
    return timeScale;
}

void Time::TimeScale(double newTimeScale) {
    timeScale = newTimeScale;
}
