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
            const std::string& Text() const { return text; }

            /**
             * @brief Set the text content of the Text object
             * @param text new content
             */
            void SetText(const std::string& text);

        private:
            std::string text;
            std::string font;
            int size;
            Alignment alignment;
            Color color;
    };

}

#endif // TEXT_H_
