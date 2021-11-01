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

            Button(double width, double height, const std::string& name, bool interactable = true) : UIObject(width, height, name);
            /**
             * @brief This function is called when the button is clicked, which
             *        will trigger a call to the registered onClick member.
             */
            void Click();

            /**
             * @brief Register the onClick handler to be used when the button is clicked.
             * @param callback The function to register, usually a lambda. But this can be
             *        any kind of callable.
             */
            void SetOnClick(std::function<void()> callback);

            bool IsInteractable();

            void SetInteractable(bool interactable);

        private:
        #include "Button_private.hpp"
    };

}

#endif // BUTTON_H_
