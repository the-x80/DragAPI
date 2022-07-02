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

DragAPI::Graphics::VertexBuffer* DragAPI::Graphics::VertexBuffer::Create(const Renderer* renderer, size_t buffSize, size_t stride, void* pData)
{
	switch (renderer->GetAPI()) {
	case DragAPI::Graphics::Renderer::API::None:
		return nullptr;
#ifdef _WIN32
	case DragAPI::Graphics::Renderer::API::Direct3D:
		return new Direct3DVertexBuffer((Direct3DRenderer*)renderer, buffSize, stride, pData);
#endif
	case DragAPI::Graphics::Renderer::API::OpenGL:
		return nullptr;
	}
	return nullptr;
}

DragAPI::Graphics::IndexBuffer* DragAPI::Graphics::IndexBuffer::Create(const Renderer* renderer, size_t buffSize, size_t stride, void* pData)
{
	switch (renderer->GetAPI()) {
	case DragAPI::Graphics::Renderer::API::None:
		return nullptr;
#ifdef _WIN32
	case DragAPI::Graphics::Renderer::API::Direct3D:
		return new Direct3DIndexBuffer((Direct3DRenderer*)renderer, buffSize, stride, pData);
#endif
	case DragAPI::Graphics::Renderer::API::OpenGL:
		return nullptr;
	}
	return nullptr;
}
