#include "String.h"
#include "../Exceptions/Exceptions.h"
#include <stdio.h>

//TODO: Implement exception handling in constructors. The new keyword might throw an exception.

DragAPI::String::String()
{
	this->length = 0;
	this->text = nullptr;
}

DragAPI::String::String(const wchar_t* _text)
{
	this->length = wcslen(_text);
#ifdef UNICODE
	this->text = new wchar_t[this->length + 1];
	memset(this->text, 0, sizeof(wchar_t) * (this->length + 1));

	memcpy(
		this->text,
		_text,
		sizeof(wchar_t) * (this->length + 1)
	);
#else
	this->text = new char[this->length + 1];
	memset(this->text, 0, sizeof(char) * (this->length + 1));

	int len = wcstombs(this->text, _text, sizeof(char) * (this->length + 1));
#endif
	
}

DragAPI::String::String(const char* _text)
{
	this->length = strlen(_text);
#ifdef UNICODE
	this->text = new wchar_t[this->length + 1];
	memset(this->text, 0, sizeof(wchar_t) * (this->length + 1));
	int len = mbstowcs(this->text, _text, this->length + 1);
#else
	this->text = new char[this->length + 1];
	memset(this->text, 0, sizeof(char) * (this->length + 1));

	memcpy(
		this->text,
		_text,
		sizeof(char) * (this->length + 1)
	);
#endif
}

DragAPI::String::String(String& other)
{
	this->length = other.length;
#ifdef UNICODE
	this->text = new wchar_t[this->length + 1];
	memset(this->text, 0, sizeof(wchar_t) * (this->length + 1));
	memcpy(this->text, other.text, sizeof(wchar_t)*(this->length+1));
#else
	this->text = new char[this->length + 1];
	memset(this->text, 0, sizeof(char) * (this->length + 1));
	memcpy(this->text, other.text, sizeof(char) * (this->length + 1));
#endif
}

DragAPI::String::String(String&& other) noexcept
{
	throw new Exceptions::NotImplementedException();
}

DragAPI::String::~String()
{
	delete[] this->text;
	this->length = 0;
}

DragAPI::String::operator char*()
{
	throw new Exceptions::NotImplementedException();
#ifdef UNICODE
	
#else

#endif
}

DragAPI::String::operator wchar_t*()
{
#ifdef UNICODE
	return this->text;
#else
	throw new Exceptions::NotImplementedException();
#endif
}
