#ifndef TEXT_H_
#define TEXT_H_

#include "UIObject.hpp"
#include "Color.hpp"
#include <string>

namespace spic {

    /**
     * @brief Enumeration for different text alignments.
     * @spicapi
     */
    enum class Alignment {
        left,
        center,
        right
    };

    /**
     * @brief Class representing a piece of text which can be rendered.
     * @spicapi
     */
    class Text : public UIObject {
        private:
            std::string text;
            std::string font;
            int size;
            Alignment alignment;
            Color color;
        public:
            void TextString(const std::string & newText);
            [[nodiscard]] const std::string & TextString() const;

            void Font(const std::string & newFont);
            [[nodiscard]] const std::string & Font() const;

            void Size(int newSize);
            [[nodiscard]] int Size() const;

            void Alignment(const spic::Alignment & newAlignment);
            [[nodiscard]] const spic::Alignment & Alignment() const;

            void Color(const spic::Color & newColor);
            [[nodiscard]] const spic::Color & Color() const;
    };

}

#endif // TEXT_H_
