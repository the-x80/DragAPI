#pragma once
#ifdef _WIN32
#include "../../../DragAPI.Core.h"
#include "../../../Event System/EventSystem.h"
#include "../../Window.h"

#include <functional>
#include <vector>

#include <Windows.h>



const char* winmsg2str_impl(int id);


namespace DragAPI {
	LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	

	class WindowsWindow : public Window {
	public:
		HWND m_Handle;
		WNDCLASSEX m_WindowClass;

		std::wstring m_Tittle;

        DragAPI::Events::EventDispatcher* m_EventDispatcher;

		WindowsWindow(DragAPI::Events::EventDispatcher* dispatcher);

		~WindowsWindow();

		void Initialize(const wchar_t* tittle, Rect<int> rect) override;

		virtual void Destroy() override;

		virtual void Show() override;
		virtual void Hide() override;

		virtual void Process() override;

		virtual void SetEventDispatcher(DragAPI::Events::EventDispatcher* e) override;

		std::wstring ToWString() {
			return std::wstring(this->m_Tittle);
		}
	};


	


	
}
#endif