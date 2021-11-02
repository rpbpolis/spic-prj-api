#ifndef IKEYLISTENER_H_
#define IKEYLISTENER_H_

namespace spic {

    /**
     * @brief Interface for objects wanting to respond to keyboard events.
     */
    class IKeyListener {
        public:
            /**
             * @brief This method will be caled whenever a key is pressed.
             *        Override for implementing the desired behaviour.
             * @spicapi
             */
            virtual void OnKeyPressed() = 0;

            /**
             * @brief This method will be called whenever a pressed key is released again.
             *        Override for implementing the desired behaviour.
             * @spicapi
             */
            virtual void OnKeyReleased() = 0;
    };

}

#endif // IKEYLISTENER_H_
