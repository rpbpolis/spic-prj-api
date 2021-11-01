#ifndef AUDIOSOURCE_H_
#define AUDIOSOURCE_H_

#include "Component.hpp"
#include <string>

namespace spic {

    /**
     * @brief Component which can play audio.
     */
    class AudioSource : public Component {
        public:

            AudioSource(const std::string& url, bool playOnAwake, double volume);
            /**
             * @brief Call this method to start playing audio.
             * @param looping Automatically start over when done.
             */
            void Play(bool looping);

            /**
             * @brief Call this method to stop playing audio.
             */
            void Stop();

            /**
             * @brief Call this method to pause audio.
             */
            void Pause();

            /**
             * @brief Call this method to resume audio if paused.
             */
            void Resume();

            bool ShouldLoop();

            void SetPlayOnAwake(bool flag);

            bool GetPlayOnAwake();

            void SetVolume(double newVolume);

            double GetVolume();

            std::string GetUrl();

        private:
            #include "AudioSource_private.hpp"
    };
}

#endif // AUDIOSOURCE_H_
