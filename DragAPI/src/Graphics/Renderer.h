#pragma once
#include "Window.h"
#include "../Data Types/Color.h"
#include "../Data Types/Vectors.h"


/*
Rendering API abstraction class

The structure is based on Direct X API for now.
Depending on the structure of other APIs this one might change to accomodate sensible abstraction.
*/

namespace DragAPI {
	namespace Graphics {

#pragma region Forward Declarations
		class IDevice;
		class RendererAPI;
#pragma endregion

		class Object {
		public:
			virtual ~Object() {};

			//virtual void Release() = 0;
		};

		//TODO: Implement Resource Misc Flags
		class Resource : public Object{

		};

		enum class PrimitiveTopologyType {//TODO: Implement more primitive topologies.
			None,
			TriangleList
		};

		enum class BufferUsage {
			Default,//A resource that requires read and write access by the GPU. This is likely to be the most common usage choice.
			Immutable,//A resource that can only be read by the GPU. It cannot be written by the GPU, and cannot be accessed at all by the CPU. This type of resource must be initialized when it is created, since it cannot be changed after creation.
			Dynamic,//A resource that is accessible by both the GPU (read only) and the CPU (write only). A dynamic resource is a good choice for a resource that will be updated by the CPU at least once per frame. 
			Staging//A resource that supports data transfer (copy) from the GPU to the CPU.
		};
		enum class CPUAccessFlag {
			None = 0b00,
			Write = 0b01,
			Read = 0b10,
			ReadWrite = 0b11
		};
		class Buffer : public Resource {

		};

		class VertexBuffer : public Buffer {
		public:
			virtual ~VertexBuffer() {};
		};
		class IndexBuffer : public Buffer {
		public:
			enum class Format : unsigned char{
				UInt16,
				UInt32
			};
		public:
			virtual ~IndexBuffer() {};

			void SetFormat(Format format) { this->m_Format = format; };
			Format GetFormat() { return this->m_Format; };
		private:
			Format m_Format;
		};
		class ConstantBuffer : public Buffer {
		public:
			virtual ~ConstantBuffer() {};
		};

		enum class InputSlotClasification {
			None,
			PerVertex,
			PerInstance
		};
		struct InputElement {
			const char* m_pSemanticName;
			unsigned int m_nSemanticIndex;
			int m_nFormat;//Will be replaced by a enum class in the future
			unsigned int m_nInputSlot;
			unsigned int m_nAlignedByteOffset;
			InputSlotClasification m_InputClass;
			unsigned int m_nInstanceDataStepRate;
		};
		class InputLayout {
		public:
			virtual ~InputLayout() {};

		};

		class Shader : Object{
		public:
			virtual ~Shader() {};
		};

		class VertexShader : public Shader{
		public:
			virtual ~VertexShader() {};
		};
		class PixelShader : public Shader{
		public:
			virtual ~PixelShader() {};
		};
		
		class IRenderTargetView {
		public:
			virtual ~IRenderTargetView() {};
		};
		class IDepthStencilView {
		public:
			virtual ~IDepthStencilView() {};
		};

		class IAdapter {
		public:
			virtual ~IAdapter() {};
		};
		class ISwapChain {
		public:
			virtual ~ISwapChain() {};

			virtual void Present() = 0;
		};
		class IFactory {
		public:
			virtual ~IFactory() {};

			static void Create(DragAPI::Graphics::RendererAPI* r, IFactory** ppFactory);
			
			virtual void CreateSwapChain(
				DragAPI::Graphics::IDevice* pDevice, 
				DragAPI::Window* pWindow,
				DragAPI::Graphics::ISwapChain** ppSwapChain
			) = 0;
		};
		class IDevice {
		public:
			virtual ~IDevice() {};

			virtual void CreateSwapChain(Window* pWindow, ISwapChain** ppSwapChain) = 0;

			virtual void CreateVertexBuffer(
				BufferUsage usage,
				CPUAccessFlag accessFlag,
				size_t buffSize,
				size_t stride,
				void* pData,
				VertexBuffer** ppVertexBuffer
			) = 0;

