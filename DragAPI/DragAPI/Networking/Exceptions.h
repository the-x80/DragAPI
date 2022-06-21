#pragma once
#include "../Exceptions/Exceptions.h"


namespace DragAPI {
	namespace Network {
		namespace Exception {
			class NetworkException : public DragAPI::Exceptions::Exception {
			private:
				errno_t m_WinSockLastError;
			};
		}
	}
}