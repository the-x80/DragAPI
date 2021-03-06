#define _CRT_SECURE_NO_WARNINGS

#include "../../../DragAPI.Core.h"
#include "../../../Debugging/Debug.h"

#include "../../Graphics.h"
#include "../Windows/WindowsWindow.h"
#include "Direct3DRenderer.h"

namespace DragAPI {
	namespace Graphics {
		namespace D3D9 {
			
		}
		namespace D3D10 {

		}
		namespace D3D11 {
			
#pragma region Vertex Buffer
			VertexBuffer::VertexBuffer():
				m_pBuffer(nullptr),
				m_nStride(0)
			{
			}

			VertexBuffer::VertexBuffer(ID3D11Buffer* pBuffer, UINT nStride):
				m_pBuffer(pBuffer),
				m_nStride(nStride)
			{
			}

			VertexBuffer::~VertexBuffer()
			{
				this->Release();
			}

			void VertexBuffer::Release()
			{
				if (this->m_pBuffer != nullptr) {
					this->m_pBuffer->Release();
				}
			}
#pragma endregion
#pragma region Index Buffer
			IndexBuffer::IndexBuffer():
				m_pBuffer(nullptr),
				m_pRefCount(0),
				m_pRenderer(nullptr)
			{
				
			}

			IndexBuffer::~IndexBuffer() 
			{
				this->Release();
			}

			void IndexBuffer::Release()
			{
				this->m_pRefCount--;
				if (this->m_pRefCount <= 0) {
					if (this->m_pBuffer != nullptr) {
						this->m_pBuffer->Release();
					}
				}
			}

			void IndexBuffer::SetData(void* pData, size_t nSize)
			{

			}
#pragma endregion
#pragma region Constant Buffer
			ConstantBuffer::ConstantBuffer():
				m_pBuffer(nullptr)
			{

			}
			
			ConstantBuffer::~ConstantBuffer() {
				this->Release();
			}

			void ConstantBuffer::Release() {
				if (this->m_pBuffer != nullptr) {
					this->m_pBuffer->Release();
				}
			}
#pragma endregion
#pragma region InputLayout
			InputLayout::InputLayout():
				m_pInputLayout(nullptr)
			{
			}
			InputLayout::InputLayout(ID3D11InputLayout* pInputLayout):
				m_pInputLayout(pInputLayout)
			{
			}
			InputLayout::~InputLayout() {
				if (this->m_pInputLayout != nullptr) {
					this->m_pInputLayout->Release();
				}
			}
#pragma endregion
#pragma region Vertex Shader
			VertexShader::VertexShader():
				m_pVertexShader(nullptr),
				m_pByteCode(nullptr),
				m_nByteCodeSize(0)
			{

			}
			VertexShader::VertexShader(ID3D11VertexShader* pVertShader, const char* pByteCode, size_t nByteCodeSize):
				m_pVertexShader(pVertShader),
				m_pByteCode(new char[nByteCodeSize]),
				m_nByteCodeSize(nByteCodeSize)
			{
				memcpy(m_pByteCode, pByteCode, sizeof(char) * m_nByteCodeSize);
			}
			VertexShader::~VertexShader() {
				this->m_pVertexShader->Release();
			}
			void VertexShader::Release()
			{
				if (this->m_pVertexShader != nullptr) {
					this->m_pVertexShader->Release();
				}
				delete[] this->m_pByteCode;
			}
#pragma endregion
#pragma region Pixel Shader
			PixelShader::PixelShader():
				m_pPixelShader(nullptr),
				m_pByteCode(nullptr),
				m_nByteCodeSize(0)
			{
			}

			PixelShader::PixelShader(ID3D11PixelShader* pPixelShader, const char* pByteCode, size_t nByteCodeSize):
				m_pPixelShader(pPixelShader),
				m_pByteCode(new char[nByteCodeSize]),
				m_nByteCodeSize(nByteCodeSize)
			{
				memcpy(m_pByteCode, pByteCode, sizeof(char) * m_nByteCodeSize);
			}

