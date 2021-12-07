#ifndef ANIMATOR_H_
#define ANIMATOR_H_

#include "Component.hpp"
#include "Sprite.hpp"
#include <vector>
#include <memory>
#include <map>
#include <string>

namespace spic {

    /**
     * @brief A component which can play animated sequences of sprites.
     * @spicapi
     */
    class Animator : public Component {
        public:
            /**
             * @brief Constructor.
             * @param fps The amount of frames the animator will cycle though per second.
             * @param sprites An list of sprites to loop through.
             * @sharedapi
             */
            Animator(int fps, const std::vector<std::shared_ptr<Sprite>>& sprites);

            /**
             * @brief Constructor.
             * @param fps The amount of frames the animator will cycle though per second.
             * @param sprites An list of sprites to loop through.
             * @sharedapi
             */
            Animator(int fps, const std::map<std::string, std::vector<std::shared_ptr<Sprite>>>& spritesMap);

            /**
             * @brief Start playing the image sequence.
             * @param looping If true, will automatically start again when done.
             * @spicapi
             */
            void Play(bool looping);

            /**
             * @brief Stop playing the image sequence. Whatever sprite was displayed
             *        last will remain shown.
             * @spicapi
             */
            void Stop();

            /**
             * @brief Get the frames per second of the animator
             * @return An integer representing the frames per second of the animator
             * @sharedapi
             */
            int FPS() const;

            /**
             * @brief Set the new frames per second of the animator
             * @param newFps An integer representing the new frames per second of the animator
             * @sharedapi
             */
            void FPS(int newFps);

        private:
            /**
             * @brief frames per second (playing speed)
             * @spicapi
             */
            int fps;

            std::vector<std::shared_ptr<Sprite>> sprites;

            /**
             * @brief index of the current sprite in the current state
             */
            int spriteIndex;

            /**
             * @brief name of the current state. for example "idle" or "running"
             */
            std::string currentState;


            /**
             * @brief map of the states with the respective sprites vector
             */
            std::map<std::string, std::vector<std::shared_ptr<Sprite>>> spritesMap;

            /**
             * @brief the time that has elapsed since the last frame
             */
            double elapsedTime;

            /**
             * @brief true if the animator is playing
             */
            bool isPlaying;
    };

}

#endif // ANIMATOR_H_
