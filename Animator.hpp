#ifndef ANIMATOR_H_
#define ANIMATOR_H_

#include "Component.hpp"
#include "Sprite.hpp"
#include <vector>
#include <memory>

#if __has_include("Animator_includes.hpp")
#include "Animator_includes.hpp"
#endif

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

#if __has_include("Animator_public.hpp")
#include "Animator_public.hpp"
#endif

        private:
            /**
             * @brief frames per second (playing speed)
             * @spicapi
             */
            int fps;

#if __has_include("Animator_private.hpp")
#include "Animator_private.hpp"
#endif
    };

}

#endif // ANIMATOR_H_
