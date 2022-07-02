#define _CRT_SECURE_NO_WARNINGS

#include "String.h"
#include "../Exceptions/Exceptions.h"


//TODO: Implement exception handling in constructors. The new keyword might throw an exception.


DragAPI::string::string():
	std::string()
{
}

DragAPI::string::string(const char* cstr):
	std::string(cstr)
{
}

DragAPI::string::~string()
{
}

void DragAPI::string::format(std::string& format, ...)
{
	
}

void DragAPI::string::replace_all(std::string& token, std::string& replace)
{
	
}

std::vector<std::string> DragAPI::string::split(const char delimiter, int startindex)
{
	return std::vector<std::string>();
}
