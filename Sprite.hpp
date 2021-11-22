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
        private:
            std::string sprite;
            Color color;
            bool flipX;
            bool flipY;
            int sortingLayer;
            int orderInLayer;
        public:
            void SortingLayer(int newSortingLayer);
            int SortingLayer() const;

            void OrderInLayer(int newOrderInLayer);
            int OrderInLayer() const;

            void FlipX(bool newFlipX);
            bool FlipX() const;

            void FlipY(bool newFlipY);
            bool FlipY() const;

            void SpriteColor(Color newColor);
            Color SpriteColor() const;

            void SpriteSrc(const std::string& newSprite);
            std::string SpriteSrc() const;

            Sprite(std::string sprite, Color color, bool flipX, bool flipY, int sortingLayer, int orderInLayer);
    };
}

#endif // SPRITERENDERER_H_
