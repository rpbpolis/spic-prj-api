#ifndef SPRITERENDERER_H_
#define SPRITERENDERER_H_

#include "Component.hpp"
#include "Color.hpp"
#include <string>

namespace spic {

    /**
     * @brief A component representing a sprite (small image)
     */
    class Sprite : public Component {
        public:
            /**
             * @brief The texture of the sprite
             * @param sprite the path to the sprite
             */
            void Texture(std::string sprite) { this->sprite = sprite; }

            /**
             * @brief The texture of the sprite
             * @return The path of the sprite
             */
            std::string Texture() const { return sprite; }

            /**
             * @brief The color of the sprite
             * @param color the color
             */
            void Color(Color color) { this->color = color; }

            /**
             * @brief The color of the sprite
             * @return the color
             */
            spic::Color Color() const { return color; }

            /**
             * @brief Whether the sprite should be flipped on the X-axis
             * @param flipX desired value
             */
            void FlipX(bool flipX) { this->flipX = flipX; }

            /**
             * @brief Whether the sprite should be flipped on the X-axis
             * @return current value
             */
            bool FlipX() const { return flipX; }

            /**
             * @brief Whether the sprite should be flipped on the Y-axis
             * @param flipY desired value
             */
            void FlipY(bool flipY) { this->flipY = flipY; }

            /**
             * @brief Whether the sprite should be flipped on the Y-axis
             * @return current value
             */
            bool FlipY() const { return flipY; }

            /**
             * @brief The layer the sprite will be sorted on
             * @param sortingLayer desired value
             */
            void SortingLayer(int sortingLayer) { this->sortingLayer = sortingLayer; }

            /**
             * @brief The layer the sprite will be sorted on
             * @return current value
             */
            int SortingLayer() const { return sortingLayer; }

            /**
             * @brief The layer the sprite will be ordered on
             * @param orderInLayer desired value
             */
            void OrderInLayer(int orderInLayer) { this->orderInLayer = orderInLayer; }

            /**
             * @brief The layer the sprite will be ordered on
             * @return current value
             */
            int OrderInLayer() const { return orderInLayer; }

        private:
            std::string sprite;
            Color color;
            bool flipX;
            bool flipY;
            int sortingLayer;
            int orderInLayer;
    };

}

#endif // SPRITERENDERER_H_
