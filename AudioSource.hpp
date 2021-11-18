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
        AudioSource(std::string audioClip, bool playOnAwake, bool loop, double volume);

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

        std::string AudioClip() const;
        void AudioClip(std::string audioClip) ;

        bool PlayOnAwake() const;
        void PlayOnAwake(bool playOnAwake);

        bool Loop() const;
        void Loop(bool loop);

        double Volume() const;
        void Volume(double volume);

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