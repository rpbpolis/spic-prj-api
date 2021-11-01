#ifndef UIOBJECT_H_
#define UIOBJECT_H_

#include "GameObject.hpp"

namespace spic {

    /**
     * @brief Base class for a user interface object like Button or Text.
     */
    class UIObject : public GameObject {
    public:
        UIObject(double width, double height, const std::string& name) : GameObject(name);

        double GetWidth();
        virtual SetWidth(double newWidth);

        double GetHeight();
        virtual SetHeight(double newHeight);
    private:
    #include "UIObject_private.hpp"
    };

}

#endif // UIOBJECT_H_
