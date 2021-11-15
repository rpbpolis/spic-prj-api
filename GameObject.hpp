#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Component.hpp"
#include "Debug.hpp"
#include "Engine.hpp"
#include "Transform.hpp"
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using Components = std::vector<std::shared_ptr<spic::Component>>;

namespace spic {

    /**
     * @brief Any object which should be represented on screen.
     * @spicapi
     */
    class GameObject {
        public:
            virtual ~GameObject() = default;

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
            static std::shared_ptr<T> FindObjectOfType(bool includeInactive = false) {
                auto activeScene = Engine::Instance().PeekScene();

                if (!activeScene) {
                    Debug::LogError("GameObject.hpp FindObjectOfType: ActiveScene is null");
                    return nullptr;
                }

                for (const auto& obj : activeScene->Contents()) {
                    auto ptr = std::dynamic_pointer_cast<T>(obj);
                    if (ptr) {
                        if (!includeInactive && !obj->Active()) {
                            continue;
                        }
                        return ptr;
                    }
                }

                return nullptr;
            }

            /**
             * @brief Gets a list of all loaded objects of Type type.
             * @spicapi
             */
            template<class T>
            static std::vector<std::shared_ptr<T>> FindObjectsOfType(bool includeInactive = false) {
                auto activeScene = Engine::Instance().PeekScene();
                std::vector<std::shared_ptr<T>> result;

                if (activeScene) {
                    for (const auto& obj : activeScene->Contents()) {
                        auto ptr = std::dynamic_pointer_cast<T>(obj);
                        if (ptr) {
                            if (!includeInactive && !obj->Active()) {
                                continue;
                            }
                            result.push_back(ptr);
                        }
                    }
                } else {
                    Debug::LogError("GameObject.hpp FindObjectOfType vector: ActiveScene is null");
                }

                return result;
            }

            /**
             * @brief Removes a GameObject from the administration.
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
             * Create a new GameObject and DO NOT add it to the static administration.
             * @tparam GameObjectType The type of GameObject
             * @tparam GameObjectArgs The argument types for the constructor of type GameObjectType
             * @param args The arguments for the constructor of type GameObjectType
             * @return A shared pointer to a newly created GameObject
             * @sharedapi
             */
            template<typename GameObjectType = spic::GameObject, typename... GameObjectArgs>
            static std::shared_ptr<GameObjectType> Create(GameObjectArgs&&... args) {
                return CreateWithComponents<GameObjectType>(args..., std::vector<std::shared_ptr<spic::Component>>());
            }

            /**
             * Create a new GameObject with components and DO NOT add it to the static administration.
             * @tparam GameObjectType The type of GameObject
             * @tparam GameObjectArgsAndComponents The argument types for the constructor of type GameObjectType and a
             * vector of components to add to the game object
             * @param args The arguments for the constructor of type GameObjectType
             * @return A shared pointer to a newly created GameObject with the added components
             * @sharedapi
             */
            template<typename GameObjectType = spic::GameObject, typename... GameObjectArgsAndComponents>
            static std::shared_ptr<GameObjectType> CreateWithComponents(GameObjectArgsAndComponents&&... input) {
                return Create_GameObjectArgsWithIndices<GameObjectType>(std::forward_as_tuple(input...), std::make_index_sequence<sizeof...(input) - 1>{});
            }

            /**
             * Create a new GameObject and add it to the static administration.
             * @tparam GameObjectType The type of GameObject
             * @tparam GameObjectArgs The argument types for the constructor of type GameObjectType
             * @param args The arguments for the constructor of type GameObjectType
             * @return A shared pointer to a newly created GameObject
             * @sharedapi
             */
            template<typename GameObjectType = spic::GameObject, typename... GameObjectArgs>
            static std::shared_ptr<GameObjectType> CreateGlobal(GameObjectArgs&&... args) {
                return CreateGlobalWithComponents<GameObjectType>(args..., std::vector<std::shared_ptr<spic::Component>>());
            }

            /**
             * Create a new GameObject with components and add it to the static administration.
             * @tparam GameObjectType The type of GameObject
             * @tparam GameObjectArgsAndComponents The argument types for the constructor of type GameObjectType and a
             * vector of components to add to the game object
             * @param args The arguments for the constructor of type GameObjectType
             * @return A shared pointer to a newly created GameObject with the added components
             * @sharedapi
             */
            template<typename GameObjectType = spic::GameObject, typename... GameObjectArgsAndComponents>
            static std::shared_ptr<GameObjectType> CreateGlobalWithComponents(GameObjectArgsAndComponents&&... input) {
                // Check if we have a scene
                auto scene = Engine::Instance().PeekScene();
                if (!scene) {
                    Debug::LogWarning("Can not create game object without scene");
                    return nullptr;
                }

                auto object =  Create_GameObjectArgsWithIndices<GameObjectType>(std::forward_as_tuple(input...), std::make_index_sequence<sizeof...(input) - 1>{});

                // Add it to the scene "static administration"
                scene->Contents().push_back(object);

                return object;
            }

