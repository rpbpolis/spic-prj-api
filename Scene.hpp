#ifndef SCENE_H_
#define SCENE_H_

#include "GameObject.hpp"

namespace spic {

    /**
     * @brief Class representing a scene which can be rendered by the Camera.
     */
    class Scene {
        public:
            /**
             * @brief This property contains all the Game Object that are contained in this scene.
             * @spicapi
             */
            std::vector<std::shared_ptr<GameObject>> contents;
    };

}

#endif // SCENE_H_