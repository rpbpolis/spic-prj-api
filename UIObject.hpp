#ifndef UIOBJECT_H_
#define UIOBJECT_H_

#include "GameObject.hpp"

namespace spic {

    /**
     * @brief Base class for a user interface object like Button or Text.
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

        private:
            double width;
            double height;
    };

}

#endif // UIOBJECT_H_
