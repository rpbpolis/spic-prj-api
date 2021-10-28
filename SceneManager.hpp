#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

#include <memory>
#include "Scene.hpp"
#include <string>

namespace spic {
	class SceneManager {
	public:
		static std::shared_ptr<Scene> CreateScene();
		static void LoadScene(const std::string& name);
		static void UnloadScene(const std::string& name);
		static std::shared_ptr<Scene> GetActiveScene;
		static void SetActiveScene(const std::string& name);
		static void MoveGameObject(std::shared_ptr<GameObject> object, std::shared_ptr<Scene> scene);
	private:
	#include "SceneManager_private.hpp"
	};
}

#endif // SCENEMANAGER_H_