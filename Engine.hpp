#ifndef SPIC_PRJ_API_CD_ENGINE_HPP
#define SPIC_PRJ_API_CD_ENGINE_HPP

#include "EngineConfig.hpp"
#include "Scene.hpp"
#include <memory>
#include <stack>

namespace spic {

    class Renderer;

    namespace Input {
        class InputHandler;
    }

    /**
     * @brief The engine class responsible for the game loop.
     * @sharedapi
     */
    class Engine {
    private:
        static Engine instance;

        Engine() = default;
        ~Engine();

        EngineConfig config;

        std::stack<std::shared_ptr<Scene>> scenes;
        std::unique_ptr<spic::Renderer> renderer;
        std::unique_ptr<spic::Input::InputHandler> inputHandler;

        bool isRunning;
        int fps;

        void UpdateBehaviourScripts() const;
        void Render();

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
        void Init(const spic::EngineConfig& config);

        /**
         * @brief Get a modifiable reference to the engine configuration.
         * @return A reference to the engine configuration that you can modify.
         */
        spic::EngineConfig& Config();

        void Start();
        void PushScene(const std::shared_ptr<Scene>& scene);
        std::shared_ptr<Scene> PeekScene() const;
        void PopScene();
        void Shutdown();

        const std::unique_ptr<spic::Renderer>& Renderer() const;
        const std::unique_ptr<spic::Input::InputHandler>& InputHandler() const;
    };
}

#endif //SPIC_PRJ_API_CD_ENGINE_HPP
