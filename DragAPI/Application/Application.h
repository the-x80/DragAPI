#pragma once
#ifndef DRAG_API_APPLICATION_H
#define DRAG_API_APPLICATION_H

#include "../Graphics/GraphicsRenderingEngine.h"

namespace DragAPI {
	class Application {
	private:
		static Application current;

		
	public:
		enum class Platform {
			Windows,
			Linux,
			Android,
			Other
		};
		enum class Architecture {
			x86,
			x64,
			ARM,
			RISC
		};

		GraphicsRenderingEngine* graphicsEngine;


		Platform platform;
		Architecture architecture;


		Application();

		inline static Application& Current() { return Application::current; };

		void ProcessFrame();
	};
}
#endif