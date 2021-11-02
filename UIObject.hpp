#ifndef UIOBJECT_H_
#define UIOBJECT_H_

#include "GameObject.hpp"

#if __has_include("UIObject_includes.hpp")
#include "UIObject_includes.hpp"
#endif

namespace spic {

    /**
     * @brief Base class for a user interface object like Button or Text.
     * @spicapi
     */
    class UIObject : public GameObject {
        public:
            /**
             * @brief Constructor.
             * @param name The name for the game object.
             * @param tag The tag for the game object.
             * @param layer The layer for the game object.
             * @param width The width of the UI object.
             * @param height The height of the UI object.
             */
            UIObject(const std::string& name, const std::string& tag, int layer, double width, double height);

            /**
             * @brief Get the width of the UIObject
             * @return The width of the UIObject
             */
            double Width() const;

            /**
             * @brief Set the width of the UIObject
             * @param newWidth The new width of the UIObject
             */
            void Width(double newWidth);

            /**
             * @brief Get the height of the UIObject
             * @return The height of the UIObject
             */
            double Height() const;

            /**
             * @brief Set the height of the UIObject
             * @param newHeight The new height of the UIObject
             */
            void Height(double newHeight);

        private:
            double width;
            double height;

#if __has_include("UIObject_private.hpp")
#include "UIObject_private.hpp"
#endif
    };

}

#endif // UIOBJECT_H_
