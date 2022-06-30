#ifndef DRAG_API_STRING_H
#define DRAG_API_STRING_H

#include <vector>
#include <array>
#include <string>
#include "../Text/Text.h"
#include "../Array/Array.h"//Outdated

namespace DragAPI {
	class CStringA;
	class CStringW;


	class String {
	private:
		/// <summary>
		/// The length of the string in characters.
		/// </summary>
		unsigned long length;

		/// <summary>
		/// Holds the character data of the string.
		/// Its the raw bytes so depending on the encoding the data held is different.
		/// Must never be nullptr.
		/// </summary>
		unsigned char* pData;

		/// <summary>
		/// Describes the size in memory of this string object.
		/// </summary>
		unsigned long nDataSize;

		/// <summary>
		/// Holds information about the strings encoding.
		/// </summary>
		DragAPI::Text::Encoding eEncoding;
	public:
		static const String& EmptyString;





		String();
		String(const wchar_t* _text);
		String(const char* _text);

		String(String& other);
		String(String&& other) noexcept;

		~String();

		/// <summary>
		/// Returns the length of the string in characters.
		/// </summary>
		/// <returns>Length of the String</returns>
		unsigned long Length() const;

		wchar_t& GetWCharAtIndex(unsigned long index);
		char& GetCharAtIndex(unsigned long index);


		bool Contains(String& other);
		bool ContainsWord(String& other);
		unsigned int Find(String& other);

		String PadLeft(unsigned long ammount, const char character);
		String PadRight(unsigned long ammount, const char character);

		String TrimLeft(unsigned long ammount);
		String TrimRight(unsigned long ammount);

		String Concat(String& other);

		bool SetEncoding(DragAPI::Text::Encoding encoding);

		/// <summary>
		/// Checks this string against another one.
		/// Performs a character by character check and returns true if all of the characters are equal.
		/// </summary>
		/// <param name="other">The other string to be chacked against.</param>
		/// <returns>Returns true if the two strings are equal.</returns>
		bool Equals(String& other) const;

		operator char*() const;
		operator wchar_t*() const;

	};

	


	class CStringA {
	private:
		char* data;
		size_t reservedSpace;
		size_t stringLength;
	public:
		CStringA();
		CStringA(const char* str);
		CStringA(CStringW& other);
		CStringA(CStringA& other);
		CStringA(CStringA&& other);
		~CStringA();


		void ReserveSize(size_t size);


		size_t Length();
	};
	class CStringW {
	private:
		wchar_t* data;
	public:

	};


	class string : public ::std::string {
	public:
		string();
		string(const char* cstr);
		~string();

		void format(::std::string& format, ...);

		int find(::std::string& token);
		::std::vector<int> find_all(::std::string& token);

		void replace(::std::string& token, ::std::string& replace);
		void replace_all(::std::string& token, ::std::string& replace);

		::std::vector<::std::string> split(const char delimiter, int startindex=0);

		int parse_int(size_t startPos, size_t length);
		int parse_float(size_t startPos, size_t length);

		::std::wstring& convert_to_wstring();
	};
	class wstring : public ::std::wstring {

	};
}

#endif