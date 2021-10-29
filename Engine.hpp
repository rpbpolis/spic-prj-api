#ifndef SPIC_PRJ_API_CD_ENGINE_HPP
#define SPIC_PRJ_API_CD_ENGINE_HPP

#include "Config.hpp"
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

        /**
         * @brief Initialize the engine with the given configuration.
         * @param config The engine configuration struct.
         */
        void Init(const spic::Config& config);

        /**
         * @brief Get a modifiable reference to the engine configuration.
         * @return A reference to the engine configuration that you can modify.
         */
        spic::Config& Config();

        void Start();
        void PushScene(const std::shared_ptr<Scene>& scene);
        std::shared_ptr<Scene> PeekScene() const;
        void PopScene();
        void Shutdown();
    };
}

#endif //SPIC_PRJ_API_CD_ENGINE_HPP
