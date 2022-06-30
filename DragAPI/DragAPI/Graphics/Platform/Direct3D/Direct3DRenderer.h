#pragma once
#include <string>
#include <vector>


#include "../../../Debugging/Debug.h"

#include "../../Renderer.h"
#include "../Windows/WindowsWindow.h"

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
	namespace Graphics {


		class Direct3DBuffer : public Buffer {

		};

		class Direct3DVertexBuffer : public VertexBuffer {

		};
		class Direct3DIndexBuffer : public IndexBuffer {

		};


		class Direct3DShader : public Shader {

		};

		class Direct3DRenderer : public Renderer {
		public:
			WindowsWindow* m_TargetWindow;
			ID3D11Device* m_pDevice;
			IDXGISwapChain* m_pSwapChain;
			ID3D11DeviceContext* m_pContext;


			Direct3DRenderer(Window* targetWindow);
			Direct3DRenderer(const Direct3DRenderer& other) = delete;
			~Direct3DRenderer();

			virtual void Clear(DragAPI::Color color) override;

			virtual void Swap() override;
		};
	}
}