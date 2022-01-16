#pragma once
#ifndef DRAG_API_APPLICATION_H
#define DRAG_API_APPLICATION_H

#include "../Exceptions/Exceptions.h"
#include "../Graphics/GraphicsRenderingEngine.h"

namespace DragAPI {
	/*
	class Application {
	private:
		static Application current;


	public:
		

		GraphicsRenderingEngine* graphicsEngine;


		Platform platform;
		Architecture architecture;


		Application();

		inline static Application& Current() { return Application::current; };

		void ProcessFrame();
	};
	*/

	namespace Exceptions {
		class ApplicationException : public Exception {

		};
	}

	enum class ApplicationPlatform {
		Windows,
		Linux,
		Android,
		Other
	};
	enum class ApplicationArchitecture {
		x86,
		x64,
		ARM,
		RISC
	};

	template <typename T> class BaseApplication {
	private:
		static T& current;

		ApplicationPlatform targetPlatform;
		ApplicationArchitecture targetArhitecture;

		char* name;
	public:
		BaseApplication() : name(nullptr){

		}
		~BaseApplication() {
			if (this->name != nullptr) {
				delete[] name;
				name = nullptr;
			}
		}

		static T& Current() { return BaseApplication::current; };


		void SetName(const char* name) {
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, name);
		};
		char* GetName() { return this->name; };
	};


	class ConsoleApplication : public BaseApplication<ConsoleApplication> {

	};
	class WindowsApplication : public BaseApplication<WindowsApplication> {

	};
	class LinuxApplication : public BaseApplication<LinuxApplication> {

	};
	class NativeApplication : public BaseApplication<NativeApplication> {

	};


	//Based on the compilation settings derrive the application class for the specific base type
	class Application :
		public WindowsApplication 
	{

	};
}
#endif