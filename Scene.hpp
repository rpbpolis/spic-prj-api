#ifndef SCENE_H_
#define SCENE_H_

#include "GameObject.hpp"

namespace spic {

    /**
     * @brief Class representing a scene which can be rendered by the Camera.
     */
    class Scene {
        public:

            Scene();
            /**
             * @brief This method is called by a Camera to render the scene on the engine.
             */
            void RenderScene();

            /**
             * @brief This method is called when creating the scene, should be overridden
             */
            virtual void OnCreate() = 0;
            /**
             * @brief This method is called when destroying the scene, should be overridden
             */
            virtual void OnDestroy() = 0;
            /**
             * @brief This method is called when loading the scene, should be overridden
             */
            virtual void OnLoad() = 0;
            /**
             * @brief This method is called when unloading the scene, should be overridden
             */
            virtual void OnUnload() = 0;
            /**
             * @brief This method is called when activating the scene, should be overridden
             */
            virtual void OnActivate() = 0;
            /**
             * @brief This method is called when deactivating the scene, should be overridden
             */
            virtual void OnDeactivate() = 0;
            /**
             * @brief This method is called when the scene needs to be updated
             */
            virtual void Update() = 0;
            

        private:
        #include "Scene_private.hpp"

        protected:
        #include "Scene_protected.hpp"
    };

}

#endif // SCENE_H_