#ifndef ANIMATOR_H_
#define ANIMATOR_H_

#include "Component.hpp"
#include "Sprite.hpp"

namespace spic {

    /**
     * @brief A component which can play animated sequences of sprites.
     */
    class Animator : public Component {
        public:
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

        private:
            /**
             * @brief frames per second (playing speed)
             */
            int fps;
            // ... collection of Sprites here
    };

}

#endif // ANIMATOR_H_
