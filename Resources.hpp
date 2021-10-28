#ifndef RESOURCES_H_
#define RESOURCES_H_

#include "GameObject.hpp"
#include <memory>

namespace spic {
	class Resources {
	public:
		template<class T, std::enable_if_t<std::is_base_of_v<GameObject, T>>* = nullptr>
		static std::shared_ptr<T> CreateGameObject(const std::string& name);

		static std::vector<std::shared_ptr<GameObject>> GameObjects;
	};
}

#endif // RESOURCES_H_