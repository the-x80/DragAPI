#pragma once
#include "Window.h"
#include "../Data Types/Color.h"

namespace DragAPI {
	namespace Graphics {

		class Buffer {

		};

		class VertexBuffer : public Buffer {
		public:

			static VertexBuffer* Create();
		};
		class IndexBuffer : public Buffer {
		public:

			static IndexBuffer* Create();
		};


		class Shader {
		public:

			static Shader* Create();
		};

		
		class Renderer {
		public:
			enum class API {
				None,
				Direct3D
			};
			virtual ~Renderer() {};


			static Renderer* Create(API api, Window* window);

			virtual void Clear(DragAPI::Color color) = 0;

			virtual void Swap() = 0;



			API GetAPI() { return this->m_API; }
		
		private:
			API m_API;
		};
	}
}