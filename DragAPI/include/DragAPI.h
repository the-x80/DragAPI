#pragma once
#ifndef DRAG_API_H
#define DRAG_API_H


#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#ifdef _WIN32
	#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
	#ifndef _WINDOWS_

/*
* Developer notes:
*	The windows header file should not be included since everything will be abstracted trough various classes.
*	Currently its included to provide functionality not yet implemented inside this API
*/
		#include <Windows.h>
	#endif
#endif

#include "../src/Debugging/Debug.h"

#include "../src/Math/Math.h"

#include "../src/Types/Types.h"

#include "../src/Exceptions/Exceptions.h"

#include "../src/Diagnostics/Diagnostics.h"

#include "../src/Array/Array.h"

#include "../src/DateTime.h"
#include "../src/Data Types/Color.h"
#include "../src/Data Types/Vectors.h"
#include "../src/Data Types/Quaternion.h"
#include "../src/Data Types/Matrix.h"
#include "../src/Data Types/Rect.h"
#include "../src/Data Types/Stack.h"
#include "../src/Data Types/String.h"

#include "../src/KeyCodes.h"

#include "../src/Event System/EventSystem.h"

#include "../src/Threading/Threading.h"

#include "../src/Localisation/Localisation.h"


#include "../src/DragAPI.Networking.h"

#include "../src/IO/IO.h"

#include "../src/Graphics/Graphics.h"

#include "../src/Injector.h"

#include "../src/Crypto/Crypto.h"

#include "../src/Text/Text.h"
#include "../src/HTML/HTML.h"

#include "../src/Application/Application.h"

#include "../src/Physics/Physics.h"


#endif