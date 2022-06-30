#define _CRT_SECURE_NO_WARNINGS

#include "String.h"
#include "../Exceptions/Exceptions.h"


//TODO: Implement exception handling in constructors. The new keyword might throw an exception.


const DragAPI::String& DragAPI::String::EmptyString = String("");



DragAPI::String::String() :
	length(0),
	pData(new unsigned char[sizeof(char) * 0]),
	nDataSize(0),
	eEncoding(DragAPI::Text::Encoding::UTF16)
{
}

DragAPI::String::String(const wchar_t* _text):
	length(wcslen(_text)),
	pData(new unsigned char[sizeof(wchar_t) * (this->length + 1)]),
	nDataSize(sizeof(wchar_t)* (this->length + 1)),
	eEncoding(DragAPI::Text::Encoding::UTF16)
{
	memcpy(this->pData, _text, sizeof(wchar_t) * (this->length + 1));
}

DragAPI::String::String(const char* _text):
	length(strlen(_text)),
	pData(new unsigned char[sizeof(char) * (this->length + 1)]),
	nDataSize(sizeof(char)* (this->length + 1)),
	eEncoding(DragAPI::Text::Encoding::ANSI)
{
	memcpy(this->pData, _text, sizeof(char) * (this->length + 1));
}

DragAPI::String::String(String& other)
{
	//throw new Exceptions::NotImplementedException();
}

DragAPI::String::String(String&& other) noexcept
{
	//throw new Exceptions::NotImplementedException();
}

DragAPI::String::~String()
{
	delete[] this->pData;
	this->length = 0;
}

unsigned long DragAPI::String::Length() const
{
	return this->length;
}

wchar_t& DragAPI::String::GetWCharAtIndex(unsigned long index)
{
	throw new Exceptions::NotImplementedException();
	// TODO: insert return statement here
	return (wchar_t&)this->pData[0];
}

char& DragAPI::String::GetCharAtIndex(unsigned long index)
{
	throw new Exceptions::NotImplementedException();
	// TODO: insert return statement here
	return (char&)this->pData[0];
}

bool DragAPI::String::Contains(String& other)
{
	throw new Exceptions::NotImplementedException();
	return false;
}

unsigned int DragAPI::String::Find(String& other)
{
	throw new Exceptions::NotImplementedException();
	return 0;
}

DragAPI::String DragAPI::String::PadLeft(unsigned long ammount, const char character)
{
	throw new Exceptions::NotImplementedException();
	return String();
}

DragAPI::String DragAPI::String::PadRight(unsigned long ammount, const char character)
{
	throw new Exceptions::NotImplementedException();
	return String();
}

DragAPI::String DragAPI::String::TrimLeft(unsigned long ammount)
{
	throw new Exceptions::NotImplementedException();
	return String();
}

DragAPI::String DragAPI::String::TrimRight(unsigned long ammount)
{
	throw new Exceptions::NotImplementedException();
	return String();
}

DragAPI::String DragAPI::String::Concat(String& other)
{
	throw new Exceptions::NotImplementedException();
	return String();
}

bool DragAPI::String::Equals(String& other) const
{
	throw new Exceptions::NotImplementedException();
	return false;
}

DragAPI::String::operator char*() const
{
	char* convertedString = new char[this->length + 1];
	memset(convertedString, 0, sizeof(char) * (this->length + 1));

	switch (this->eEncoding) {
	case DragAPI::Text::Encoding::ANSI:
		memcpy(convertedString, this->pData, sizeof(char) * (this->length + 1));
		break;
	case DragAPI::Text::Encoding::UTF8:
		throw new Exceptions::NotImplementedException();
		break;
	case DragAPI::Text::Encoding::UTF16:
		wcstombs(convertedString, (wchar_t*)this->pData, this->length);
		break;
	case DragAPI::Text::Encoding::UTF32:
		throw new Exceptions::NotImplementedException();
		break;
	}
	return convertedString;
}

DragAPI::String::operator wchar_t*() const
{
	wchar_t* convertedString = new wchar_t[this->length+1];
	memset(convertedString, 0, sizeof(wchar_t) * (this->length + 1));
	switch (this->eEncoding) {
	case DragAPI::Text::Encoding::ANSI:
		mbstowcs(convertedString, (const char*)this->pData, this->length);
		break;
	case DragAPI::Text::Encoding::UTF8:
		throw new Exceptions::NotImplementedException();
		//mbstowcs(convertedString, (const char*)this->pData, this->length);
		break;
	case DragAPI::Text::Encoding::UTF16:
		memcpy(convertedString, this->pData, sizeof(wchar_t) * (this->length + 1));
		break;
	case DragAPI::Text::Encoding::UTF32:
		throw new Exceptions::NotImplementedException();
		break;
	}
	return (wchar_t*)convertedString;
}

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
