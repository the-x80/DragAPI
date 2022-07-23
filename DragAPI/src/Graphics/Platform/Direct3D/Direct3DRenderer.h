#pragma once
#include <array>
#include <cmath>
#include <string>
#include <vector>


#include <Windows.h>
#include <DirectXMath.h>

#include <dxgi.h>

#include <d3d9.h>
#include <d3d9caps.h>

#include <d3d10_1.h>

#include <d3d11.h>
#include <d3d11_1.h>
#include <d3d11_2.h>
#include <d3d11_3.h>
#include <d3d11_4.h>
#include <d3d11sdklayers.h>
#include <d3d11shader.h>


#include <d3d12.h>
#include <d3d12shader.h>
#include <d3d12video.h>

#pragma comment(lib, "DXGI.lib")

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3d10_1.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3d12.lib")

#include <d3dcompiler.h>
#pragma comment(lib, "d3dcompiler.lib")

//This shit is pretty much done as far as the basic drawing to the screen goes.
//More advanced tehniques will come shortly



namespace DragAPI {
	namespace Graphics {
		//TODO: Implement each D3D API separately and create an abstracted class for Direct3D
#pragma region Unused code. Kept for reference
		/*
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
		class Direct3DConstantBuffer : public ConstantBuffer {
		public:
			Direct3DRenderer* m_Renderer;
			ID3D11Buffer* m_Buffer;

			Direct3DConstantBuffer(Direct3DRenderer* r, size_t buffSize, void* pData);
			~Direct3DConstantBuffer();

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

		class Direct3DRenderer : public RendererAPI {
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

			virtual void Swap() override;

			virtual void DrawIndexed() override;

			virtual RenderContext* GetRenderContext() override { return m_pContext; }
		};
		*/
#pragma endregion



		namespace D3D9 {
			
		}
		namespace D3D10 {

		}
		namespace D3D11 {
			class RendererAPI;
			
			class VertexBuffer : public DragAPI::Graphics::VertexBuffer {
			public:
				ID3D11Buffer* m_pBuffer;
				UINT m_nStride;
				

				VertexBuffer();//The default ctor should do nothing
				VertexBuffer(ID3D11Buffer* pBuffer, UINT nStride);
				~VertexBuffer();

				void Release();
			};

			class IndexBuffer : public DragAPI::Graphics::IndexBuffer {
			public:
				ID3D11Buffer* m_pBuffer;

				IndexBuffer();
				
				~IndexBuffer();

				void Release();

				void SetData(void* pData, size_t nSize);
			private:
				size_t* m_pRefCount;
				RendererAPI* m_pRenderer;

			};

			class ConstantBuffer : public DragAPI::Graphics::ConstantBuffer {
			public:
				ID3D11Buffer* m_pBuffer;

				ConstantBuffer();
				~ConstantBuffer();

				void Release();
			};

			class InputLayout : public DragAPI::Graphics::InputLayout{
			public:
				ID3D11InputLayout* m_pInputLayout;

				InputLayout();
				InputLayout(ID3D11InputLayout* pInputLayout);
				~InputLayout();
			};

			class VertexShader : public DragAPI::Graphics::VertexShader {
			public:
				ID3D11VertexShader* m_pVertexShader;

				//Theese two will be replaced by a object of some sort in the future most likely.
				//It will be done when custom shader compilation is implemented
				char* m_pByteCode;
				size_t m_nByteCodeSize;
				

				VertexShader();
				VertexShader(ID3D11VertexShader* pVertShader, const char* pByteCode, size_t nByteCodeSize);
				~VertexShader();

				void Release();
			};
			class PixelShader : public DragAPI::Graphics::PixelShader{
			public:
				ID3D11PixelShader* m_pPixelShader;

				//Theese two will be replaced by a object of some sort in the future most likely.
				//It will be done when custom shader compilation is implemented
				char* m_pByteCode;
				size_t m_nByteCodeSize;

				PixelShader();
				PixelShader(ID3D11PixelShader* pPixelShader, const char* pByteCode, size_t nByteCodeSize);
				~PixelShader();
			};

			class IRenderTargetView : public DragAPI::Graphics::IRenderTargetView {
			public:
				ID3D11RenderTargetView* m_pRenderTargetView;

				IRenderTargetView();
				IRenderTargetView(ID3D11RenderTargetView* pRTV);
				~IRenderTargetView();
			};
			
			class IAdapter : public DragAPI::Graphics::IAdapter {
			public:
				IDXGIAdapter* m_pAdapter;

				IAdapter();
				~IAdapter();
			};
			class ISwapChain : public DragAPI::Graphics::ISwapChain {
			public:
				IDXGISwapChain* m_pSwapChain;

				ISwapChain();
				ISwapChain(IDXGISwapChain* pSwapChain);
				~ISwapChain();

				virtual void Present() override;
			};
			class IFactory : public DragAPI::Graphics::IFactory {
			public:
				IDXGIFactory2* m_pFactory;

