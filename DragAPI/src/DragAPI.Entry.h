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
		DragAPI::Application*  l_CurrentApplication = DragAPI::Application::CreateApplication();
		l_CurrentApplication->Run();
		delete l_CurrentApplication;
		return 0;
	}
	#endif
#endif