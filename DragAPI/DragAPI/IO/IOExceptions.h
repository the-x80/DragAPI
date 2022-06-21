#pragma once
#include "../Exceptions/Exceptions.h"


namespace DragAPI {
	namespace Exceptions {
		class IOException : public ::DragAPI::Exceptions::Exception {
		public:
			IOException();
		};
	}
}