			PixelShader::~PixelShader() {
				if (this->m_pPixelShader != nullptr) {
					this->m_pPixelShader->Release();
				}
			}
#pragma endregion

#pragma region Render Target View
			
			IRenderTargetView::IRenderTargetView():
				m_pRenderTargetView(nullptr)
			{
			}

			IRenderTargetView::IRenderTargetView(ID3D11RenderTargetView* pRTV):
				m_pRenderTargetView(pRTV)
			{
			}

			IRenderTargetView::~IRenderTargetView() {

			}
#pragma endregion

#pragma region IAdapter
			IAdapter::IAdapter() {

			}
			IAdapter::~IAdapter() {

			}

#pragma endregion
#pragma region ISwapChain
			ISwapChain::ISwapChain():
				m_pSwapChain(nullptr)
			{

			}

			ISwapChain::ISwapChain(IDXGISwapChain* pSwapChain):
				m_pSwapChain(pSwapChain)
			{
			}

			ISwapChain::~ISwapChain() {
				if (this->m_pSwapChain != nullptr) {
					this->m_pSwapChain->Release();
				}
			}

			void ISwapChain::Present()
			{
				this->m_pSwapChain->Present(1u, 0);
			}

			
#pragma endregion
#pragma region IFactory
			IFactory::IFactory()
			{
				HRESULT hr = CreateDXGIFactory2(DXGI_CREATE_FACTORY_DEBUG, __uuidof(IDXGIFactory2), (void**)&this->m_pFactory);
				if (hr != S_OK) {//Error ha occured
					DragAPI::Debug::Log(DragAPI::Debug::LogLevel::Error, "D3D11::IFactory::IFactory() @ %p::Unable to create IFactory interface object\n", this);
				}
			}

			IFactory::~IFactory() {
				if (this->m_pFactory != nullptr) {
					this->m_pFactory->Release();
				}
			}

			void DragAPI::Graphics::D3D11::IFactory::CreateSwapChain(
				DragAPI::Graphics::IDevice* pDevice,
				DragAPI::Window* pWindow,
				DragAPI::Graphics::ISwapChain** ppSwapChain
			)
			{
				DXGI_SWAP_CHAIN_DESC l_scd = { 0 };
				l_scd.BufferDesc.Width = 0;
				l_scd.BufferDesc.Height = 0;
				l_scd.BufferDesc.RefreshRate.Denominator = 0;
				l_scd.BufferDesc.RefreshRate.Numerator = 0;
				l_scd.BufferDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
				l_scd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
				l_scd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

				l_scd.SampleDesc.Count = 0;
				l_scd.SampleDesc.Quality = 0;

				l_scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
				l_scd.BufferCount = 2;
				l_scd.OutputWindow = ((WindowsWindow*)pWindow)->m_Handle;
				l_scd.Windowed = TRUE;
				l_scd.SwapEffect = DXGI_SWAP_EFFECT_SEQUENTIAL;
				l_scd.Flags = 0;
				this->m_pFactory->CreateSwapChain(
					((DragAPI::Graphics::D3D11::IDevice*)pDevice)->m_pDevice,
					&l_scd,
					(IDXGISwapChain**)&(*(DragAPI::Graphics::D3D11::ISwapChain**)ppSwapChain)->m_pSwapChain);
			}
			
#pragma endregion
#pragma region IDevice
			IDevice::IDevice() :
				m_pDevice(nullptr)
			{
			}
			IDevice::IDevice(ID3D11Device* pDevice):
				m_pDevice(pDevice)
			{
			}
			IDevice::~IDevice() {
				if (this->m_pDevice != nullptr) {
					this->m_pDevice->Release();
				}
			}

