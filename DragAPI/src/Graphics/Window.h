#ifndef DRAG_API_WINDOW_H
#define DRAG_API_WINDOW_H

#include <array>
#include <vector>
#include <string>
#include "../Exceptions/Exceptions.h"
#include "../Data Types/Rect.h"

#include "../Event System/EventSystem.h"

//TODO Set the window class to be a wrapper around OS specific window classes

namespace DragAPI {
	class Window {
	protected:
		Rect<int> m_WindowRect;

		Window():m_WindowRect() {};
		
	public:
		~Window() {};


		static Window* Create(const wchar_t* tittle, Rect<int> rect, DragAPI::Events::EventDispatcher* dispatcher);

		virtual void Initialize(const wchar_t* tittle, Rect<int> rect) = 0;
		virtual void Destroy() = 0;

		virtual void Show() = 0;
		virtual void Hide() = 0;

		virtual void Process() = 0;

		virtual void SetEventDispatcher(DragAPI::Events::EventDispatcher* e) = 0;
	};

	namespace Exceptions {
		class WindowException : public Exception {
		private:
			Window* m_Window;
		public:
			WindowException() :m_Window(nullptr){}
			WindowException(Window* window) : m_Window(window) {}
			~WindowException() {};

			const char* what() const override {
				return "";
			}
		};
	}
}

#endif