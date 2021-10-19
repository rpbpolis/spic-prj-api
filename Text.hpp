#ifndef TEXT_H_
#define TEXT_H_

#include "UIObject.hpp"
#include "Color.hpp"
#include <string>

namespace spic {

    /**
     * @brief Enumeration for different text alignments.
     */
    enum class Alignment {
        left,
        center,
        right
    };

    /**
     * @brief Class representing a piece of text which can be rendered.
     */
    class Text : public UIObject {
        public:
            /**
             * @brief Constructor.
             * @param name The name for the game object.
             * @param tag The tag for the game object.
             * @param layer The layer for the game object.
             * @param width The width of the UI object.
             * @param height The height of the UI object.
             */
            Text(const std::string& name, const std::string& tag, int layer, double width, double height);
            
            /**
             * @brief Constructor.
             * @param name The name for the game object.
             * @param tag The tag for the game object.
             * @param layer The layer for the game object.
             * @param width The width of the UI object.
             * @param height The height of the UI object.
             * @param text The content of the Text object
             * @param font The font the Text object will use to render
             * @param size The size the font will be rendered at
             * @param alignment The alignment the content will be rendered with 
             * @param color The color the content will be rendered in
             */
            Text(const std::string& name, const std::string& tag, int layer, double width, double height, const std::string& text, const std::string& font, int size, Alignment alignment, const Color& color);
        private:
            std::string text;
            std::string font;
            int size;
            Alignment alignment;
            Color color;
    };

}

#endif // TEXT_H_