            /**
             * Add a child to a parent game object.
             * This is a safer alternative to the two separate calls to AddChild() and Parent().
             * @param parent The parent game object.
             * @param child The child game object.
             */
            static void AddChild(std::shared_ptr<GameObject> parent, std::shared_ptr<GameObject> child);

            /**
             * Adds multiple children to a parent game object.
             * This is a safer alternative to the two separate calls to AddChild() and Parent().
             * @param parent The parent game object.
             * @param child The child game object.
             */
            static void AddChildren(std::shared_ptr<GameObject> parent, std::vector<std::shared_ptr<GameObject>> children);

            /**
             * @brief Constructor.
             * @details The new GameObject will also be added to a statically
             *          available collection, the administration.  This makes the
             *          Find()-functions possible.
             * @param name The name for the game object.
             * @param tag The tag for the game object.
             * @param layer The layer for the game object.
             * @spicapi
             */
            GameObject(const std::string& name, const std::string& tag, int layer);

            /**
             * @brief Does the object exist?
             * @spicapi
             */
            operator bool() const;

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
            void AddComponent(std::shared_ptr<T> component) {
                components.push_back(component);
            }

            /**
             * @brief Removes a component from a game object.
             * @param component Reference to the component.
             * @sharedapi
             */
            void RemoveComponent(std::shared_ptr<Component> component);

