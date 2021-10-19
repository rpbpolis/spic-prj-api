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
             * @brief Get the content of the Text object
             * @return A reference to the content of the Text object
             */
            const std::string& Content() const { return text; }

            /**
             * @brief Set the text content of the Text object
             * @param text new content
             */
            void Content(const std::string& text);

            /**
             * @brief Get the font of the Text object
             * @return A reference to the font of the Text object
             */
            const std::string& Font() const { return font; }

            /**
             * @brief Set the font of the Text object
             * @param font the new font
             */
            void Font(const std::string& font);

            /**
             * @brief Get the size of the Text object
             * @return A reference to the size of the Text object
             */
            int Size() const { return size; }

            /**
             * @brief Set the size of the Text object
             * @param size the new size
             */
            void Size(int size);

            /**
             * @brief Get the alignment of the Text object
             * @return A reference to the alignment of the Text object
             */
            Alignment TextAlignment() const { return alignment; }

            /**
             * @brief Set the alignment of the content of the Text object
             * @param alignment the new alignment
             */
            void TextAlignment(Alignment alignment);

            /**
             * @brief Get the color of the Text object
             * @return A reference to the color of the Text object
             */
            const Color& Color() const { return color; }

            /**
             * @brief Set the color of the Text object
             * @param color the new color
             */
            void Color(const Color& color);

        private:
            std::string text;
            std::string font;
            int size;
            Alignment alignment;
            Color color;
    };

}

#endif // TEXT_H_
