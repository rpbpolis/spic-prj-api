#ifndef SCENE_H_
#define SCENE_H_

#include "GameObject.hpp"
#include <vector>
#include <memory>

#if __has_include("Scene_includes.hpp")
#include "Scene_includes.hpp"
#endif

namespace spic {

    /**
     * @brief Class representing a scene which can be rendered by the Camera.
     */
    class Scene {
        public:
            /**
             * @brief This function is called by a Camera to render the scene on the engine.
             */
            void RenderScene();

            const std::vector<std::shared_ptr<GameObject>>& Contents();

    private:
#if __has_include("Scene_private.hpp")
#include "Scene_private.hpp"
#endif
    };

}

#endif // SCENE_H_