            /**
             * @brief Get the first component of the specified type. Must be
             *        a valid subclass of Component.
             * @return Pointer to Component instance.
             * @spicapi
             */
            template<class T>
            std::shared_ptr<T> GetComponent() const {
                for (const auto& component : components) {
                    auto ptr = std::dynamic_pointer_cast<T>(component);
                    if (ptr) return ptr;
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
            std::shared_ptr<T> GetComponentInChildren() const {
                for (const auto& childComponent : children) {
                    for (const auto& component : childComponent->components) {
                        auto ptr = std::dynamic_pointer_cast<T>(component);
                        if (ptr) return ptr;
                    }
                }
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
            std::shared_ptr<T> GetComponentInParent() const {
                auto p = parent.lock();
                if (p) {
                    for (const auto& component : p->components) {
                        auto ptr = std::dynamic_pointer_cast<T>(component);
                        if (ptr) return ptr;
                    }
                } else {
                    p.reset();
                }
                return nullptr;
            }

            /**
             * @brief Get all components of the specified type. Must be
             *        a valid subclass of Component.
             * @return Vector with pointers to Component instances.
             * @spicapi
             */
            template<class T>
            std::vector<std::shared_ptr<T>> GetComponents() const {
                // Filter components by type T
                std::vector<std::shared_ptr<T>> result;
                for (const auto& component : components) {
                    auto ptr = std::dynamic_pointer_cast<T>(component);
                    if (ptr) result.push_back(ptr);
                }

                // Recursively add components from child GameObjects
                for (const auto& child : children) {
                    auto childResult = child->GetComponents<T>();
                    result.insert(result.end(), childResult.begin(), childResult.end());
                }

                return result;
            }

            /**
             * @brief Get all components of the specified type from
             *        contained game objects. Must be
             *        a valid subclass of Component.
             * @return Vector with pointers to Component instances.
             * @spicapi
             */
            template <class T>
            std::vector<std::shared_ptr<T>> GetComponentsInChildren() const {
                std::vector<std::shared_ptr<T>> result;
                for (const auto& childComponent : children) {
                    auto childResult = childComponent->GetComponents<T>();
                    result.insert(result.end(), childResult.begin(), childResult.end());
                }
                return result;
            }

            /**
             * @brief Get all components op the specified type from
             *        the parent game object. Must be
             *        a valid subclass of Component.
             * @return Vector with pointers to Component instances.
             * @spicapi
             */
            template <class T>
            std::vector<std::shared_ptr<T>> GetComponentsInParent() const {
                auto p = parent.lock();
                if (p) {
                    return p->template GetComponents<T>();
                } else {
                    p.reset();
                }
                return nullptr;
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

            /**
             * @brief Returns the transform of this GameObject
             * @return A reference to the transform
             * @sharedapi
             */
            spic::Transform& Transform();

            /**
             * @brief Returns a const reference to the transform of this GameObject
             * @return A const reference to the transform
             * @sharedapi
             */
            const spic::Transform& Transform() const;

            /**
             * The parent of this GameObject.
             * @return A weak pointer to the parent.
             * @sharedapi
             */
            std::weak_ptr<GameObject> Parent();

            /**
             * The parent of this GameObject.
             * @param parent A weak pointer to the new parent
             * @sharedapi
             */
            void Parent(std::weak_ptr<GameObject> parent);

            /**
             * Returns a list of children in this GameObject.
             * @return A list of shared pointers to the children.
             * @sharedapi
             */
            const std::vector<std::shared_ptr<GameObject>>& Children() const;

            /**
             * Add a child to the children of this GameObject.
             * @param child the child to add.
             * @sharedapi
             */
            void AddChild(std::shared_ptr<GameObject> child);

            /**
             * Remove a child from the children of this GameObject.
             * @param child the child to remove.
             * @sharedapi
             */
            void RemoveChild(std::shared_ptr<GameObject> child);

            /**
             * Retrieve the name of this GameObject.
             * @return the name of this GameObject.
             * @sharedapi
             */
            const std::string& Name() const;

            /**
             * Retrieve the tag of this GameObject.
             * @return the tag of this GameObject.
             * @sharedapi
             */
            const std::string& Tag() const;

            /**
             * Retrieve the layer of this GameObject.
             * @return the layer of this GameObject.
             * @sharedapi
             */
            int Layer() const;

            /**
             * Retrieve the relative position of this gameobject in relation to its parent.
             * @return the relative position of this gameobject in relation to its parent.
             * @sharedapi
             */
            Point RelativePosition();

        private:
            std::string name;
            std::string tag;
            bool active;
            int layer;

            // Every gameObject has an identifier (id) which gets a value by auto incrementing the static 'idCounter' int
            // This happens in the constructor of GameObject.cpp (id = idCounter++)
            static int idCounter;

            // GameObject id is used to make comparisons to other gameobjects. (See bool GameObject::operator==)
            int id;
            spic::Transform transform;
            std::weak_ptr<GameObject> parent;
            std::vector<std::shared_ptr<GameObject>> children;
            std::vector<std::shared_ptr<Component>> components;

            /**
             * The real function that creates a game object with components in one.
             * Since you can only add normal parameters before variadic ones we used a little redirection and
             * meta programming to be able to pass them in a natural order. E.g. GameObject args first, then a vector
             * of components.
             * @tparam GameObjectType The type of GameObject
             * @tparam GameObjectArgs The argument types for the constructor of type GameObjectType
             * @param comps A vector of components to add to the game object
             * @param args The arguments for the constructor of type GameObjectType
             * @return A shared pointer to a newly created GameObject with optional components
             */
            template<typename GameObjectType, typename... GameObjectArgs>
            static std::shared_ptr<GameObjectType> Create_ComponentsFirst(std::vector<std::shared_ptr<Component>> comps, GameObjectArgs... args) {
                // Create a pointer of the game object
                std::shared_ptr<GameObjectType> pointer = std::make_shared<GameObjectType>(std::forward<GameObjectArgs>(args)...);

                for (const auto &component : comps) {
                    component->GameObject(pointer);
                    pointer->AddComponent(component);
                }

                return pointer;
            }

            /**
             * A redirection trick with metaprogramming to shuffle the order of the arguments when creating a game object.
             * @tparam GameObjectType The type of GameObject
             * @tparam GameObjectArgs The argument types for the constructor of type GameObjectType
             * @param comps A vector of components to add to the game object
             * @param args The arguments for the constructor of type GameObjectType
             * @return A shared pointer to a newly created GameObject with optional components
             */
            template<typename GameObjectType, typename... GameObjectArgsAndComponents, size_t... GameObjectArgIndices>
            static std::shared_ptr<GameObjectType> Create_GameObjectArgsWithIndices(std::tuple<GameObjectArgsAndComponents...> args, std::index_sequence<GameObjectArgIndices...>) {
                auto constexpr ComponentIndex = sizeof...(GameObjectArgsAndComponents) - 1;
                return Create_ComponentsFirst<GameObjectType>(std::get<ComponentIndex>(args), std::get<GameObjectArgIndices>(args)...);
            }
    };

}

#endif // GAMEOBJECT_H_
