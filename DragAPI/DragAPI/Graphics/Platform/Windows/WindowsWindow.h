#pragma once
#ifdef _WIN32
#include "../../../DragAPI.Core.h"
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
	LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		switch (msg) {
		case WM_CREATE:
			OutputDebugString(TEXT("Window created"));
			break;
		default:
			break;
		}
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}

	class WindowsWindow : public Window {
	public:
		HANDLE m_Handle;
		WNDCLASSEX m_WindowClass;


		WindowsWindow():
			m_Handle(INVALID_HANDLE_VALUE),
			m_WindowClass()
		{
			

		}

		~WindowsWindow() {

		}

		void Initialize(const wchar_t* tittle, Rect<int> rect) override {
			m_WindowClass.cbSize = sizeof(m_WindowClass);
			m_WindowClass.style = CS_HREDRAW | CS_VREDRAW;
			m_WindowClass.lpfnWndProc = DragAPI::WndProc;
			m_WindowClass.cbClsExtra = 0;
			m_WindowClass.cbWndExtra = 0;
			m_WindowClass.hInstance = GetModuleHandle(NULL);
			m_WindowClass.hIcon = NULL;
			m_WindowClass.hCursor = NULL;
			m_WindowClass.hbrBackground = NULL;
			m_WindowClass.lpszMenuName = NULL;
			m_WindowClass.lpszClassName = TEXT("DragAPI::WindowClass");
			m_WindowClass.hIconSm = NULL;

			ATOM l_RegisterClassResult = RegisterClassEx(&this->m_WindowClass);
			DRAG_API_ASSERT(l_RegisterClassResult != 0, "RegisterClassEx failed. GetLastError = %d", GetLastError());

			this->m_Handle = CreateWindowEx(WS_EX_ACCEPTFILES, m_WindowClass.lpszClassName, tittle, WS_OVERLAPPEDWINDOW | WS_CAPTION, rect.xMin, rect.yMin, rect.Width(), rect.Height(), NULL, NULL, m_WindowClass.hInstance, NULL);
			DRAG_API_ASSERT(this->m_Handle != NULL, "CreateWindowEx failed. GetLastError = %d", GetLastError());
		}

		void Destroy() override {
			DestroyWindow((HWND)this->m_Handle);
		}

		void Show() override {
			ShowWindow((HWND)this->m_Handle, SW_SHOWNORMAL);
		}
		void Hide() override {
			ShowWindow((HWND)this->m_Handle, SW_HIDE);
		}

		void Process() override {
			MSG msg;
			ZeroMemory(&msg, sizeof(msg));
			while (::PeekMessage(&msg, (HWND)this->m_Handle, 0, 0, PM_REMOVE)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
	};


	Window* Window::Create(const wchar_t* tittle, Rect<int> rect) {
		Window* retVal = new WindowsWindow();
		retVal->Initialize(tittle, rect);
		return retVal;
	}
}
#endif