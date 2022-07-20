#include "Renderer.h"
#include "Platform\Direct3D\Direct3DRenderer.h"

DragAPI::Graphics::RendererAPI* DragAPI::Graphics::RendererAPI::Create(API api)
{
	switch (api) {
	case API::None:
		return nullptr;
#ifdef _WIN32
	//case API::Direct3D:
		//return new Direct3DRenderer(window);
	case API::Direct3D_11:
		return new DragAPI::Graphics::D3D11::RendererAPI();
#endif
	}
	return nullptr;
}

void DragAPI::Graphics::IFactory::Create(DragAPI::Graphics::RendererAPI* r, IFactory** ppFactory)
{
	switch (r->GetAPI()) {
	case DragAPI::Graphics::RendererAPI::API::None:
		*ppFactory = nullptr;
		return;
#ifdef _WIN32
		//case API::Direct3D:
			//return new Direct3DRenderer(window);
	case DragAPI::Graphics::RendererAPI::API::Direct3D_11:
		*ppFactory = new DragAPI::Graphics::D3D11::IFactory();
		return;
#endif
	}
	return;
}