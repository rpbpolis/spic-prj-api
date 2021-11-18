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
            void SortingLayer(int sortingLayer);
            int SortingLayer();

            void OrderInLayer(int orderInLayer);
            int OrderInLayer();

            void FlipX(bool flipX);
            bool FlipX();

            void FlipY(bool flipY);
            bool FlipY();

            void SpriteColor(Color color);
            Color SpriteColor();

            void SpriteSrc(std::string sprite);
            std::string SpriteSrc();

            Sprite(std::string sprite, double r, double g, double b, double a, bool flipX, bool flipY, int sortingLayer, int orderInLayer);
    };
}

#endif // SPRITERENDERER_H_
