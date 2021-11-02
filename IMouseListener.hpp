#ifndef IMOUSELISTENER_H_
#define IMOUSELISTENER_H_

namespace spic {

    /**
     * @brief Interface for objects wanting to respond to mouse events.
     */
    class IMouseListener {
        public:
            /**
             * @brief Called whenever the mouse is moved.
             * @spicapi
             */
            virtual void OnMouseMoved() = 0;

            /**
             * @brief Called whenever a mouse button is clicked.
             * @spicapi
             */
            virtual void OnMouseClicked() = 0;

            /**
             * @brief Called each frame when a mouse button is still down.
             * @spicapi
             */
            virtual void OnMousePressed() = 0;

            /**
             * @brief Called whenever a mouse button is released.
             * @spicapi
             */
            virtual void OnMouseReleased() = 0;
    };

}

#endif // IMOUSELISTENER_H_
