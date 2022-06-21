#pragma once
#ifdef _WIN32
#include "../../Window.h"

#include <functional>
#include <vector>

#include <Windows.h>

#include <d3d9.h>
#include <d3d10_1.h>
#include <d3d11.h>
#include <d3d12.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3d10_1.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3d12.lib")


namespace DragAPI {
	class WindowsWindow : public Window {
	public:
		HANDLE m_Handle;


		WindowsWindow():
		m_Handle(INVALID_HANDLE_VALUE)
		{

		}

		~WindowsWindow() {

		}

		void Initialize() override {

		}

		void Destroy() override {

		}

		void Show() override {

		}
		void Hide() override {

		}
	};


	Window* Window::Create(const char* tittle, Rect<int> rect) {
		return new WindowsWindow();
	}
}
#endif