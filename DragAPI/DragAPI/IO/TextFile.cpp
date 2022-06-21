#define _CRT_SECURE_NO_WARNINGS
#include "TextFile.h"

DragAPI::IO::TextFile::TextFile() : rawText("")
{
}

DragAPI::IO::TextFile::TextFile(const char* fName) : rawText(""), File::File(fName)
{
}

DragAPI::IO::TextFile::~TextFile()
{
}

bool DragAPI::IO::TextFile::Read(char* text)
{
	long n_FileSize = this->GetSize();
	char* buffer = new char[n_FileSize+1];
	ZeroMemory(buffer, n_FileSize + 1);

	bool b_ReadResult = ((File*)this)->Read(buffer, n_FileSize);
	if (b_ReadResult == false) {
		delete[] buffer;
		return false;
	}

	strcpy(text, buffer);
	delete[] buffer;
	return true;
}

bool DragAPI::IO::TextFile::Write(const char* text)
{
	return false;
}
