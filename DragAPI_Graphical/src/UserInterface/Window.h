#pragma once
#include <DragAPI\Core.h>
namespace DragAPI::UI {

	class Window {
	public:
		virtual ~Window() {};

		static Window* Create(
			const char* pCaption,
			const DragAPI::rect_u16& rClientRect
		);//See what can be implemented here. Keep the parameter list as brief as possible
	};
}