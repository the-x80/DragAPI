#pragma once
#include "Window.h"
#include "../Data Types/Color.h"
#include "../Data Types/Vectors.h"

namespace DragAPI {
	namespace Graphics {

		class Renderer;

		class Object {
		public:
			//virtual void Release() = 0;
		};

		class Buffer : public Object{

		};

		class VertexBuffer : public Buffer {
		public:

			static VertexBuffer* Create(const Renderer* renderer, size_t buffSize, size_t stride, void* pData);

			virtual void Bind() = 0;
		};
		class IndexBuffer : public Buffer {
		public:

			static IndexBuffer* Create(const Renderer* r, size_t buffSize, size_t stride, void* pData);

			virtual void Bind() = 0;
		};

		class Shader {
		public:
		};

		class VertexShader : public Shader{
		public:
			static VertexShader* CompileFromSource(const char* vs_source);
		};
		class PixelShader : public Shader{
		public:
			static PixelShader* CompileFromSource(const char* ps_source);
		};
		
		
		class RenderContext {
		public:
		};
		
		class Renderer {
		public:
			enum class API {
				None,
				Direct3D,
				OpenGL
			};
			virtual ~Renderer() {};


			static Renderer* Create(API api, Window* window);

			virtual void Clear(DragAPI::Color color) = 0;

			virtual void DrawLine2D(DragAPI::Vector<float, 2> p1, DragAPI::Vector<float, 2> p2, DragAPI::Color color) = 0;

			virtual void Swap() = 0;


			virtual RenderContext* GetRenderContext() = 0;


			API GetAPI() const { return this->m_API; }
		protected:
			void SetAPI(API api) { this->m_API = api; }
		private:
			API m_API;
		};
	}
}