			void IDevice::CreateSwapChain(DragAPI::Window* pWindow, DragAPI::Graphics::ISwapChain** ppSwapChain)
			{
				if (this->m_pDevice == nullptr) {//This should never happen but a check is done anyway for onforseen bugs
					throw new DragAPI::Exceptions::NullPointerException();
				}

				IDXGIFactory1* pFactory = nullptr;
				CreateDXGIFactory1(__uuidof(IDXGIFactory1), (void**)&pFactory);

				DXGI_SWAP_CHAIN_DESC sd = { 0 };
				sd.BufferDesc.Width = 0;
				sd.BufferDesc.Height = 0;
				sd.BufferDesc.RefreshRate.Denominator = 0;
				sd.BufferDesc.RefreshRate.Numerator = 0;
				sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
				sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
				sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

				sd.SampleDesc.Count = 1;
				sd.SampleDesc.Quality = 0;

				sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
				sd.BufferCount = 1;
				sd.OutputWindow = ((WindowsWindow*)pWindow)->m_Handle;
				sd.Windowed = true;
				sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
				sd.Flags = 0;

				IDXGISwapChain* pSwapChainNative = nullptr;
				pFactory->CreateSwapChain(m_pDevice, &sd, &pSwapChainNative);

				*ppSwapChain = new ISwapChain(pSwapChainNative);
				pFactory->Release();
			}

			void DragAPI::Graphics::D3D11::IDevice::CreateVertexBuffer(
				BufferUsage usage, 
				CPUAccessFlag accessFlag, 
				size_t buffSize, 
				size_t stride, 
				void* pData, 
				DragAPI::Graphics::VertexBuffer** ppVertexBuffer
			)
			{
				D3D11_BUFFER_DESC l_bd = { 0 };
				l_bd.Usage = (D3D11_USAGE)usage;//Since this is a 1 to 1 translation simple cast is acceptable for now
				l_bd.ByteWidth = (UINT)buffSize;
				l_bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
				l_bd.CPUAccessFlags = 0;
				switch (accessFlag) {
				case CPUAccessFlag::None:
					l_bd.CPUAccessFlags = 0;
					break;
				case CPUAccessFlag::Read:
					l_bd.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
					break;
				case CPUAccessFlag::Write:
					l_bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
					break;
				case CPUAccessFlag::ReadWrite:
					l_bd.CPUAccessFlags = D3D11_CPU_ACCESS_READ | D3D11_CPU_ACCESS_WRITE;
					break;
				default:
					throw new DragAPI::Exceptions::InvalidArgumentException();
					break;
				}
				l_bd.MiscFlags = 0;
				l_bd.StructureByteStride = stride;


				DragAPI::Debug::Log(DragAPI::Debug::LogLevel::Info, 
					"DragAPI::Graphics::D3D11::IDevice[@ %p]::CreateVertexBuffer(BufferUsage %d, CPUAccessFlag %d, Size %d, Stride %d, pData %p, nullptr) ::Creating a Vertex Buffer object.\n", 
					this, usage, accessFlag, buffSize, stride, pData);



				D3D11_SUBRESOURCE_DATA l_sd = { 0 };
				l_sd.pSysMem = pData;
				ID3D11Buffer* pBuffer = nullptr;
				HRESULT hr = this->m_pDevice->CreateBuffer(&l_bd, &l_sd, &pBuffer);
				DRAG_API_ASSERT(hr == S_OK, "Unable to create vertex buffer.");

				if (ppVertexBuffer == nullptr) {
					throw new DragAPI::Exceptions::ArgumentNullException();
				}
				*ppVertexBuffer = new VertexBuffer(pBuffer, stride);
			}

