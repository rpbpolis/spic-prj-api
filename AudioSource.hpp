#ifndef AUDIOSOURCE_H_
#define AUDIOSOURCE_H_

#include "Component.hpp"
#include <string>

namespace spic {

    /**
     * @brief Component which can play audio.
     * @spicapi
     */
    class AudioSource : public Component {
        public:
            /**
             * @brief Constructor.
             * @param audioClip The source tho the audio clip.
             * @param playOnAwake Whether the audio should start playing automatically.
             * @param looping Automatically start over when done.
             * @param volume The volume level of the AudioSource.
             * @sharedapi
             */
            AudioSource(const std::string& audioClip, bool playOnAwake, bool looping, double volume, bool music);

            /**
             * @brief Call this method to start playing audio.
             * @param looping Automatically start over when done.
             * @spicapi
             */
            void Play(bool looping);

            /**
             * @brief Call this method to stop playing audio.
             * @spicapi
             */
            void Stop();

            /**
             * @brief Get the volume of the AudioSource
             * @return The volume of the AudioSource, which is a double between 0.0 and 1.0 inclusively
             * @sharedapi
             */
            double Volume() const;

            /**
             * @brief Set volume of the AudioSource
             * @param newVolume The new volume level of the AudioSource
             * @sharedapi
             */
            void Volume(double newVolume);

            /**
             * @brief Get the audioClip of the AudioSource
             * @return The audioClip of the AudioSource, which is a string path of the audio
             * @sharedapi
             */
            std::string AudioClip() const;

            /**
             * @brief Get the loop bool of the AudioSource
             * @return The loop check of the AudioSource, which is a bool that shows if the audio should be looped
             * @sharedapi
             */
            bool Loop() const;

            /**
             * @brief Get the music bool of the AudioSource
             * @return The music check of the AudioSource, which is a bool that shows if the audio should be played as music or a sound effect
             * @sharedapi
             */
            bool Music() const;

        private:
            /**
             * @brief Path to a locally stored audio file.
             * @spicapi
             */
            std::string audioClip;

            /**
             * @brief When true, the component will start playing automatically.
             * @spicapi
             */
            bool playOnAwake;

            /**
             * @brief When true, the audio will play indefinitely.
             * @spicapi
             */
            bool loop;

            /**
             * @brief Audio volume, between 0.0 and 1.0.
             * @spicapi
             */
            double volume;

            /**
             * @brief When true, music will be played, otherwise a sound effect will be played
             * @spicapi
             */
            bool music;
    };

}

#endif // AUDIOSOURCE_H_
