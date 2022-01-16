#pragma once
#ifndef DRAG_API_H
#define DRAG_API_H


#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#ifdef _WIN32
	#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
	#ifndef _WINDOWS_
		#include <Windows.h>
	#endif
#endif

#include "Math/Math.h"

#include "Data Types/String.h"

#include "Exceptions/Exceptions.h"

#include "Diagnostics/Diagnostics.h"

#include "Debug.h"

#include "Array/Array.h"

#include "DateTime.h"
#include "Data Types/Color.h"
#include "Data Types/Vectors.h"
#include "Data Types/Quaternion.h"
#include "Data Types/Rect.h"
#include "Data Types/Stack.h"

#include "Event System/EventSystem.h"

#include "Localisation/Localisation.h"


#include "DragAPI.Networking.h"

#include "IO/IO.h"

#include "Graphics/Graphics.h"

#include "Injector.h"

#include "Crypto/Crypto.h"

#include "Text/Text.h"
#include "HTML/HTML.h"

#include "Graphics/GraphicsRenderingEngine.h"

#include "Application/Application.h"

namespace DragAPI {
	static const char APIVersion[5] = "0.1b";
}




#ifdef _WIN32
	#define APPLICATION_ENTRY_POINT int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#else
	#define APPLICATION_ENTRY_POINT main()
#endif



#endif