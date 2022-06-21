#pragma once
#ifndef DRAG_API_GRAPHICS_RENDERING_ENGINE_H
#define DRAG_API_GRAPHICS_RENDERING_ENGINE_H
#include <bitset>
#include <functional>
#include <vector>
#include <string>

#include "../Exceptions/Exceptions.h"

#include "../Data Types/Rect.h"
#include "../Data Types/Vectors.h"
#include "../Data Types/Quaternion.h"
#include "../Data Types/Queue.h"




namespace DragAPI {
	namespace Graphics {
		enum class RenderingAPI {
			None,
			DirectX,
			OpenGL,
			Vulkan,
			Software,
			Raytracer
		};


		class Renderer {
		public:
			Renderer();
			Renderer(Renderer& other);
			Renderer(Renderer&& other) noexcept;
			~Renderer();
		};

		/// <summary>
		/// 
		/// </summary>
		/// <typeparam name="T">The structure that holds one element of the vertex buffer</typeparam>
		template <class T> class VertexBuffer {
		private:
			std::vector<T> data;
		public:
		};
		class IndexBuffer {

		};
		class Shader {

		};
		class Material {
		private:
			Shader shader;
		public:
		};
		class RenderingEngine {
		private:
			std::vector<Renderer> renderers;

		public:
			RenderingEngine();
			RenderingEngine(RenderingEngine& other) = delete;
			RenderingEngine(RenderingEngine&& other) = delete;
			~RenderingEngine();


			static RenderingEngine Create();//Creates a rendering engine
			static std::vector<RenderingAPI> GetSupportedAPIs();

#pragma region Virtual functions

#pragma endregion
		};

		namespace Exceptions {
#pragma region Vertex buffer exceptions
#pragma endregion
#pragma region Index buffer exceptions
#pragma endregion
#pragma region Shader exceptions
#pragma endregion
#pragma region Material exceptions
#pragma endregion
#pragma region Rendering engine exceptions
			class UnsupportedAPIException : public DragAPI::Exceptions::Exception {

			};
#pragma endregion
		}
	}
}

#endif