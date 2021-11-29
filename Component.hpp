#ifndef COMPONENT_H_
#define COMPONENT_H_

namespace spic {

    /**
     * @brief Base class for all components.
     */
    class Component {
    public:
        Component();

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
        virtual void Active(bool flag) { active = flag; }

        bool operator==(const Component& other) const;
        bool operator!=(const Component& other) const;

        static int nextAvailableId;

        int Id() const { return id; }


    private:
        /**
         * @brief Active status.
         */
        bool active;

        int id;
    };

}

#endif // COMPONENT_H_
