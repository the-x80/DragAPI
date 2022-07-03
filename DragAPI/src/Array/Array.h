#ifndef ARRAY_H
#define ARRAY_H

//Developer notes
//	-Switch from using new to using malloc. Slight speed increase.
//	-The Clear function needs a better implementation. See inside the function block for more info.
//Changelog
//28.8::
//	-Added Clear function to the Array class.
//15.9.2021::
//	-Added exception handling to the Add function when allocating memory for the resized array
//	-Switched memory allocation from new to malloc
//	-Switched memory deallocation from delete to free

#include "../Exceptions/Exceptions.h"

//TODO:Make the reservedSize and reservedLength feature work. Currently its not implemented.


namespace DragAPI {
	namespace Exceptions {
		class ArrayEmptyException : public ::DragAPI::Exceptions::Exception {
		public:
			ArrayEmptyException();
			ArrayEmptyException(char* msg);
		};
	}
}
#endif