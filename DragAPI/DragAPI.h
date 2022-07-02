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

#include "DragAPI/Debugging/Debug.h"

#include "DragAPI/Math/Math.h"

#include "DragAPI/Types/Types.h"

#include "DragAPI/Exceptions/Exceptions.h"

#include "DragAPI/Diagnostics/Diagnostics.h"

#include "DragAPI/Array/Array.h"

#include "DragAPI/DateTime.h"
#include "DragAPI/Data Types/Color.h"
#include "DragAPI/Data Types/Vectors.h"
#include "DragAPI/Data Types/Quaternion.h"
#include "DragAPI/Data Types/Matrix.h"
#include "DragAPI/Data Types/Rect.h"
#include "DragAPI/Data Types/Stack.h"
#include "DragAPI/Data Types/String.h"

#include "DragAPI/KeyCodes.h"

#include "DragAPI/Event System/EventSystem.h"

#include "DragAPI/Threading/Threading.h"

#include "DragAPI/Localisation/Localisation.h"


#include "DragAPI/DragAPI.Networking.h"

#include "DragAPI/IO/IO.h"

#include "DragAPI/Graphics/Graphics.h"

#include "DragAPI/Injector.h"

#include "DragAPI/Crypto/Crypto.h"

#include "DragAPI/Text/Text.h"
#include "DragAPI/HTML/HTML.h"

#include "DragAPI/Application/Application.h"

#include "DragAPI/Physics/Physics.h"


#endif