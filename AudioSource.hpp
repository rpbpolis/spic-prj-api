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

        private:
            #include "AudioSource_private.hpp"
    };
}

#endif // AUDIOSOURCE_H_
