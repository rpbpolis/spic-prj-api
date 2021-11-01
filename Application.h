#pragma once

namespace spic
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		virtual void OnUpdate();

	protected:
	#include "Application_protected.hpp"
	};

	Application* CreateApplication();
}
