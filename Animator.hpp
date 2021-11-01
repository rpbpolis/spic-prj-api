#ifndef ANIMATOR_H_
#define ANIMATOR_H_

#include "Component.hpp"
#include "Sprite.hpp"
#include "SpriteSheet.hpp"

namespace spic {

    /**
     * @brief A component which can play animated sequences of sprites.
     */
    class Animator : public Component {
        public:

            Animator(SpriteSheet sheet, int fps);
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

            int GetFps();

            void SetFps(int newFps);

        private:
        #include "Animator_private.hpp"
    };
}

#endif // ANIMATOR_H_
