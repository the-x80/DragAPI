
#include <array>
#include <vector>

#include <d3d11.h>
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>


#include "GraphicsRenderingEngine.h"





namespace DragAPI {
	namespace Graphics {
		RenderingEngine::RenderingEngine():
			renderers()
		{
		}
		RenderingEngine::~RenderingEngine()
		{
		}
	};
};