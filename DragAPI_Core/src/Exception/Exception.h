#pragma once
#include <stdexcept>
namespace DragAPI {
	class Exception : public std::exception{
	public:
		virtual ~Exception() {};
	};
}