#ifndef SPRITERENDERER_H_
#define SPRITERENDERER_H_

#include "Component.hpp"
#include "Color.hpp"
#include <string>

namespace spic {

    /**
     * @brief A component representing a sprite (small image)
     * @spicapi
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
             * @sharedapi
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
             * @sharedapi
             */
            Sprite(const std::string& sprite, const Color& color, bool flipX, bool flipY, int sortingLayer, int orderInLayer);

            /**
             * @brief The texture of the sprite
             * @param sprite the path to the sprite
             * @sharedapi
             */
            void Texture(const std::string& sprite);

            /**
             * @brief The texture of the sprite
             * @return The path of the sprite
             * @sharedapi
             */
            const std::string& Texture() const;

            /**
             * @brief The color of the sprite
             * @param color the color
             * @sharedapi
             */
            void Color(const spic::Color& color);

            /**
             * @brief The color of the sprite
             * @return the color
             * @sharedapi
             */
            const spic::Color& Color() const;

            /**
             * @brief Whether the sprite should be flipped on the X-axis
             * @param flipX desired value
             * @sharedapi
             */
            void FlipX(bool flipX);

            /**
             * @brief Whether the sprite should be flipped on the X-axis
             * @return current value
             * @sharedapi
             */
            bool FlipX() const;

            /**
             * @brief Whether the sprite should be flipped on the Y-axis
             * @param flipY desired value
             * @sharedapi
             */
            void FlipY(bool flipY);

            /**
             * @brief Whether the sprite should be flipped on the Y-axis
             * @return current value
             * @sharedapi
             */
            bool FlipY() const;

            /**
             * @brief The layer the sprite will be sorted on
             * @param sortingLayer desired value
             * @sharedapi
             */
            void SortingLayer(int sortingLayer);

            /**
             * @brief The layer the sprite will be sorted on
             * @return current value
             * @sharedapi
             */
            int SortingLayer() const;

            /**
             * @brief The layer the sprite will be ordered on
             * @param orderInLayer desired value
             * @sharedapi
             */
            void OrderInLayer(int orderInLayer);

            /**
             * @brief The layer the sprite will be ordered on
             * @return current value
             * @sharedapi
             */
            int OrderInLayer() const;

            /**
             * @brief The width that should be rendered. (Overwrites QueryTexture width in Renderer)
             * @return the current cutoffWidth
             * @sharedapi
             */
            double CutoffWidth() const;

            /**
             * @brief Replace cutoff width
             * @param newValue
             */
            void CutoffWidth(double newValue);

        private:
            std::string sprite;
            spic::Color color;
            bool flipX;
            bool flipY;
            int sortingLayer;
            int orderInLayer;
            double cutoffWidth;
    };

}

#endif // SPRITERENDERER_H_
