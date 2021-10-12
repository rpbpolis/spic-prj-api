#ifndef SPIC_PRJ_API_CD_ENGINE_HPP
#define SPIC_PRJ_API_CD_ENGINE_HPP

#include "Scene.hpp"
#include <stack>

namespace spic {
    class Engine {
    private:
        static Engine instance;
        Engine() = default;

        std::stack<std::shared_ptr<Scene>> scenes;

    public:
        static Engine& Instance();
        Engine(const Engine&) = delete;
        Engine& operator=(const Engine&) = delete;
        Engine(const Engine&&) = delete;
        Engine& operator=(Engine&&) = delete;

        void Start();
        void UpdateGameObjects();
        void RenderActiveScene();
        void PopScene();
        std::shared_ptr<Scene> ActiveScene();
        void ActiveScene(const std::shared_ptr<Scene>& scene);
        void Shutdown();
    };
}

#endif //SPIC_PRJ_API_CD_ENGINE_HPP
