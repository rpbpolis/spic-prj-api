#ifndef SCENE_H_
#define SCENE_H_

#include <vector>
#include <memory>

namespace spic {

    class GameObject;

    /**
     * @brief Class representing a scene which can be rendered by the Camera.
     * @spicapi
     */
    class Scene {
        public:
            Scene() = default;

            Scene(const Scene&) = delete;
            Scene& operator=(const Scene&) = delete;
            Scene(const Scene&&) = delete;
            Scene& operator=(Scene&&) = delete;

            virtual ~Scene() = default;

            /**
             * @brief This function is called by a Camera to render the scene on the engine.
             * @spicapi
             */
            void RenderScene();

            /**
             * @brief This property contains all the Game Object that are contained in this scene.
             * @spicapi
             */
            std::vector<std::shared_ptr<GameObject>>& Contents();

            /**
             * Called when this scene is first created.
             * Use this method to initialize the objects in this scene.
             * @sharedapi
             */
            virtual void OnCreate() {};

            /**
             * Called when this scene is pushed on top of the stack, or when the scene directly above this
             * one is popped from the stack, thus revealing this one.
             * @sharedapi
             */
            virtual void OnActivate();

            /**
             * Called when this scene is popped from the stack.
             * @sharedapi
             */
            virtual void OnDeactivate();

    private:
        std::vector<std::shared_ptr<GameObject>> contents;
    };

}

#endif // SCENE_H_
