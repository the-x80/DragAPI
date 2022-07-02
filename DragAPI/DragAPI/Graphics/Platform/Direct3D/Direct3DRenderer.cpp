#include "../../../DragAPI.Core.h"
#include "../../../Debugging/Debug.h"

#include "Direct3DRenderer.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Vertex Buffer //////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region Vertex Buffer
DragAPI::Graphics::Direct3DVertexBuffer::Direct3DVertexBuffer(Direct3DRenderer* renderer, size_t buffSize, size_t stride, void* pData)
{
	Debug::Log(DragAPI::Debug::LogLevel::Info, "Constructing a vertex buffer @ %p", this);
	D3D11_BUFFER_DESC bd = { 0 };
	bd.ByteWidth = (UINT)buffSize;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_READ|D3D11_CPU_ACCESS_WRITE;
	bd.MiscFlags = 0;
	bd.StructureByteStride = (UINT)stride;

	D3D11_SUBRESOURCE_DATA sd = { 0 };
	sd.pSysMem = pData;
	renderer->m_pDevice->CreateBuffer(&bd, &sd, &this->m_pVertexBuffer);

	this->m_Renderer = renderer;

	this->m_Stride = stride;
}

DragAPI::Graphics::Direct3DVertexBuffer::~Direct3DVertexBuffer()
{
	this->m_pVertexBuffer->Release();
	this->m_pVertexBuffer = nullptr;
	this->m_Renderer = nullptr;
}

void DragAPI::Graphics::Direct3DVertexBuffer::Bind()
{
	//TODO: See documentation fot IASetVertexBuffers
	this->m_Renderer->m_pContext->m_pContext->IASetVertexBuffers(0, 1, &this->m_pVertexBuffer, (UINT*)&this->m_Stride, nullptr);
}
#pragma endregion
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Index Buffer ///////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region Index Buffer
DragAPI::Graphics::Direct3DIndexBuffer::Direct3DIndexBuffer(Direct3DRenderer* r, size_t buffSize, size_t stride, void* pData)
{
	Debug::Log(DragAPI::Debug::LogLevel::Info, "Constructing an index buffer @ %p", this);
	D3D11_BUFFER_DESC bd = { 0 };
	bd.ByteWidth = (UINT)buffSize;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_READ | D3D11_CPU_ACCESS_WRITE;
	bd.MiscFlags = 0;
	bd.StructureByteStride = (UINT)stride;

	D3D11_SUBRESOURCE_DATA sd = { 0 };
	sd.pSysMem = pData;
	r->m_pDevice->CreateBuffer(&bd, &sd, &this->m_pIndexBuffer);

	this->m_Renderer = r;

	this->m_Stride = stride;
}

DragAPI::Graphics::Direct3DIndexBuffer::~Direct3DIndexBuffer()
{
	if (this->m_pIndexBuffer != nullptr) {
		this->m_pIndexBuffer->Release();
	}
}

void DragAPI::Graphics::Direct3DIndexBuffer::Bind()
{
}
#pragma endregion
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Shaders ////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region Shaders
//// Vertex Shader //////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region Vertex Shader
DragAPI::Graphics::Direct3DVertexShader::Direct3DVertexShader()
{
}

DragAPI::Graphics::Direct3DVertexShader::~Direct3DVertexShader()
{
	
}

DragAPI::Graphics::Direct3DVertexShader* DragAPI::Graphics::Direct3DVertexShader::FromSource(Direct3DRenderer* r, const char* vs_source)
{
	
	ID3DBlob* l_ErrorBlob;

	Direct3DVertexShader* l_VertShader = new Direct3DVertexShader();
	::DragAPI::Debug::Log(DragAPI::Debug::LogLevel::Info, "DragAPI::Graphics::Direct3DVertexShader::FromSource(Direct3DRenderer* r = %p, const char* vs_source = %p)::\n	Constructing a Vertex Shader @ %p from source\n", r, vs_source, l_VertShader);
	HRESULT hr = D3DCompile2(vs_source, strlen(vs_source), NULL/*Should be set*/,
		NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "vs_5_0",
		D3DCOMPILE_DEBUG, NULL, NULL, NULL, 0, &l_VertShader->m_pShaderBlob, &l_ErrorBlob);
	if (hr != S_OK) {
		//There has been an error while compiling the shader.
		::DragAPI::Debug::Log(DragAPI::Debug::LogLevel::Info, "DragAPI::Graphics::Direct3DVertexShader::FromSource(Direct3DRenderer* r = %p, const char* vs_source = %p)::\n	Constructing a Vertex Shader @ %p from source failed.\n    \"%s\"\n", r, vs_source, l_VertShader, l_ErrorBlob->GetBufferPointer());
	}

	return l_VertShader;
}
#pragma endregion
//// Pixel Shader ///////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region Pixel Shader

DragAPI::Graphics::Direct3DPixelShader::Direct3DPixelShader()
{
}

DragAPI::Graphics::Direct3DPixelShader::~Direct3DPixelShader()
{
	
}

