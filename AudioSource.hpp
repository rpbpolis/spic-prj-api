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
             * @brief Constructor.
             * @param audioClip The source tho the audio clip.
             * @param playOnAwake Whether the audio should start playing automatically.
             */
            AudioSource(const std::string& audioClip, const bool playOnAwake);

            /**
             * @brief Call this method to start playing audio.
             * @param looping Automatically start over when done.
             */
            void Play(bool looping);

            /**
             * @brief Call this method to stop playing audio.
             */
            void Stop();

        private:
            /**
             * @brief Path to a locally stored audio file.
             */
            std::string audioClip;

            /**
             * @brief When true, the component will start playing automatically.
             */
            bool playOnAwake;

            /**
             * @brief When true, the audio will play indefinitely.
             */
            bool loop;

            /**
             * @brief Audio volume, between 0.0 and 1.0.
             */
            double volume;
    };

}

#endif // AUDIOSOURCE_H_