			void IDevice::CreateIndexBuffer(
				BufferUsage usage, 
				CPUAccessFlag accessFlag, 
				size_t buffSize, 
				size_t stride, 
				void* pData, 
				DragAPI::Graphics::IndexBuffer** ppIndexBuffer)
			{
				D3D11_BUFFER_DESC l_bd = { 0 };
				l_bd.Usage = (D3D11_USAGE)usage;//Since this is a 1 to 1 translation simple cast is acceptable for now
				l_bd.ByteWidth = (UINT)buffSize;
				l_bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
				l_bd.CPUAccessFlags = 0;
				switch (accessFlag) {
				case CPUAccessFlag::None:
					l_bd.CPUAccessFlags = 0;
					break;
				case CPUAccessFlag::Read:
					l_bd.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
					break;
				case CPUAccessFlag::Write:
					l_bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
					break;
				case CPUAccessFlag::ReadWrite:
					l_bd.CPUAccessFlags = D3D11_CPU_ACCESS_READ | D3D11_CPU_ACCESS_WRITE;
					break;
				}
				l_bd.MiscFlags = 0;
				l_bd.StructureByteStride = (UINT)stride;

				DragAPI::Debug::Log(DragAPI::Debug::LogLevel::Info,
					"DragAPI::Graphics::D3D11::IDevice[@ %p]::CreateIndexBuffer(BufferUsage %d, CPUAccessFlag %d, Size %d, Stride %d, pData %p, nullptr) ::Creating a Index Buffer object.\n",
					this, usage, accessFlag, buffSize, stride, pData);

				D3D11_SUBRESOURCE_DATA l_sd = { 0 };
				l_sd.pSysMem = pData;
				ID3D11Buffer* pBuffer = nullptr;
				HRESULT hr = this->m_pDevice->CreateBuffer(&l_bd, &l_sd, &pBuffer);
				DRAG_API_ASSERT(hr == S_OK, "Unable to create index buffer.");

				if (ppIndexBuffer == nullptr) {
					throw new DragAPI::Exceptions::ArgumentNullException();
				}
				*ppIndexBuffer = new IndexBuffer();
				((IndexBuffer*)*ppIndexBuffer)->m_pBuffer = pBuffer;
			}

			void IDevice::CreateConstantBuffer(
				BufferUsage usage, 
				CPUAccessFlag accessFlag, 
				size_t buffSize, 
				size_t stride, 
				void* pData, 
				DragAPI::Graphics::ConstantBuffer** ppConstantBuffer)
			{
				D3D11_BUFFER_DESC l_bd = { 0 };
				l_bd.Usage = (D3D11_USAGE)usage;//Since this is a 1 to 1 translation simple cast is acceptable for now
				l_bd.ByteWidth = (UINT)buffSize;
				l_bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
				l_bd.CPUAccessFlags = 0;
				switch (accessFlag) {
				case CPUAccessFlag::None:
					l_bd.CPUAccessFlags = 0;
					break;
				case CPUAccessFlag::Read:
					l_bd.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
					break;
				case CPUAccessFlag::Write:
					l_bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
					break;
				}
				l_bd.MiscFlags = 0;

				D3D11_SUBRESOURCE_DATA l_sd = { 0 };
				l_sd.pSysMem = pData;
				ID3D11Buffer* pBuffer = nullptr;
				HRESULT hr = this->m_pDevice->CreateBuffer(&l_bd, &l_sd, &pBuffer);
				DRAG_API_ASSERT(hr == S_OK, "Unable to create constant buffer.");

				if (ppConstantBuffer == nullptr) {
					throw new DragAPI::Exceptions::ArgumentNullException();
				}
				*ppConstantBuffer = new ConstantBuffer();
				((ConstantBuffer*)*ppConstantBuffer)->m_pBuffer = pBuffer;
			}

