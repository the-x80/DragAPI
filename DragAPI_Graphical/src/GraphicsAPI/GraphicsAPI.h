#pragma once


namespace DragAPI::Graphical {
	enum class NativeAPI {
		Nnone,
		DirectX
	};
	class GraphicsAPI {
	public:
		virtual ~GraphicsAPI() {};

		static GraphicsAPI* Create(NativeAPI api);
	};
}