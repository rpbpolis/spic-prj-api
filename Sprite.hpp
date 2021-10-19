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
