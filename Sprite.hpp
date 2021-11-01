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
        Sprite(const std::string& sprite, Color color, int sortingLayer, int orderInLayer);

        std::string GetSpriteUrl();

        Color GetColor();
        void SetColor(Color newColor);

        bool ShouldFlipX();
        void SetFlipX(bool flag);

        bool ShouldFlipY();
        void SetFlipY(bool flag);

        int GetSortingLayer();
        void SetSortingLayer(int newLayer);

        int GetOrderInLayer();
        void SetOrderInLayer(int newOrder);

    private:
    #include "Sprite_private.hpp"
    };

}

#endif // SPRITERENDERER_H_
