#ifndef BUTTON_H_
#define BUTTON_H_

#include "UIObject.hpp"
#include <functional>

namespace spic {

    /**
     * @brief Instances of this class are clickable user interface items.
     * @spicapi
     */
    class Button : public UIObject {
        public:
            /**
             * @brief Constructor.
             * @param name The name for the game object.
             * @param tag The tag for the game object.
             * @param layer The layer for the game object.
             * @param width The width of the UI object.
             * @param height The height of the UI object.
             * @sharedapi
             */
            Button(const std::string& name, const std::string& tag, int layer, double width, double height);

            /**
             * @brief This function is called when the button is clicked, which
             *        will trigger a call to the registered onClick member.
             * @spicapi
             */
            void Click();

            /**
             * @brief Register the onClick handler to be used when the button is clicked.
             * @param callback The function to register, usually a lambda. But this can be
             *        any kind of callable.
             * @spicapi
             */
            void OnClick(std::function<void()> callback) { onClick = callback; }

            /**
             * @brief Register an onClick handler that has the Button as a parameter (to access components)
             * @param callback The function to register.
             * @sharedapi
             */
            void OnClick(std::function<void(Button*)> callback) { onClickWithButton = callback; }

            /**
             * @brief Get if the button is interactable
             * @return A boolean flag if the button is interactable or not
             * @sharedapi
             */
            bool Interactable() const;

            /**
             * @brief Set if the button is interactable
             * @param isInteractable A new boolean value to define if the button should be interactable or not
             * @sharedapi
             */
            void Interactable(bool isInteractable);

        private:
            /**
             * @brief When false, the button will not react to clicks.
             * @spicapi
             */
            bool interactable;

            /**
             * @brief The registered click handler.
             * @spicapi
             */
            std::function<void()> onClick;
            std::function<void(Button*)> onClickWithButton;
    };

}

#endif // BUTTON_H_
