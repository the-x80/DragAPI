#include "Exceptions.h"
#ifdef _WIN32
#ifdef _WIN32_WINNT
#undef _WIN32_WINNT
#endif

#define _WIN32_WINNT 0x0400

#include <Windows.h>
#include <TlHelp32.h>
#include <DbgHelp.h>

#pragma comment(lib, "Dbghelp.lib")
#endif
#include "../Debugging/Debug.h"
#include "../Diagnostics/Diagnostics.h"




#pragma region Exception Window
class ExceptionWindow {
public:
	HWND hwnd_Handle;
	RECT r_Rect;
	DragAPI::Exceptions::Exception* e_DisplayingException;

	inline ExceptionWindow() {
		hwnd_Handle = (HWND)INVALID_HANDLE_VALUE;
		r_Rect = RECT();
		e_DisplayingException = nullptr;
	}



	void Create() {

	}
};
#pragma endregion














DragAPI::Exceptions::Exception::Exception() noexcept
{
	n_WindowsLastErrorCode = GetLastError();
	
	this->message = new char[0];
	this->cstr_FullMessage = new char[0];

	this->n_SourceFileLine = 0;

	//Note StackTrace does not have full functionality for now.
	this->stackTrace = DragAPI::Diagnostics::StackTrace::Create(1);
}

DragAPI::Exceptions::Exception::Exception(const char* msg) noexcept
{
	n_WindowsLastErrorCode = GetLastError();

	size_t n_MessageLength = strlen(msg);
	try {
		this->message = new char[n_MessageLength + 1];
	}
	catch (std::bad_alloc e) {
	}
	memset(this->message, 0, n_MessageLength+1);
	memcpy_s(this->message, n_MessageLength, msg, n_MessageLength);

	this->cstr_FullMessage = new char[0];

	this->stackTrace = DragAPI::Diagnostics::StackTrace::Create(1);

	//this->mi_Method = DebugMethodInfo();

	this->n_SourceFileLine = 0;
}

DragAPI::Exceptions::Exception::~Exception()
{
	delete[] this->message;
	delete[] this->cstr_FullMessage;
	delete this->stackTrace;
}

const char* DragAPI::Exceptions::Exception::what() const
{
	return "Unhandeled exception";
}

char* DragAPI::Exceptions::Exception::ToString()
{
	return this->cstr_FullMessage;
}

void DragAPI::Exceptions::Exception::PrintToOutput()
{
}

DragAPI::Exceptions::NullPointerException::NullPointerException() noexcept
{
}

DragAPI::Exceptions::NullPointerException::NullPointerException(const char* msg) noexcept : DragAPI::Exceptions::Exception::Exception(msg)
{
}

DragAPI::Exceptions::NullPointerException::~NullPointerException()
{
}

DragAPI::Exceptions::BadAllocationException::BadAllocationException()
{
}

DragAPI::Exceptions::BadAllocationException::BadAllocationException(const char* msg) : DragAPI::Exceptions::Exception(msg)
{
}

DragAPI::Exceptions::OutOfMemoryException::OutOfMemoryException()
{
}

DragAPI::Exceptions::ArgumentNullException::ArgumentNullException()
{
}

//TODO:Implement InvalidArgumentException
DragAPI::Exceptions::InvalidArgumentException::InvalidArgumentException()
{
}

DragAPI::Exceptions::InvalidArgumentException::InvalidArgumentException(std::string message)
{
}

DragAPI::Exceptions::IndexOutOfBoundsException::IndexOutOfBoundsException()
{
}

DragAPI::Exceptions::DivisionByZeroException::DivisionByZeroException()
{
}

DragAPI::Exceptions::NotImplementedException::NotImplementedException()
{
}


