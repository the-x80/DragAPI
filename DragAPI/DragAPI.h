#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#ifndef _WINDOWS_
#include <Windows.h>
#endif

#include <d3d9.h>
#include <d3d10_1.h>
#include <d3d11.h>
#include <d3d12.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3d10_1.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3d12.lib")

#include "Exceptions/Exceptions.h"

#include "StackTrace.h"

#include "Debug.h"

#include "Array/Array.h"

#include "DateTime.h"
#include "Vectors.h"
#include "Quaternion.h"

#include "DragAPI.Networking.h"

#include "Window.h"


namespace DragAPI {
	static const char version[5] = "0.1b";
}