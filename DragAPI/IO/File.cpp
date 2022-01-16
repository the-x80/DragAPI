#include "File.h"

#include "../Debug.h"

DragAPI::IO::File::File() :
	cstrFileName()
{
	n_size = 0;
	hFile = INVALID_HANDLE_VALUE;
	b_isFileOpen = false;
}

DragAPI::IO::File::File(const char* cstr_fName):
	cstrFileName(cstr_fName)
{
	
	n_size = 0;
	hFile = INVALID_HANDLE_VALUE;
	b_isFileOpen = false;
}

DragAPI::IO::File::~File()
{
	if (this->b_isFileOpen) {
		this->Close();
	}
}

bool DragAPI::IO::File::Open()
{
	this->hFile = CreateFile(this->cstrFileName, GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (this->hFile == INVALID_HANDLE_VALUE) {

	}
	return false;
}

bool DragAPI::IO::File::Close()
{
	CloseHandle(this->hFile);
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