			void IDevice::CreateInputLayout(
				DragAPI::Graphics::InputElement* pInputElements, 
				size_t nNumInputElements, 
				DragAPI::Graphics::VertexShader* pVertShader, 
				DragAPI::Graphics::InputLayout** ppInputLayout)
			{
				//Convert the abstracted Input element structure to the native DX input element structure
				D3D11_INPUT_ELEMENT_DESC* pInputElementsNative = new D3D11_INPUT_ELEMENT_DESC[nNumInputElements];
				for (int i = 0; i < nNumInputElements; i++) {
					pInputElementsNative[i].SemanticName = pInputElements[i].m_pSemanticName;
					pInputElementsNative[i].SemanticIndex = pInputElements[i].m_nSemanticIndex;
					//Format for now is a 1 to 1 representation. It might not be like that in the future
					pInputElementsNative[i].Format = (DXGI_FORMAT)pInputElements[i].m_nFormat;
					pInputElementsNative[i].InputSlot = pInputElements[i].m_nInputSlot;
					pInputElementsNative[i].AlignedByteOffset = pInputElements[i].m_nAlignedByteOffset;


					switch (pInputElements[i].m_InputClass) {
					case DragAPI::Graphics::InputSlotClasification::None:
						throw new DragAPI::Exceptions::InvalidArgumentException();
						break;
					case DragAPI::Graphics::InputSlotClasification::PerVertex:
						pInputElementsNative[i].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
						break;
					case DragAPI::Graphics::InputSlotClasification::PerInstance:
						pInputElementsNative[i].InputSlotClass = D3D11_INPUT_PER_INSTANCE_DATA;
						break;
					default:
						throw new DragAPI::Exceptions::InvalidArgumentException();
						break;
					}

					pInputElementsNative[i].InstanceDataStepRate = pInputElements[i].m_nInstanceDataStepRate;
				}

				ID3D11InputLayout* pInputLayoutNative = nullptr;
				HRESULT hr = this->m_pDevice->CreateInputLayout(pInputElementsNative, nNumInputElements, ((VertexShader*)pVertShader)->m_pByteCode, ((VertexShader*)pVertShader)->m_nByteCodeSize, &pInputLayoutNative);
				if (hr != S_OK) {
					throw new DragAPI::Exceptions::Exception();
				}
				*ppInputLayout = new InputLayout(pInputLayoutNative);
			}

			void IDevice::CreateVertexShader(
				const char* pByteCode,
				size_t nByteCodeSize, 
				DragAPI::Graphics::VertexShader** ppVertShader)
			{
				ID3D11VertexShader* l_VertShader = nullptr;
				this->m_pDevice->CreateVertexShader(pByteCode, nByteCodeSize, NULL, &l_VertShader);
				*ppVertShader = new VertexShader(l_VertShader, pByteCode, nByteCodeSize);
			}
			void IDevice::CreatePixelShader(
				const char* pByteCode, 
				size_t nByteCodeSize, 
				DragAPI::Graphics::PixelShader** ppPixelShader)
			{
				ID3D11PixelShader* l_FragShader = nullptr;
				HRESULT hr = this->m_pDevice->CreatePixelShader(pByteCode, nByteCodeSize, NULL, &l_FragShader);
				if (hr != S_OK) {
					DragAPI::Debug::Log(DragAPI::Debug::LogLevel::Error, "Could not create pixel shader.");
				}
				*ppPixelShader = new PixelShader(l_FragShader, pByteCode, nByteCodeSize);
			}

			void IDevice::CreateRenderTargetView(DragAPI::Graphics::ISwapChain* pSwap, DragAPI::Graphics::IRenderTargetView** ppRTV)
			{
				HRESULT hr = S_OK;
				ID3D11Resource* pResource = nullptr;
				hr = ((ISwapChain*)pSwap)->m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Resource), (void**)&pResource);
				if (hr != S_OK) {
					DragAPI::Debug::Log(DragAPI::Debug::LogLevel::Info,
						"DragAPI::Graphics::D3D11::IDevice[@ %p]::CreateRenderTargetView(pSwap %p, nullptr) :: Failed to get the buffer to the swapchains backbuffer. GetBuffer function returned %0x\n",
						this, pSwap, hr);
				}
				if (pResource == nullptr) {
					DragAPI::Debug::Log(DragAPI::Debug::LogLevel::Info,
						"DragAPI::Graphics::D3D11::IDevice[@ %p]::CreateRenderTargetView(pSwap %p, nullptr) :: The Resource object returned by the GetBuffer function is nullptr.\n",
						this, pSwap);
					throw new DragAPI::Exceptions::NullPointerException();
				}
				ID3D11RenderTargetView* pRTV = nullptr;
				this->m_pDevice->CreateRenderTargetView(pResource, NULL, &pRTV);
				*ppRTV = new IRenderTargetView(pRTV);
			}
#pragma endregion
#pragma region IDeviceContext
			IDeviceContext::IDeviceContext() {

			}
			IDeviceContext::IDeviceContext(ID3D11DeviceContext* pDevContext):
				m_pDeviceContext(pDevContext)
			{
			}
			IDeviceContext::~IDeviceContext() {

			}
			void IDeviceContext::IASetPrimitiveTopology(DragAPI::Graphics::PrimitiveTopologyType type)
			{
				switch (type) {
				case DragAPI::Graphics::PrimitiveTopologyType::None:
					this->m_pDeviceContext->IASetPrimitiveTopology((D3D11_PRIMITIVE_TOPOLOGY)0);//Set for error checking. Since 0 is an invalid topology.
					break;
				case DragAPI::Graphics::PrimitiveTopologyType::TriangleList:
					this->m_pDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
					break;
				}
			}

