#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Component.hpp"
#include <string>
#include <vector>
#include <memory>

namespace spic {

    /**
     * @brief Any object which should be represented on screen.
     */
    class GameObject {
        public:
            /**
             * @brief Finds a GameObject by name and returns it.
             * @param name The name of the GameObject you want to find.
             * @return Pointer to GameObject, or nullptr if not found.
             * @spicapi
             */
            static std::shared_ptr<GameObject> Find(const std::string& name);

            /**
             * @brief Returns a vector of active GameObjects tagged tag. Returns empty
             *        vector if no GameObject was found.
             * @param tag The tag to find.
             * @return std::vector of GameObject pointers. No ownership.
             * @spicapi
             */
            static std::vector<std::shared_ptr<GameObject>> FindGameObjectsWithTag(const std::string& tag);

            /**
             * @brief Returns one active GameObject tagged tag. Returns nullptr if no GameObject was found.
             * @param tag The tag to find.
             * @return Pointer to GameObject, or nullptr if not found.
             * @spicapi
             */
            static std::shared_ptr<GameObject> FindWithTag(const std::string& tag);

            /**
             * @brief Returns the first active loaded object of type T.
             * @spicapi
             */
            template<class T>
            static std::shared_ptr<T> FindObjectOfType(bool includeInactive = false) {
                // ... implementation here
            }

            /**
             * @brief Gets a list of all loaded objects of type T.
             * @spicapi
             */
            template<class T>
            static std::vector<std::shared_ptr<T>> FindObjectsOfType(bool includeInactive = false) {
                // ...implementation here
            }

            /**
             * @brief Removes a GameObject from the administration.
             * @details Child GameObjects will be destroyed, too, as well as
             *          Components owned by the GameObject.
             * @param obj The GameObject to be destroyed. Must be a valid pointer to existing Game Object.
             * @exception A std::runtime_exception is thrown when the pointer is not valid.
             * @spicapi
             */
            static void Destroy(std::shared_ptr<GameObject> obj);

            /**
             * @brief Removes a Component.
             * @details Will search for the Component among the GameObjects.
             * @param obj The Component to be removed. If obj == nullptr, Destroy() does nothing.
             * @spicapi
             */
            static void Destroy(Component* obj);

            /**
             * @brief Constructor.
             * @details The new GameObject will also be added to a statically
             *          available collection, the administration.  This makes the
             *          Find()-functions possible.
             * @param name The name for the game object.
             * @spicapi
             */
            GameObject(const std::string& name);

            /**
             * @brief Does the object exist? TODO wat wordt hiermee bedoeld?
             * @spicapi
             */
            operator bool();

            /**
             * @brief Compare two GameObjects.
             * @param other The other object to compare this one with.
             * @return true if not equal, false otherwise.
             * @spicapi
             */
            bool operator!=(const GameObject& other);

            /**
             * @brief Compare two GameObjects
             * @param other The other object to compare this one with.
             * @return true if equal, false otherwise.
             * @spicapi
             */
            bool operator==(const GameObject& other);

            /**
             * @brief Add a Component of the specified type. Must be a valid
             *        subclass of Component. The GameObject assumes ownership of
             *        the Component.
             * @details This function places a pointer to the component in
             *          a suitable container.
             * @param component Reference to the component.
             * @spicapi
             */
            template<class T>
            void AddComponent(std::shared_ptr<T> component) {
                // ... implementation here
            }

            /**
             * @brief Get the first component of the specified type. Must be
             *        a valid subclass of Component.
             * @return Pointer to Component instance.
             * @spicapi
             */
            template<class T>
            std::shared_ptr<T> GetComponent() const {
                // ... implementation here
            }

            /**
             * @brief Get the first component of the specified type from
             *        contained game objects. Must be
             *        a valid subclass of Component.
             * @return Pointer to Component instance.
             * @spicapi
             */
            template<class T>
            std::shared_ptr<T> GetComponentInChildren() const {
                // ... implementation here
            }

            /**
             * @brief Get the first component of the specified type from
             *        the parent game object. Must be
             *        a valid subclass of Component.
             * @return Pointer to Component instance.
             * @spicapi
             */
            template<class T>
            std::shared_ptr<T> GetComponentInParent() const {
                // ... implementation here
            }

            /**
             * @brief Get all components of the specified type. Must be
             *        a valid subclass of Component.
             * @return Vector with pointers to Component instances.
             * @spicapi
             */
            template<class T>
            std::vector<std::shared_ptr<T>> GetComponents() const {
                // ... implementation here
            }

            /**
             * @brief Get all components of the specified type from
             *        contained game objects. Must be
             *        a valid subclass of Component.
             * @return Vector with pointers to Component instances.
             * @spicapi
             */
            template<class T>
            std::vector<std::shared_ptr<T>> GetComponentsInChildren() const {
                // ... implementation here
            }

            /**
             * @brief Get all components op the specified type from
             *        the parent game object. Must be
             *        a valid subclass of Component.
             * @return Vector with pointers to Component instances.
             * @spicapi
             */
            template<class T>
            std::vector<std::shared_ptr<T>> GetComponentsInParent() const {
                // ... implementation here
            }

            /**
             * @brief Activates/Deactivates the GameObject, depending on the given true or false value.
             * @param active Desired value.
             * @spicapi
             */
            void Active(bool flag);

            /**
             * @brief Returns whether this game object is itself active.
             * @return true if active, false if not.
             * @spicapi
             */
            bool Active() const;

            /**
             * @brief Returns whether this game component is active, taking its parents
             *        into consideration as well.
             * @return true if game object and all of its parents are active,
             *        false otherwise.
             * @spicapi
             */
            bool IsActiveInWorld() const;

        private:
            std::string name;
            std::string tag;
            bool active;
            int layer;
            // ... more members
    };

}

#endif // GAMEOBJECT_H_
