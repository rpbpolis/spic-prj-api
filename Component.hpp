#ifndef COMPONENT_H_
#define COMPONENT_H_

namespace spic {

    /**
     * @brief Base class for all components.
     */
    class Component {
        public:
            /**
             * @brief Getter for active status.
             * @return true if active, false otherwise.
             * @spicapi
             */
            bool Active() const { return active; }

            /**
             * @brief flag New active status.
             * @spicapi
             */
            void Active(bool flag) { active = flag; }

            bool operator==(const Component& other);
            bool operator!=(const Component& other);


            int Id() const { return id; }
            void Id(int newId) { id = newId; }


    private:
            /**
             * @brief Active status.
             */
            bool active;

            int id;
    };

}

#endif // COMPONENT_H_