			virtual void CreateIndexBuffer(
				BufferUsage usage,
				CPUAccessFlag accessFlag,
				size_t buffSize,
				size_t stride,
				void* pData,
				IndexBuffer** ppIndexBuffer
			) = 0;

			virtual void CreateConstantBuffer(
				BufferUsage usage,
				CPUAccessFlag accessFlag,
				size_t buffSize,
				size_t stride,
				void* pData,
				DragAPI::Graphics::ConstantBuffer** ppIndexBuffer
			) = 0;
			/*
			virtual void CreateVertexShader() = 0;
			virtual void CreatePixelShader() = 0;
			virtual void CreateHullShader() = 0;
			virtual void CreateGeometryShader() = 0;
			virtual void CreateComputeShader() = 0;
			*/


			virtual void CreateInputLayout(
				InputElement* pInputElements, 
				size_t nNumInputElements, 
				VertexShader* pVertShader, 
				InputLayout** ppInputLayout
			) = 0;
			//Note that the bytecode parameter is API dependent. In the future this might change depending on the needs of this abstracted api
			virtual void CreateVertexShader(const char* pByteCode, size_t nByteCodeSize, VertexShader** ppVertShader) = 0;
			virtual void CreatePixelShader(const char* pByteCode, size_t nByteCodeSize, PixelShader** ppPixelShader) = 0;


			virtual void CreateRenderTargetView(ISwapChain* pSwap, IRenderTargetView** ppRTV) = 0;
		};
		class IDeviceContext {
		public:
			virtual ~IDeviceContext() {};

			virtual void IASetPrimitiveTopology(
				PrimitiveTopologyType type
			) = 0;

			virtual void IASetVertexBuffer(
				size_t nInputSlot,
				VertexBuffer* pVertexBuffer
			) = 0;
			virtual void IASetVertexBuffers(
				size_t nInputSlot,
				size_t nBufferSize,
				VertexBuffer** ppVertexBufferArray
			) = 0;

			virtual void IASetIndexBuffer(
				IndexBuffer* pIndexBuffer
			) = 0;

			virtual void IASetInputLayout(InputLayout* pInputLayout) = 0;

			virtual void VSSetShader(VertexShader* pShader) = 0;

			virtual void PSSetShader(PixelShader* pShader) = 0;

			virtual void OMSetRenderTarget(IRenderTargetView* pRTV) = 0;

			virtual void RSSetViewport(
				float nWidth, 
				float nHeight,
				float nMinDepth,
				float nMaxDepth,
				float nTopLeftX,
				float nTopLeftY
			) = 0;


			virtual void ClearRenderTargetView(IRenderTargetView* pRTV, DragAPI::Color color) = 0;

			virtual void Draw(size_t nVertCount, size_t nStartIndex = 0) = 0;
			virtual void DrawIndexed(size_t nIndexCount, size_t nStartIndex, int nBaseVertexLocation) = 0;
		};
		class RendererAPI {
		public:
			enum class API {
				None,
				Direct3D,
				Direct3D_9,
				Direct3D_10,
				Direct3D_11,
				Direct3D_12,
				OpenGL
			};
			virtual ~RendererAPI() {};


			static RendererAPI* Create(API api);

			/// <summary>
			/// Creates a device associated with the current rendering API
			/// </summary>
			/// <param name="pAdapter">The graphics adapter that is used. Set this parameter to null to use a default adapter</param>
			/// <param name="pDevice">Buffer to store the created device</param>
			/// <param name="pDeviceContext">Buffer to store the created device context</param>
			virtual void CreateDevice(
				IAdapter* pAdapter, 
				IDevice** ppDevice, 
				IDeviceContext** ppDeviceContext
			) = 0;

			

			virtual void CreateDeviceAndSwapChain(
				IAdapter* pAdapter,
				IDevice** ppDevice,
				IDeviceContext** ppDeviceContext,
				Window* pWindow,
				ISwapChain** ppSwapChain
			) = 0;

			inline const API GetAPI() const { return this->m_API; }
		protected:
			API m_API;

			void SetAPI(API api) { this->m_API = api; }
		};
	}
}