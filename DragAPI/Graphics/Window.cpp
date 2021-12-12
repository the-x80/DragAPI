#include <vector>

#include "Window.h"
#include "../Data Types/String.h"

#include <d3d9.h>
#include <d3d10_1.h>
#include <d3d11.h>
#include <d3d12.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3d10_1.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3d12.lib")

static std::vector<DragAPI::Window*> windowPool;

DragAPI::Window* GetWindowByHandle(HWND handle) {
	for (int i = 0; i < windowPool.size(); i++) {
		if (windowPool[i]->GetHandle() == handle) {
			return windowPool[i];
		}
	}
	return nullptr;
}

LRESULT CALLBACK DefaultWindowProc(
	_In_ HWND   hwnd,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
) {
	DragAPI::Window* currentWindow = GetWindowByHandle(hwnd);
	switch (uMsg) {
	case WM_CREATE:

		return 0;
	case WM_PAINT:

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}



DragAPI::Window::Window()
{
	h_WindowHandle = NULL;
	ZeroMemory(&this->rect, sizeof(this->rect));
	ZeroMemory(&this->wcex_Registered, sizeof(this->wcex_Registered));

	this->wcex_Registered.cbSize = sizeof(this->wcex_Registered);

	windowPool.push_back(this);
}

DragAPI::Window::Window(Window* parent) : DragAPI::Window::Window()
{
}

void DragAPI::Window::Create()
{
	HINSTANCE hInstance = GetModuleHandle(NULL);
	this->Create(hInstance);
}

void DragAPI::Window::Create(HINSTANCE hInstance)
{
	wcex_Registered.cbSize = sizeof(WNDCLASSEX);
	wcex_Registered.style = CS_HREDRAW | CS_VREDRAW;
	wcex_Registered.lpfnWndProc = DefaultWindowProc;
	wcex_Registered.cbClsExtra = 0;
	wcex_Registered.cbWndExtra = 0;
	wcex_Registered.hInstance = hInstance;
	wcex_Registered.hIcon = NULL;
	wcex_Registered.hCursor = NULL;
	wcex_Registered.hbrBackground = NULL;
	wcex_Registered.lpszMenuName = NULL;
	wcex_Registered.lpszClassName = L"DefaultWindowClass";
	wcex_Registered.hIconSm = NULL;

	if (RegisterClassEx(&this->wcex_Registered) == FALSE) {
		char debugMessage[512] = "";
		sprintf_s(debugMessage, "Unable to register class\nGetLastError returned %d", GetLastError());
		OutputDebugStringA(debugMessage);
	}


	this->h_WindowHandle = CreateWindow(L"DefaultWindowClass", L"", WS_BORDER, 0, 0, 800, 600, NULL, NULL, hInstance, NULL);
	if (this->h_WindowHandle == NULL) {
		char debugMessage[512] = "";
		sprintf_s(debugMessage, "Unable to create window\nGetLastError returned %d", GetLastError());
		OutputDebugStringA(debugMessage);
	}
}

void DragAPI::Window::Show(bool value)
{
	//TODO Implement error checking here.
	ShowWindow(this->h_WindowHandle, value);
}

HWND DragAPI::Window::GetHandle() const
{
	return this->h_WindowHandle;
}

void DragAPI::Window::Paint()
{
}

void DragAPI::Window::SetRect(long x, long y, long w, long h)
{
	this->rect.left = x;
	this->rect.top = y;
	this->rect.right = x+w;
	this->rect.bottom = y+h;
}
