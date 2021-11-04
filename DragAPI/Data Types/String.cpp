#define _CRT_SECURE_NO_WARNINGS

#include "String.h"
#include "../Exceptions/Exceptions.h"


//TODO: Implement exception handling in constructors. The new keyword might throw an exception.


const DragAPI::String& DragAPI::String::EmptyString = String("");



DragAPI::String::String() :
	length(0),
	pData(new unsigned char[sizeof(char) * 0]),
	nDataSize(0),
	eEncoding(StringEncoding::UTF16)
{
}

DragAPI::String::String(const wchar_t* _text):
	length(wcslen(_text)),
	pData(new unsigned char[sizeof(wchar_t) * (this->length + 1)]),
	nDataSize(sizeof(wchar_t)* (this->length + 1)),
	eEncoding(StringEncoding::UTF16)
{
	memcpy(this->pData, _text, sizeof(wchar_t) * (this->length + 1));
}

DragAPI::String::String(const char* _text):
	length(strlen(_text)),
	pData(new unsigned char[sizeof(char) * (this->length + 1)]),
	nDataSize(sizeof(char)* (this->length + 1)),
	eEncoding(StringEncoding::ANSI)
{
	memcpy(this->pData, _text, sizeof(char) * (this->length + 1));
}

DragAPI::String::String(const Array<wchar_t>& charArray):
	length(charArray.Length()),
	pData(new unsigned char[sizeof(wchar_t) * (this->length + 1)]),
	nDataSize(sizeof(wchar_t)* (this->length + 1)),
	eEncoding(StringEncoding::UTF16)
{
	memcpy(this->pData, charArray.GetBufferPointer(), sizeof(wchar_t) * (this->length + 1));
}

DragAPI::String::String(const Array<char>& charArray) :
	length(charArray.Length()),
	pData(new unsigned char[sizeof(char) * (this->length + 1)]),
	nDataSize(sizeof(char)* (this->length + 1)),
	eEncoding(StringEncoding::ANSI)
{
	memcpy(this->pData, charArray.GetBufferPointer(), sizeof(char) * (this->length + 1));
}

DragAPI::String::String(String& other)
{
	throw new Exceptions::NotImplementedException();
}

DragAPI::String::String(String&& other) noexcept
{
	throw new Exceptions::NotImplementedException();
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

DragAPI::Array<char> DragAPI::String::ToCharArray() const
{
	char* data = new char[this->length+1];
	memset(data, 0, sizeof(char) * (this->length + 1));
	switch (this->eEncoding) {
	case StringEncoding::ANSI:
		memcpy(data, this->pData, sizeof(char) * (this->length + 1));
		break;
	case StringEncoding::UTF8:
		throw new Exceptions::NotImplementedException();
		break;
	case StringEncoding::UTF16:
		throw new Exceptions::NotImplementedException();
		break;
	case StringEncoding::UTF32:
		throw new Exceptions::NotImplementedException();
		break;
	}
	Array<char> returnValue = Array<char>(data, sizeof(char) * (this->length + 1));
	return returnValue;
}

DragAPI::Array<wchar_t> DragAPI::String::ToWCharArray() const
{
	throw new Exceptions::NotImplementedException();
	return Array<wchar_t>();
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

DragAPI::Array<DragAPI::String> DragAPI::String::Split(const char delimiter)
{
	throw new Exceptions::NotImplementedException();
	return Array<String>();
}

DragAPI::Array<DragAPI::String> DragAPI::String::Split(String& delimiters)
{
	throw new Exceptions::NotImplementedException();
	return Array<String>();
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
	case StringEncoding::ANSI:
		memcpy(convertedString, this->pData, sizeof(char) * (this->length + 1));
		break;
	case StringEncoding::UTF8:
		throw new Exceptions::NotImplementedException();
		break;
	case StringEncoding::UTF16:
		wcstombs(convertedString, (wchar_t*)this->pData, this->length);
		break;
	case StringEncoding::UTF32:
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
	case StringEncoding::ANSI:
		mbstowcs(convertedString, (const char*)this->pData, this->length);
		break;
	case StringEncoding::UTF8:
		throw new Exceptions::NotImplementedException();
		//mbstowcs(convertedString, (const char*)this->pData, this->length);
		break;
	case StringEncoding::UTF16:
		memcpy(convertedString, this->pData, sizeof(wchar_t) * (this->length + 1));
		break;
	case StringEncoding::UTF32:
		throw new Exceptions::NotImplementedException();
		break;
	}
	return (wchar_t*)convertedString;
}

