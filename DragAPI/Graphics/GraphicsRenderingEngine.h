#pragma once
#ifndef DRAG_API_GRAPHICS_RENDERING_ENGINE_H
#define DRAG_API_GRAPHICS_RENDERING_ENGINE_H
#include <vector>

#include <Windows.h>
#include <d3d11.h>
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")



namespace DragAPI {
	class GraphicsRenderingEngine {
	private:
		ID3D11Device* pDevice;
		IDXGISwapChain* pSwapChain;
		ID3D11DeviceContext* pContext;

		IDXGIFactory1* pFactory;

		std::vector<IDXGIAdapter*>* pAdapters;
	public:
		GraphicsRenderingEngine();

		void Create(HWND hWnd);
		void Destroy();
	};
}

#endif