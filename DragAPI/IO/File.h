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
			String cstrFileName;
			HFILE hFile;

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
			bool Read(Array<void>* buffer);

			bool Write(void* buffer, int bufferSize);
			bool Write(std::vector<BYTE>);
			bool Write(Array<void>* buffer);
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
			Array<BYTE> ReadByteArray(long count);

			short ReadShort();
			Array<short> ReadShortArray(long count);

			int ReadInt();
			Array<int> ReadIntArray(long count);

			long ReadLong();
			Array<long> ReadLongArray(long count);

			float ReadFloat();
			Array<float> ReadFloatArray(long count);
		};
	}
}


#endif