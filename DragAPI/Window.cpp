#include "Window.h"

#include <d3d9.h>
#include <d3d10_1.h>
#include <d3d11.h>
#include <d3d12.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3d10_1.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3d12.lib")

DragAPI::Window::Window()
{
	h_WindowHandle = NULL;
	ZeroMemory(&this->rect, sizeof(this->rect));
	ZeroMemory(&this->wcex_Registered, sizeof(this->wcex_Registered));
}

DragAPI::Window::Window(Window* parent) : DragAPI::Window::Window()
{

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
