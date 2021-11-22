#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Component.hpp"
#include <string>
#include <utility>
#include <vector>
#include <memory>
#include <iostream>

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
             * @brief Returns the first active loaded object of Type type.
             * @spicapi
             */
            template<class T>
            static std::shared_ptr<GameObject> FindObjectOfType(bool includeInactive = false) {
//                for(GameObject gameObject : gameObjects){
//                    if(typeid(GameObject) != typeid(T)){
//                        continue;
//                    }
//                    if(includeInactive || gameObject.Active()){
//                        return std::make_shared<GameObject>(gameObject);
//                    }
//                }
                return nullptr;
            }

            /**
             * @brief Gets a list of all loaded objects of Type type.
             * @spicapi
             */
            template<class T>
            static std::vector<std::shared_ptr<GameObject>> FindObjectsOfType(bool includeInactive = false) {
//                std::vector<std::shared_ptr<GameObject>> objectsOfType;
//                for(GameObject gameObject : gameObjects){
//                    if(typeid(GameObject) != typeid(T)){
//                        continue;
//                    }
//                    if(includeInactive || gameObject.Active()){
//                        objectsOfType.push_back(std::make_shared<GameObject>(gameObject));
//                    }
//                }
                return std::vector<std::shared_ptr<GameObject>>();
            }

            /**
             * @brief Removes a GameObject from the gameObjects.
             * @details TODO What happens if this GameObject is a parent to others? What happens
             *          to the Components it possesses?
             * @param obj The GameObject to be destroyed. Must be a valid pointer to existing Game Object.
             * @exception A std::runtime_exception is thrown when the pointer is not valid.
             * @spicapi
             */
            static void Destroy(std::shared_ptr<GameObject> obj);

            /**
             * @brief Removes a Component.
             * @details Will search for the Component among the GameObjects.
             * @param obj The Component to be removed.
             * @spicapi
             */
            static void Destroy(Component* obj);

            /**
             * @brief Constructor.
             * @details The new GameObject will also be added to a statically
             *          available collection, the gameObjects.  This makes the
             *          Find()-functions possible.
             * @param name The name for the game object.
             * @spicapi
             */
            explicit GameObject(std::string name);
            GameObject(std::string name, std::string tag, bool active, int layer);


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
            bool operator!=(const GameObject& other) const;

            /**
             * @brief Compare two GameObjects
             * @param other The other object to compare this one with.
             * @return true if equal, false otherwise.
             * @spicapi
             */
            bool operator==(const GameObject& other) const;

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
            void AddComponent(std::shared_ptr<Component> component) {
                components.emplace_back(component);
            }

            /**
             * @brief Get the first component of the specified type. Must be
             *        a valid subclass of Component.
             * @return Pointer to Component instance.
             * @spicapi
             */
            template<class T>
            [[nodiscard]] std::shared_ptr<Component> GetComponent() const {
                for(const std::shared_ptr<Component>& component: components){
                    if(!component.get()){
                        continue;
                    }

                    Component& componentRefPtr = *component;

                    if(typeid(componentRefPtr) == typeid(T)){
                        return component;
                    }
                }
                return nullptr;
            }


            /**
             * @brief Get the first component of the specified type from
             *        contained game objects. Must be
             *        a valid subclass of Component.
             * @return Pointer to Component instance.
             * @spicapi
             */
            template<class T>
            std::shared_ptr<Component> GetComponentInChildren() const {
//                if(!std::is_base_of<Component, T>::value){
//                    return nullptr;
//                }
//                for(Component component: components){
//                    if(typeid(component) == typeid(GameObject)){
//                        continue;
//                    }
//                    GameObject *gameObject = (GameObject*)&component;
//                    for(Component innerComponent : gameObject->components){
//                        if(typeid(innerComponent) == typeid(T)){
//                            return std::make_shared<Component>(innerComponent);
//                        }
//                    }
//                }
                return nullptr;
            }

            /**
             * @brief Get the first component of the specified type from
             *        the parent game object. Must be
             *        a valid subclass of Component.
             * @return Pointer to Component instance.
             * @spicapi
             */
            template<class T>
            std::shared_ptr<Component> GetComponentInParent() const {
//                if(parent != nullptr){
//                    return nullptr;
//                }
//                if(!std::is_base_of<Component, T>::value){
//                    return nullptr;
//                }
//                for(Component component: parent->components){
//                    if(typeid(component) == typeid(T)){
//                        return std::make_shared<Component>(component);
//                    }
//                }
                return nullptr;
            }

            /**
             * @brief Get all components of the specified type. Must be
             *        a valid subclass of Component.
             * @return Vector with pointers to Component instances.
             * @spicapi
             */
            template<class T>
            [[nodiscard]] std::vector<std::shared_ptr<Component>> GetComponents() const {
                std::vector<std::shared_ptr<Component>> foundComponents;

                for(std::shared_ptr<Component> component : components){
                    if(!component.get()){
                        continue;
                    }

                    Component& componentRefPtr = *component;

                    if(typeid(componentRefPtr) == typeid(T)){
                        foundComponents.emplace_back(component);
                    }
                }

                return foundComponents;
            }

            /**
             * @brief Get all components of the specified type from
             *        contained game objects. Must be
             *        a valid subclass of Component.
             * @return Vector with pointers to Component instances.
             * @spicapi
             */
            template<class T>
            std::vector<std::shared_ptr<Component>> GetComponentsInChildren() const {
//                std::vector<std::shared_ptr<Component>> foundComponents;
//                if(std::is_base_of<Component, T>::value){
//                    return foundComponents;
//                }
//                for(Component component: components){
//                    if(typeid(component) != typeid(GameObject)){
//                        continue;
//                    }
//                    GameObject *gameObject = (GameObject*)&component;
//                    for(Component innerComponent : gameObject->components){
//                        if(typeid(innerComponent) == typeid(T)){
//                            foundComponents.push_back(std::make_shared<Component>(innerComponent));
//                        }
//                    }
//                }
                return std::vector<std::shared_ptr<Component>>();
            }

            /**
             * @brief Get all components op the specified type from
             *        the parent game object. Must be
             *        a valid subclass of Component.
             * @return Vector with pointers to Component instances.
             * @spicapi
             */
            template<class T>
            std::vector<std::shared_ptr<Component>> GetComponentsInParent() const {
//                std::vector<std::shared_ptr<Component>> parentComponents;
//                if(parent != nullptr){
//                    return parentComponents;
//                }
//                if(!std::is_base_of<Component, T>::value){
//                    return parentComponents;
//                }
//                for(Component component: parent->components){
//                    if(typeid(component) == typeid(T)){
//                        parentComponents.push_back(std::make_shared<Component>(component));
//                    }
//                }
                return std::vector<std::shared_ptr<Component>>();
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

            void addChild( GameObject* newGameObject);

            void Name(const std::string& name);
            std::string Name() const;

            void Tag(const std::string& tag);
            std::string Tag() const;


            void Layer(int layer);
            int Layer() const;

            int Id() const { return id; }
            void Id(int newId) { id = newId; }

    private:
            std::string name;
            std::string tag;
            bool active;
            int layer;
            static std::vector<std::shared_ptr<GameObject>> gameObjects;
            std::vector<std::shared_ptr<Component>> components;
//            std::vector<GameObject*> children;
//            GameObject* parent;
            int id{};
        // ... more members
    };

}

#endif // GAMEOBJECT_H_
