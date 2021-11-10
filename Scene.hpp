#ifndef SCENE_H_
#define SCENE_H_

#include <vector>
#include <memory>

#if __has_include("Scene_includes.hpp")
#include "Scene_includes.hpp"
#endif

namespace spic {

    class GameObject;

    /**
     * @brief Class representing a scene which can be rendered by the Camera.
     * @spicapi
     */
    class Scene {
        public:
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

    private:
#if __has_include("Scene_private.hpp")
#include "Scene_private.hpp"
#endif
    };

}

#endif // SCENE_H_