#ifndef BUTTON_H_
#define BUTTON_H_

#include "UIObject.hpp"
#include <functional>

namespace spic {

    /**
     * @brief Instances of this class are clickable user interface items.
     */
    class Button : public UIObject {
        public:

        private:
            bool interactable;
            std::function<void()> onClick;
    };

}

#endif // BUTTON_H_