			void IDeviceContext::IASetVertexBuffer(
				size_t nInputSlot, 
				DragAPI::Graphics::VertexBuffer* pVertexBuffer)
			{
				UINT l_offsets = 0;
				this->m_pDeviceContext->IASetVertexBuffers(
					nInputSlot, 
					1, 
					&((VertexBuffer*)pVertexBuffer)->m_pBuffer, 
					&((VertexBuffer*)pVertexBuffer)->m_nStride, 
					&l_offsets);
			}

			void IDeviceContext::IASetVertexBuffers(
				size_t nInputSlot, 
				size_t nBufferSize, 
				DragAPI::Graphics::VertexBuffer** ppVertexBuffer)
			{
				ID3D11Buffer** pVertBufferNative = new ID3D11Buffer*[nBufferSize];
				UINT* pStrides = new UINT[nBufferSize];
				UINT* pOffsets = new UINT[nBufferSize];
				for (int i = 0; i < nBufferSize; i++) {
					pVertBufferNative[i] = ((VertexBuffer*)ppVertexBuffer[i])->m_pBuffer;
					pStrides[i] = ((VertexBuffer*)ppVertexBuffer[i])->m_nStride;
					pOffsets[i] = 0;
				}
				this->m_pDeviceContext->IASetVertexBuffers(
					nInputSlot,
					nBufferSize,
					pVertBufferNative,
					pStrides,
					pOffsets
				);

				delete[] pVertBufferNative;
				delete[] pStrides;
				delete[] pOffsets;
			}

			void IDeviceContext::IASetIndexBuffer(DragAPI::Graphics::IndexBuffer* pIndexBuffer)
			{
				this->m_pDeviceContext->IASetIndexBuffer(((IndexBuffer*)pIndexBuffer)->m_pBuffer, DXGI_FORMAT_R32_UINT, 0);
			}

			void IDeviceContext::IASetInputLayout(DragAPI::Graphics::InputLayout* pInputLayout)
			{
				this->m_pDeviceContext->IASetInputLayout(((InputLayout*)pInputLayout)->m_pInputLayout);
			}

			void IDeviceContext::VSSetShader(DragAPI::Graphics::VertexShader* pShader)
			{
				if (pShader == nullptr) {
					throw new DragAPI::Exceptions::ArgumentNullException();
				}

				this->m_pDeviceContext->VSSetShader(((VertexShader*)pShader)->m_pVertexShader, NULL, 0);
			}

			void IDeviceContext::PSSetShader(DragAPI::Graphics::PixelShader* pShader)
			{
				if (pShader == nullptr) {
					throw new DragAPI::Exceptions::ArgumentNullException();
				}

				this->m_pDeviceContext->PSSetShader(((PixelShader*)pShader)->m_pPixelShader, NULL, 0);
			}

			void IDeviceContext::OMSetRenderTarget(DragAPI::Graphics::IRenderTargetView* pRTV)
			{
				this->m_pDeviceContext->OMSetRenderTargets(1, &((IRenderTargetView*)pRTV)->m_pRenderTargetView, nullptr);
			}

