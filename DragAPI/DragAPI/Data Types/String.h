#ifndef DRAG_API_STRING_H
#define DRAG_API_STRING_H

#include <vector>
#include <array>
#include <string>
#include "../Text/Text.h"
#include "../Array/Array.h"//Outdated

namespace DragAPI {
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