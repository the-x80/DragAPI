#ifndef DRAG_API_WINDOW_H
#define DRAG_API_WINDOW_H

#include <array>
#include <vector>
#include <string>

#ifndef _WINDOWS_
#include <Windows.h>
#endif
#include "../Exceptions/Exceptions.h"
#include "../Data Types/Rect.h"

#include "GraphicsRenderingEngine.h"
#include "../Application/Application.h"

//TODO Set the window class to be a wrapper around OS specific window classes

namespace DragAPI {
	enum class WindowMode {
		Windowed,
		WindowedFullscreen,
		Fullscreen
	};

	class Window {
	protected:
		Rect<int> m_WindowRect;

		Window():m_WindowRect() {};
		~Window() {};
	public:
		static Window* Create(const wchar_t* tittle, Rect<int> rect);

		virtual void Initialize(const wchar_t* tittle, Rect<int> rect) = 0;
		virtual void Destroy() = 0;

		virtual void Show() = 0;
		virtual void Hide() = 0;

		virtual void Process() = 0;
	};

	namespace Exceptions {
		class WindowException : public Exception {
		private:
			Window* m_Window;
		public:
			WindowException() {}
			WindowException(Window* window) : m_Window(window) {}

			const char* what() const override {
				return "";
			}
		};
	}
}

#endif