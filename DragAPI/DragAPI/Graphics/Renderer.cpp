#include "Renderer.h"
#ifdef _WIN32
#include "Platform/Direct3D/Direct3DRenderer.h"
#endif

DragAPI::Graphics::Renderer* DragAPI::Graphics::Renderer::Create(API api, Window* window)
{
	switch (api) {
	case API::None:
		return nullptr;
#ifdef _WIN32
	case API::Direct3D:
		return new Direct3DRenderer(window);
#endif
	}
	return nullptr;
}
