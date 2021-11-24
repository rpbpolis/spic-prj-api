#ifndef TEXT_H_
#define TEXT_H_

#include "UIObject.hpp"
#include "Color.hpp"
#include <string>
#include <utility>

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
            Text(const std::string & objectName, const std::string & objectTag, bool active, int layer, double newWidth, double newHeight, std::string text, std::string font, int size, Alignment alignment,
                 const Color &color)
            : UIObject(objectName, objectTag, active, layer, newWidth, newHeight), text(std::move(text)), font(std::move(font)), size(size),
              alignment(alignment), color(color) {}

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
