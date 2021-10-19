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
