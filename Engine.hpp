#ifndef SPIC_PRJ_API_CD_ENGINE_HPP
#define SPIC_PRJ_API_CD_ENGINE_HPP

#include "Scene.hpp"

#if __has_include("Engine_includes.hpp")
#include "Engine_includes.hpp"
#endif

namespace spic {
    class Engine {
    private:
        static Engine instance;
        Engine() = default;

#if __has_include("Engine_private.hpp")
#include "Engine_private.hpp"
#endif

    public:
        static Engine& Instance();
        Engine(const Engine&) = delete;
        Engine& operator=(const Engine&) = delete;
        Engine(const Engine&&) = delete;
        Engine& operator=(Engine&&) = delete;

        void Start();
        void PushScene(const std::shared_ptr<Scene>& scene);
        std::shared_ptr<Scene> PeekScene() const;
        void PopScene();
        void Shutdown();
    };
}

#endif //SPIC_PRJ_API_CD_ENGINE_HPP
