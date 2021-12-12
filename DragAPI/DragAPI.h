#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#ifndef _WINDOWS_
#include <Windows.h>
#endif

#include "Math/Math.h"

#include "Data Types/String.h"

#include "Exceptions/Exceptions.h"

#include "Diagnostics/Diagnostics.h"

#include "Debug.h"

#include "Array/Array.h"

#include "DateTime.h"
#include "Data Types/Vectors.h"
#include "Data Types/Quaternion.h"

#include "DragAPI.Networking.h"

#include "IO/IO.h"

#include "Graphics/Graphics.h"

#include "Injector.h"

#include "Text/Text.h"
#include "HTML/HTML.h"

namespace DragAPI {
	static const char version[5] = "0.1b";
}