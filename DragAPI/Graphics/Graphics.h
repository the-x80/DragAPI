#ifndef DRAG_API_GRAPHICS_H
#define DRAG_API_GRAPHICS_H
#include "../Data Types/Vectors.h"
#include "../Array/Array.h"

#include "Window.h"

//TODO: Implement Graphics you asshole

namespace DragAPI {
	namespace Graphics {
		namespace Rendering {
			enum class RenderingApi {
				DirectX9,
				DirectX10,
				DirectX11,
				DirectX12,
				OpenGL,
				Vulkan
			};




			class VertexBuffer {
			private:
				DragAPI::Array<Vector3Double> position;
			
			protected:
				VertexBuffer();
				VertexBuffer(VertexBuffer& other);
				VertexBuffer(VertexBuffer&& other);
				~VertexBuffer();

			public:
				static VertexBuffer* Create(RenderingApi api);
			};
			class IndexBuffer {
			private:
				DragAPI::Array<int> indices;
			
			protected:
				IndexBuffer();
				IndexBuffer(IndexBuffer& other);
				IndexBuffer(IndexBuffer&& other);
				~IndexBuffer();

			public:
				static IndexBuffer* Create(RenderingApi api);
			};

			class Renderer {
			private:

			protected:
				Renderer();
				Renderer(Renderer& other);
				Renderer(Renderer&& other);

			public:
				static Renderer* Create(RenderingApi api);
			};
		}
	}
}
#endif