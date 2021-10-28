#ifndef UIOBJECT_H_
#define UIOBJECT_H_

#include "GameObject.hpp"

namespace spic {

    /**
     * @brief Base class for a user interface object like Button or Text.
     */
    class UIObject : public GameObject {
        private:
        #include "UIObject_private.hpp"
    };

}

#endif // UIOBJECT_H_
