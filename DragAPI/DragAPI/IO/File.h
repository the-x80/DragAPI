#ifndef DRAG_API_FILE_H
#define DRAG_API_FILE_H

#include <array>
#include <vector>

#ifndef _WINDOWS_
#include <Windows.h>
#endif

#include "../Data Types/String.h"

#include "../Array/Array.h"
#include "../Exceptions/Exceptions.h"

namespace DragAPI {
	namespace IO {
		class File {
		private:
			::DragAPI::String cstrFileName;
			HANDLE hFile;

			long n_size;

			bool b_isFileOpen;
		public:
			File();
			File(const char* cstr_fName);
			~File();


			bool Open();
			bool Close();

			long GetSize();

			bool Read(void* buffer, int bufferSize);
			bool Read(std::vector<BYTE>);

			bool Write(void* buffer, int bufferSize);
			bool Write(std::vector<BYTE>);
		};


		class FileStream {
		private:
			char* cstrFileName;
			HFILE hFile;

			long cursorPos;
			long n_size;
		public:
			FileStream();

			bool Open();
			bool Close();

			bool SetCursorPosition(long position);

			BYTE ReadByte();

			short ReadShort();

			int ReadInt();

			long ReadLong();

			float ReadFloat();
		};
	}
}


#endif