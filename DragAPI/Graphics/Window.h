#ifndef DRAG_API_WINDOW_H
#define DRAG_API_WINDOW_H

#ifndef _WINDOWS_
#include <Windows.h>
#endif
#include "../Exceptions/Exceptions.h"
#include "../Data Types/Rect.h"

#include "GraphicsRenderingEngine.h"
#include "../Application/Application.h"

//TODO Set the window class to be a wrapper around OS specific window classes

namespace DragAPI {
	template <class T> class BaseWindow;

	namespace Exceptions {
		template <class T> class WindowException : public Exception {
		private:
			BaseWindow<T>* window;
		public:
			WindowException() noexcept : window(nullptr), Exception() {};

			const char* what() const override{

			}
		};
	}



	enum class WindowMode {
		Windowed,
		WindowedFullscreen,
		Fullscreen
	};
	


	template <class T> class BaseWindow {
	private:
	protected:
		HWND m_hwnd;
		MSG msg;
		RectInt rect;
		char* cstr_Title;
	public:
		static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
		{
			T* pThis = NULL;

			if (uMsg == WM_NCCREATE)
			{
				CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam;
				pThis = (T*)pCreate->lpCreateParams;
				SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pThis);

				pThis->m_hwnd = hwnd;
			}
			else
			{
				pThis = (T*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
			}

			switch (uMsg) {
			default:
				break;
			}

			if (pThis != nullptr)
			{
				return pThis->HandleMessage(uMsg, wParam, lParam);
			}
			else
			{
				return DefWindowProc(hwnd, uMsg, wParam, lParam);
			}
		}


		BaseWindow() : m_hwnd(NULL), msg(), rect() {};
		BOOL Create(PCWSTR lpWindowName, DWORD dwStyle, DWORD dwExStyle = 0, int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, int nWidth = CW_USEDEFAULT, int nHeight = CW_USEDEFAULT, HWND hWndParent = 0, HMENU hMenu = 0)
		{
			WNDCLASS wc = { 0 };

			wc.lpfnWndProc = T::WindowProc;
			wc.hInstance = GetModuleHandle(NULL);
			wc.lpszClassName = ClassName();

			ATOM a_RegClass = RegisterClass(&wc);
			if (a_RegClass == 0) {
				//Registering of class has failed.
			}

			m_hwnd = CreateWindowEx(
				dwExStyle, ClassName(), lpWindowName, dwStyle, x, y,
				nWidth, nHeight, hWndParent, hMenu, GetModuleHandle(NULL), this
			);

			if (this->m_hwnd == NULL) {
				//Something went wrong while creating a window
				//Handle the error accordingly.
			}

			return (m_hwnd ? TRUE : FALSE);
		}
		BOOL Destroy() { return DestroyWindow(this->m_hwnd); }

		void SetTitle(const char* text){
			SetWindowText(this->m_hwnd, text);

			if (this->cstr_Title != nullptr) {
				delete[] this->cstr_Title;
			}
			this->cstr_Title = new char[strlen(text) + 1];
			strcpy(this->cstr_Title, text);
		}

		inline HWND WindowHandle() const { return m_hwnd; }

		BOOL MessageGet() {
			return GetMessage(&this->msg, this->WindowHandle(), 0, 0);
		}
		BOOL MessageTranslate() {
			return TranslateMessage(&this->msg);
		}
		BOOL MessageDispatch() {
			return DispatchMessage(&this->msg);
		}

		RectInt ClientRect() {};
		RectInt ClientRect(RectInt r) {};
	protected:
		virtual PCWSTR  ClassName() const = 0;
		virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;
	};

	class Window : public BaseWindow<Window> {
	public:
		PCWSTR  ClassName() const { return L"Default Window Class"; }
		LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

		Window();
		
		void Show(bool value);
	};
}

#endif