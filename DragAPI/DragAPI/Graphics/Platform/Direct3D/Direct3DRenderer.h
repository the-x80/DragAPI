#pragma once
#include <array>
#include <cmath>
#include <string>
#include <vector>


#include "../../../Debugging/Debug.h"

#include "../../Renderer.h"
#include "../Windows/WindowsWindow.h"

#include <Windows.h>
#include <DirectXMath.h>


#include <d3d9.h>
#include <d3d9caps.h>

#include <d3d10_1.h>

#include <d3d11.h>
#include <d3d12.h>
#include <d3d12shader.h>
#include <d3d12video.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3d10_1.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3d12.lib")

#include <d3dcompiler.h>
#pragma comment(lib, "d3dcompiler.lib")

#include <wrl.h>


namespace DragAPI {
	namespace Graphics {
		class Direct3DRenderer;

		class Direct3DBuffer : public Buffer {
		public:
			ID3D11Buffer* m_Buffer;
		};

		class Direct3DVertexBuffer : public VertexBuffer {
		public:
			Direct3DRenderer* m_Renderer;
			ID3D11Buffer* m_pVertexBuffer;
			size_t m_Stride;

			Direct3DVertexBuffer(Direct3DRenderer* renderer, size_t buffSize, size_t stride, void* pData);
			~Direct3DVertexBuffer();

			virtual void Bind() override;
		};
		class Direct3DIndexBuffer : public IndexBuffer {
		public:
			Direct3DRenderer* m_Renderer;
			ID3D11Buffer* m_pIndexBuffer;
			size_t m_Stride;

			Direct3DIndexBuffer(Direct3DRenderer* r, size_t buffSize, size_t stride, void* pData);
			~Direct3DIndexBuffer();

			virtual void Bind() override;
		};

		class Direct3DShader : public Shader {
		public:
			ID3DBlob* m_pShaderBlob;

			Direct3DShader();
			~Direct3DShader();
		};
		class Direct3DVertexShader : public VertexShader, public Direct3DShader {
		public:
			Direct3DVertexShader();
			~Direct3DVertexShader();

			static Direct3DVertexShader* FromSource(Direct3DRenderer* r, const char* vs_source);
		};
		class Direct3DPixelShader : public PixelShader, public Direct3DShader {
		public:
			Direct3DPixelShader();
			~Direct3DPixelShader();

			static Direct3DPixelShader* FromSource(Direct3DRenderer* r, const char* ps_source);
		};
		

		class Direct3DRenderContext : public RenderContext{
		public:
			ID3D11DeviceContext* m_pContext;

			Direct3DRenderContext(ID3D11DeviceContext* con);
			~Direct3DRenderContext();
		};

		class Direct3DRenderer : public Renderer {
		public:
			WindowsWindow*	m_TargetWindow;
			Microsoft::WRL::ComPtr < ID3D11Device >				m_pDevice;
			Microsoft::WRL::ComPtr < IDXGISwapChain >			m_pSwapChain;
			Direct3DRenderContext*								m_pContext;
			Microsoft::WRL::ComPtr < ID3D11RenderTargetView >	m_pRenderTarget;


			Direct3DRenderer(Window* targetWindow);
			Direct3DRenderer(const Direct3DRenderer& other) = delete;
			~Direct3DRenderer();

			virtual void Clear(DragAPI::Color color) override;

			virtual void DrawLine2D(DragAPI::Vector<float, 2> p1, DragAPI::Vector<float, 2> p2, DragAPI::Color color) override;

			virtual void Swap() override;

			virtual RenderContext* GetRenderContext() override { return m_pContext; }
		};
	}
}