DragAPI::Graphics::Direct3DPixelShader* DragAPI::Graphics::Direct3DPixelShader::FromSource(Direct3DRenderer* r, const char* ps_source)
{
	return nullptr;
}
#pragma endregion
//// Shader /////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region Shader
DragAPI::Graphics::Direct3DShader::Direct3DShader() :
	m_pShaderBlob(nullptr)
{
}

DragAPI::Graphics::Direct3DShader::~Direct3DShader()
{
	if (this->m_pShaderBlob != nullptr) {
		this->m_pShaderBlob->Release();
	}
}
#pragma endregion
#pragma endregion
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Render Context /////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region Render Context
DragAPI::Graphics::Direct3DRenderContext::Direct3DRenderContext(ID3D11DeviceContext* con) :
	m_pContext(con)
{
	
}

DragAPI::Graphics::Direct3DRenderContext::~Direct3DRenderContext()
{
	if (this->m_pContext != nullptr) {
		this->m_pContext->Release();
	}
}
#pragma endregion
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Renderer ///////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DragAPI::Graphics::Direct3DRenderer::Direct3DRenderer(Window* targetWindow):
	m_TargetWindow((WindowsWindow*)targetWindow),
	m_pDevice(nullptr)
{
	this->SetAPI(DragAPI::Graphics::Renderer::API::Direct3D);
	::DragAPI::Debug::Log(DragAPI::Debug::LogLevel::Info, "DragAPI::Graphics::Direct3DRenderer::Direct3DRenderer(Window* targetWindow = %p)::Constructing a Direct3D Renderer @ %p\n", targetWindow, this);
	HRESULT hr = S_OK;

	DXGI_SWAP_CHAIN_DESC l_sd = {0};
	l_sd.BufferDesc.Width = 0;
	l_sd.BufferDesc.Height = 0;
	l_sd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	l_sd.BufferDesc.RefreshRate.Numerator = 0;
	l_sd.BufferDesc.RefreshRate.Denominator = 0;
	l_sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	l_sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	l_sd.SampleDesc.Count = 1;
	l_sd.SampleDesc.Quality = 0;
	l_sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	l_sd.BufferCount = 1;
	l_sd.OutputWindow = this->m_TargetWindow->m_Handle;
	l_sd.Windowed = TRUE;
	l_sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	l_sd.Flags = 0;
	::DragAPI::Debug::Log(DragAPI::Debug::LogLevel::Info, "DragAPI::Graphics::Direct3DRenderer::Direct3DRenderer(Window* targetWindow = %p) @ %p::Filled DXGI_SWAP_CHAIN_DESC structure.\n"
															"	l_sd.BufferDesc.Width = %d\n"
															"	l_sd.BufferDesc.Height = %d\n", 
															targetWindow, this,
															l_sd.BufferDesc.Width,
															l_sd.BufferDesc.Height = 0);

	ID3D11DeviceContext* l_DeviceContext = nullptr;

	::DragAPI::Debug::Log(DragAPI::Debug::LogLevel::Info, "DragAPI::Graphics::Direct3DRenderer::Direct3DRenderer(Window* targetWindow = %p) @ %p::D3D11CreateDeviceAndSwapChain()\n", targetWindow, this);
	hr = D3D11CreateDeviceAndSwapChain(nullptr, 
		D3D_DRIVER_TYPE_HARDWARE, 
		nullptr,
		0, nullptr, 0, 
		D3D11_SDK_VERSION, 
		&l_sd, 
		&this->m_pSwapChain, 
		&this->m_pDevice, 
		nullptr, 
		&l_DeviceContext);
	DRAG_API_ASSERT(hr == S_OK, "D3D11CreateDeviceAndSwapChain failed with %d", hr);

	this->m_pContext = new Direct3DRenderContext(l_DeviceContext);

	ID3D11Resource* l_pBackBuffer = nullptr;
	hr = this->m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Resource), reinterpret_cast<void**>(&l_pBackBuffer));
	DRAG_API_ASSERT(hr == S_OK, "Unable to get the ID3D11Resource describing the back buffer.");

	this->m_pDevice->CreateRenderTargetView(l_pBackBuffer, nullptr, &this->m_pRenderTarget);
	l_pBackBuffer->Release();
}

DragAPI::Graphics::Direct3DRenderer::~Direct3DRenderer()
{
}

void DragAPI::Graphics::Direct3DRenderer::Clear(DragAPI::Color color)
{
	float colordata[4] = { color.red, color.green, color.blue, color.alpha };
	this->m_pContext->m_pContext->ClearRenderTargetView(this->m_pRenderTarget.Get(), colordata);
}

void DragAPI::Graphics::Direct3DRenderer::DrawLine2D(DragAPI::Vector<float, 2> p1, DragAPI::Vector<float, 2> p2, DragAPI::Color color)
{

}

void DragAPI::Graphics::Direct3DRenderer::Swap()
{
	this->m_pSwapChain->Present(1u, 0);
}


