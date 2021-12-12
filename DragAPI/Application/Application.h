#pragma once
#ifndef DRAG_API_APPLICATION_H
#define DRAG_API_APPLICATION_H
namespace DragAPI {
	namespace Application {
		enum class Platform {
			Windows,
			Linux,
			Android,
			Other
		};
		enum class Architecture {
			x86,
			x64,
			ARM,
			RISC
		};



		static const Platform platform = Platform::Windows;



		static const Architecture architecture = Architecture::x86;
	}
}
#endif