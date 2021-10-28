#ifndef ANIMATOR_H_
#define ANIMATOR_H_

#include "Component.hpp"
#include "Sprite.hpp"
#include <vector>
#include <memory>

namespace spic {

    /**
     * @brief A component which can play animated sequences of sprites.
     */
    class Animator : public Component {
        public:
            /**
             * @brief Constructor.
             * @param fps The amount of frames the animator will cycle though per second.
             * @param sprites An list of sprites to loop through.
             */
            Animator(int fps, const std::vector<std::shared_ptr<Sprite>>& sprites);

            /**
             * @brief Start playing the image sequence.
             * @param looping If true, will automatically start again when done.
             */
            void Play(bool looping);

            /**
             * @brief Stop playing the image sequence. Whatever sprite was displayed
             *        last will remain shown.
             */
            void Stop();

            /**
             * @brief Get the frames per second of the animator
             * @return An integer representing the frames per second of the animator
             */
            int FPS() const;

            /**
             * @brief Set the new frames per second of the animator
             * @param newFps An integer representing the new frames per second of the animator
             */
            void FPS(int newFps);

        private:
            /**
             * @brief frames per second (playing speed)
             */
            int fps;

            /**
             * @brief collection of Sprites to cycle through
             */
            std::vector<std::shared_ptr<Sprite>> sprites;
    };

}

#endif // ANIMATOR_H_
