#ifndef DRAG_API_STRING_H
#define DRAG_API_STRING_H

namespace DragAPI {
	class String {
	private:
		long length;
#ifdef UNICODE
		wchar_t* text;
#else
		char* text;
#endif
	public:
		String();
		String(const wchar_t* _text);
		String(const char* _text);

		String(String& other);
		String(String&& other) noexcept;

		~String();

		operator char*();
		operator wchar_t*();
	};
}

#endif