				IFactory();
				~IFactory();
				
				virtual void CreateSwapChain(
					DragAPI::Graphics::IDevice* pDevice,
					DragAPI::Window* pWindow,
					DragAPI::Graphics::ISwapChain** ppSwapChain
				) override;
				
			};
			class IDevice : public DragAPI::Graphics::IDevice {
			public:
				ID3D11Device* m_pDevice;

				IDevice();
				IDevice(ID3D11Device* pDevice);
				~IDevice();

				virtual void CreateSwapChain(DragAPI::Window* pWindow, DragAPI::Graphics::ISwapChain** ppSwapChain) override;

				virtual void CreateVertexBuffer(
					BufferUsage usage,
					CPUAccessFlag accessFlag,
					size_t buffSize,
					size_t stride,
					void* pData,
					DragAPI::Graphics::VertexBuffer** ppVertexBuffer
				) override;

				virtual void CreateIndexBuffer(
					BufferUsage usage,
					CPUAccessFlag accessFlag,
					size_t buffSize,
					size_t stride,
					void* pData,
					DragAPI::Graphics::IndexBuffer** ppIndexBuffer
				) override;

				virtual void CreateConstantBuffer(
					BufferUsage usage,
					CPUAccessFlag accessFlag,
					size_t buffSize,
					size_t stride,
					void* pData,
					DragAPI::Graphics::ConstantBuffer** ppConstantBuffer
				) override;

				virtual void CreateInputLayout(
					DragAPI::Graphics::InputElement* pInputElements,
					size_t nNumInputElements,
					DragAPI::Graphics::VertexShader* pVertShader,
					DragAPI::Graphics::InputLayout** ppInputLayout
				) override;

				virtual void CreateVertexShader(
					const char* pByteCode, 
					size_t nByteCodeSize, 
					DragAPI::Graphics::VertexShader** ppVertShader
				) override;

				virtual void CreatePixelShader(
					const char* pByteCode, 
					size_t nByteCodeSize, 
					DragAPI::Graphics::PixelShader** ppPixelShader
				) override;



				virtual void CreateRenderTargetView(DragAPI::Graphics::ISwapChain* pSwap, DragAPI::Graphics::IRenderTargetView** ppRTV) override;
			};
			class IDeviceContext : public DragAPI::Graphics::IDeviceContext {
			public:
				ID3D11DeviceContext* m_pDeviceContext;

				IDeviceContext();
				IDeviceContext(ID3D11DeviceContext* pDevContext);
				~IDeviceContext();

				virtual void IASetPrimitiveTopology(
					DragAPI::Graphics::PrimitiveTopologyType type
				);

				virtual void IASetVertexBuffer(
					size_t nInputSlot,
					DragAPI::Graphics::VertexBuffer* pVertexBuffer
				) override;

				virtual void IASetVertexBuffers(
					size_t nInputSlot,
					size_t nBufferSize,
					DragAPI::Graphics::VertexBuffer** ppVertexBuffer
				) override;

				virtual void IASetIndexBuffer(
					DragAPI::Graphics::IndexBuffer* pIndexBuffer
				) override;

				virtual void IASetInputLayout(DragAPI::Graphics::InputLayout* pInputLayout) override;

				virtual void VSSetShader(DragAPI::Graphics::VertexShader* pShader) override;

				virtual void PSSetShader(DragAPI::Graphics::PixelShader* pShader) override;


				virtual void OMSetRenderTarget(DragAPI::Graphics::IRenderTargetView* pRTV) override;


				virtual void RSSetViewport(
					float nWidth,
					float nHeight,
					float nMinDepth,
					float nMaxDepth,
					float nTopLeftX,
					float nTopLeftY
				) override;


				virtual void ClearRenderTargetView(DragAPI::Graphics::IRenderTargetView* pRTV, DragAPI::Color color) override;

				virtual void Draw(size_t nVertCount, size_t nStartIndex = 0) override;
				virtual void DrawIndexed(size_t nIndexCount, size_t nStartIndex, int nBaseVertexLocation) override;
			};
			class RendererAPI : public DragAPI::Graphics::RendererAPI {
			public:
				RendererAPI();
				~RendererAPI();


				virtual void CreateDevice(
					DragAPI::Graphics::IAdapter* pAdapter, 
					DragAPI::Graphics::IDevice** pDevice, 
					DragAPI::Graphics::IDeviceContext** pDeviceContext
				) override;

				virtual void CreateDeviceAndSwapChain(
					DragAPI::Graphics::IAdapter* pAdapter,
					DragAPI::Graphics::IDevice** ppDevice,
					DragAPI::Graphics::IDeviceContext** ppDeviceContext,
					DragAPI::Window* pWindow,
					DragAPI::Graphics::ISwapChain** ppSwapChain
				) override;
			private:
			};
		}
		namespace D3D12 {

		}
	}
}