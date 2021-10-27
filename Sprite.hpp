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
             * @brief Constructor
             * @param sprite The source to the sprite
             * @param flipX The flip of the x-axis of the sprite
             * @param flipY The flip of the y-axis of the sprite
             * @param sortingLayer The layer the sprite will be sorted on
             * @param orderLayer The layer the sprite will be ordered on
             */
            Sprite(const std::string& sprite, bool flipX, bool flipY, int sortingLayer, int orderLayer);
            
            /**
             * @brief Constructor
             * @param sprite The source to the sprite
             * @param color The color of the sprite
             * @param flipX The flip of the x-axis of the sprite
             * @param flipY The flip of the y-axis of the sprite
             * @param sortingLayer The layer the sprite will be sorted on
             * @param orderInLayer The layer the sprite will be ordered on
             */
            Sprite(const std::string& sprite, const Color& color, bool flipX, bool flipY, int sortingLayer, int orderInLayer);

            /**
             * @brief The texture of the sprite
             * @param sprite the path to the sprite
             */
            void Texture(const std::string& sprite);

            /**
             * @brief The texture of the sprite
             * @return The path of the sprite
             */
            const std::string& Texture() const;

            /**
             * @brief The color of the sprite
             * @param color the color
             */
            void Color(const spic::Color& color);

            /**
             * @brief The color of the sprite
             * @return the color
             */
            const spic::Color& Color() const;

            /**
             * @brief Whether the sprite should be flipped on the X-axis
             * @param flipX desired value
             */
            void FlipX(bool flipX);

            /**
             * @brief Whether the sprite should be flipped on the X-axis
             * @return current value
             */
            bool FlipX() const;

            /**
             * @brief Whether the sprite should be flipped on the Y-axis
             * @param flipY desired value
             */
            void FlipY(bool flipY);

            /**
             * @brief Whether the sprite should be flipped on the Y-axis
             * @return current value
             */
            bool FlipY() const;

            /**
             * @brief The layer the sprite will be sorted on
             * @param sortingLayer desired value
             */
            void SortingLayer(int sortingLayer);

            /**
             * @brief The layer the sprite will be sorted on
             * @return current value
             */
            int SortingLayer() const;

            /**
             * @brief The layer the sprite will be ordered on
             * @param orderInLayer desired value
             */
            void OrderInLayer(int orderInLayer);

            /**
             * @brief The layer the sprite will be ordered on
             * @return current value
             */
            int OrderInLayer() const;

        private:
            std::string sprite;
            spic::Color color;
            bool flipX;
            bool flipY;
            int sortingLayer;
            int orderInLayer;
    };

}

#endif // SPRITERENDERER_H_
