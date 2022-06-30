#ifndef DRAG_API_GRAPHICS_H
#define DRAG_API_GRAPHICS_H
#include "Window.h"



namespace DragAPI {
	namespace Graphics {
		enum class RendererAPI {
			None,
			DirectX
		};

		class Renderer {
		public:
			RendererAPI m_API;
			Window* m_TargetWindow;


			Renderer();
			~Renderer();


			static Renderer* Create(RendererAPI api, Window* targetWindow);
		};
	}
}


#endif