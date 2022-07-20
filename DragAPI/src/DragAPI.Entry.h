#pragma once
#ifndef DRAG_API_ENTRY_H
#define DRAG_API_ENTRY_H

#ifndef _WINDLL

	#ifdef _WIN32
	#include <Windows.h>
	#define DRAG_API_ENTRY_FUNC int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
	#else
	#define DRAG_API_ENTRY_FUNC int main(int argc, char** argv)
	#endif



	DRAG_API_ENTRY_FUNC{
		::DragAPI::Debug::Log(DragAPI::Debug::LogLevel::Info, "DRAG_API_ENTRY_FUNC::Creating Application class\n");
		DragAPI::Application*  l_CurrentApplication = DragAPI::Application::CreateApplication();
		::DragAPI::Debug::Log(DragAPI::Debug::LogLevel::Info, "DRAG_API_ENTRY_FUNC::Application class @ %p. Executing Application\n", l_CurrentApplication);
		l_CurrentApplication->Run();
		::DragAPI::Debug::Log(DragAPI::Debug::LogLevel::Info, "DRAG_API_ENTRY_FUNC::Application class @ %p stopped execution. Deleting the created application class.\n", l_CurrentApplication);
		delete l_CurrentApplication;
		return 0;
	}
	#endif
#endif