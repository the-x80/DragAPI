#include "Direct3DRenderer.h"

DragAPI::Graphics::Direct3DRenderer::Direct3DRenderer(Window* targetWindow):
	m_TargetWindow((WindowsWindow*)targetWindow),
	m_pDevice(nullptr)
{
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


	D3D11CreateDeviceAndSwapChain(nullptr, 
		D3D_DRIVER_TYPE_HARDWARE, 
		nullptr,
		0, nullptr, 0, 
		D3D11_SDK_VERSION, 
		&l_sd, 
		&this->m_pSwapChain, 
		&this->m_pDevice, 
		nullptr, 
		&this->m_pContext);


}

DragAPI::Graphics::Direct3DRenderer::~Direct3DRenderer()
{
	if (this->m_pContext != nullptr) {
		this->m_pContext->Release();
	}

	if (this->m_pSwapChain != nullptr) {
		this->m_pSwapChain->Release();
	}

	if (this->m_pDevice != nullptr) {
		this->m_pDevice->Release();
	}
}

void DragAPI::Graphics::Direct3DRenderer::Clear(DragAPI::Color color)
{
	ID3D11Resource* l_pBackBuffer = nullptr;
	this->m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Resource), reinterpret_cast<void**>(&l_pBackBuffer));

	ID3D11RenderTargetView* l_pRenderTarget = nullptr;
	this->m_pDevice->CreateRenderTargetView(l_pBackBuffer, nullptr, &l_pRenderTarget);

	float colordata[4] = { color.red, color.green, color.blue, color.alpha };
	this->m_pContext->ClearRenderTargetView(l_pRenderTarget, colordata);

	l_pRenderTarget->Release();
	l_pBackBuffer->Release();
}

void DragAPI::Graphics::Direct3DRenderer::Swap()
{
	this->m_pSwapChain->Present(1u, 0);
}
