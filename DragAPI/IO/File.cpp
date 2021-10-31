#include "File.h"

DragAPI::IO::File::File()
{
	cstrFileName = nullptr;
	hFile = (HFILE)INVALID_HANDLE_VALUE;
}

DragAPI::IO::File::File(const char* cstr_fName)
{
	cstrFileName = nullptr;
	hFile = (HFILE)INVALID_HANDLE_VALUE;
}

DragAPI::IO::File::~File()
{
	if (this->cstrFileName != nullptr) {
		delete[] this->cstrFileName;
	}
}

bool DragAPI::IO::File::Open()
{
	return false;
}

bool DragAPI::IO::File::Close()
{
	return false;
}

bool DragAPI::IO::File::Read(void* buffer, int bufferSize)
{
	return false;
}

bool DragAPI::IO::File::Write(void* buffer, int bufferSize)
{
	return false;
}
