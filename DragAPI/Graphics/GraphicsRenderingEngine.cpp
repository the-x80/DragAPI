#include "GraphicsRenderingEngine.h"

DragAPI::GraphicsRenderingEngine::GraphicsRenderingEngine():
	pDevice(nullptr),
	pSwapChain(nullptr),
	pContext(nullptr),
	pAdapters(nullptr)
{
}

void DragAPI::GraphicsRenderingEngine::Create(HWND hWnd)
{
	HRESULT h_CreateFactory = CreateDXGIFactory1(__uuidof(IDXGIFactory1), reinterpret_cast<void**>(&this->pFactory));
	if (FAILED(h_CreateFactory)) {
		//Something went wrong when creating the factory
	}



	DXGI_SWAP_CHAIN_DESC sd = { 0 };



	HRESULT h_CreateDevice = D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		D3D11_CREATE_DEVICE_DEBUG,
		nullptr,
		0,
		D3D11_SDK_VERSION,
		&sd,
		&this->pSwapChain,
		&this->pDevice,
		nullptr,
		&this->pContext
	);

	if (FAILED(h_CreateDevice)) {
		//Creating a device and swap chain failed.
		OutputDebugString(L"Unable to create Device and SwapChain\n");
	}

}

void DragAPI::GraphicsRenderingEngine::Destroy()
{
	if (this->pAdapters != nullptr) {
		delete this->pAdapters;
	}
	if (this->pFactory != nullptr) {
		this->pFactory->Release();
	}
	if (this->pContext != nullptr) {
		this->pContext->Release();
	}
	if (this->pSwapChain != nullptr) {
		this->pSwapChain->Release();
	}
	if (this->pDevice != nullptr) {
		this->pDevice->Release();
	}
}