			void IDeviceContext::RSSetViewport(float nWidth, float nHeight, float nMinDepth, float nMaxDepth, float nTopLeftX, float nTopLeftY)
			{
				D3D11_VIEWPORT vp = { 0 };
				vp.Width = nWidth;
				vp.Height = nHeight;
				vp.MinDepth = nMinDepth;
				vp.MaxDepth = nMaxDepth;
				vp.TopLeftX = nTopLeftX;
				vp.TopLeftY = nTopLeftY;
				this->m_pDeviceContext->RSSetViewports(1, &vp);
			}

			void IDeviceContext::ClearRenderTargetView(DragAPI::Graphics::IRenderTargetView* pRTV, DragAPI::Color color)
			{
				FLOAT col[4] = { color.red, color.green, color.blue, color.alpha };
				this->m_pDeviceContext->ClearRenderTargetView(((IRenderTargetView*)pRTV)->m_pRenderTargetView, col);
			}

			void IDeviceContext::Draw(size_t nVertCount, size_t nStartIndex)
			{
				this->m_pDeviceContext->Draw((UINT)nVertCount, (UINT)nStartIndex);
			}

			void IDeviceContext::DrawIndexed(size_t nIndexCount, size_t nStartIndex, int nBaseVertexLocation)
			{
				this->m_pDeviceContext->DrawIndexed((UINT)nIndexCount, (UINT)nStartIndex, (UINT)nBaseVertexLocation);
			}
#pragma endregion
#pragma region Renderer API
			RendererAPI::RendererAPI() {

			}
			RendererAPI::~RendererAPI() {
				
				
			}

			void RendererAPI::CreateDevice(
				DragAPI::Graphics::IAdapter* pAdapter, 
				DragAPI::Graphics::IDevice** ppDevice, 
				DragAPI::Graphics::IDeviceContext** ppDeviceContext
			)
			{
				DragAPI::Debug::Log(DragAPI::Debug::LogLevel::Info, "DragAPI::Graphics::D3D11::RendererAPI::CreateDevice() @ %p::Creating a Device object\n", this);
				
				//TODO: Implement adapters. Currently they are not considered.

				ID3D11Device* pNativeDevice;
				ID3D11DeviceContext* pNativeContext;
				D3D_FEATURE_LEVEL l_SupportedFeatureLevel;
				ZeroMemory(&l_SupportedFeatureLevel, sizeof(D3D_FEATURE_LEVEL));
				HRESULT hr = D3D11CreateDevice(
					NULL,
					D3D_DRIVER_TYPE_HARDWARE,
					NULL,
					D3D11_CREATE_DEVICE_DEBUG | D3D11_CREATE_DEVICE_DISABLE_GPU_TIMEOUT,
					NULL/*Default Feature Level*/,
					0,
					D3D11_SDK_VERSION,
					&pNativeDevice,
					&l_SupportedFeatureLevel,
					&pNativeContext
				);

				//Error check here
				if (hr != S_OK) {//There was an error.
					throw new DragAPI::Exceptions::Exception("Unknow error.");
				}


				*ppDevice = new IDevice(pNativeDevice);
				*ppDeviceContext = new IDeviceContext(pNativeContext);
			}

			void RendererAPI::CreateDeviceAndSwapChain(
				DragAPI::Graphics::IAdapter* pAdapter, 
				DragAPI::Graphics::IDevice** ppDevice, 
				DragAPI::Graphics::IDeviceContext** ppDeviceContext, 
				DragAPI::Window* pWindow, 
				DragAPI::Graphics::ISwapChain** ppSwapChain)
			{
				RendererAPI::CreateDevice(pAdapter, ppDevice, ppDeviceContext);
				(*ppDevice)->CreateSwapChain(pWindow, ppSwapChain);
			}


#pragma endregion

		}
		namespace D3D12 {

		}
	}
}

