#ifndef SPIC_PRJ_API_CD_ENGINE_HPP
#define SPIC_PRJ_API_CD_ENGINE_HPP

#include "EngineConfig.hpp"
#include "EventBus.hpp"
#include "PhysicsManager.hpp"
#include "Scene.hpp"
#include <AudioManager.hpp>
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

        Engine();
        ~Engine();

        EngineConfig config;

        std::stack<std::shared_ptr<Scene>> scenes;
        std::unique_ptr<spic::Renderer> renderer;
        std::unique_ptr<spic::Input::InputHandler> inputHandler;
        std::unique_ptr<spic::EventBus> eventBus;
        std::unique_ptr<spic::PhysicsManager> physicsManager;
        std::unique_ptr<spic::AudioManager> audioManager;

        bool isRunning;
        int fps;
        bool showFps;
        bool showColliders;

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
        std::unique_ptr<spic::EventBus>& EventBus();
        const std::unique_ptr<spic::PhysicsManager>& PhysicsManager() const;
        const std::unique_ptr<spic::AudioManager>& AudioManager() const;

        void ToggleFps();
        void ToggleColliders();
    };
}

#endif // SPIC_PRJ_API_CD_ENGINE_HPP
