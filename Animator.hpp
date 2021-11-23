#ifndef ANIMATOR_H_
#define ANIMATOR_H_

#include <vector>
#include "Component.hpp"
#include "Sprite.hpp"

namespace spic {

    /**
     * @brief A component which can play animated sequences of sprites.
     */
    class Animator : public Component {
        public:
            Animator(int fps, std::vector<Sprite> sprites);

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

            void Fps(int fps);
            [[nodiscard]] int Fps() const;

            const Sprite & CurrentSprite();
        private:
            /**
             * @brief frames per second (playing speed)
             * @spicapi
             */
            int fps;
            bool isPlaying{};
            bool _looping;
            size_t currentFrame{};

            std::vector<Sprite> sprites{};
    };

}

#endif // ANIMATOR_H_
