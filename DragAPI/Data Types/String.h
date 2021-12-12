#ifndef DRAG_API_STRING_H
#define DRAG_API_STRING_H

#include <vector>
#include <array>
#include <string>
#include "../Text/Text.h"
#include "../Array/Array.h"//Outdated

namespace DragAPI {
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
		String(const Array<wchar_t>& charArray);
		String(const Array<char>& charArray);

		String(String& other);
		String(String&& other) noexcept;

		~String();

		/// <summary>
		/// Returns the length of the string in characters.
		/// </summary>
		/// <returns>Length of the String</returns>
		unsigned long Length() const;

		/// <summary>
		/// Converts this string to a char array.
		/// </summary>
		/// <returns>An Array object populated with char data from the string.</returns>
		Array<char> ToCharArray() const;
		/// <summary>
		/// Converts this string to a wide char array.
		/// </summary>
		/// <returns>An Array object populated with wide char data from the string.</returns>
		Array<wchar_t> ToWCharArray() const;

		wchar_t& GetWCharAtIndex(unsigned long index);
		char& GetCharAtIndex(unsigned long index);


		bool Contains(String& other);
		bool ContainsWord(String& other);
		unsigned int Find(String& other);

		Array<String> Split(const char delimiter);
		Array<String> Split(String& delimiters);

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
}

#endif