#ifndef DRAG_API_FILE_H
#define DRAG_API_FILE_H

#ifndef _WINDOWS_
#include <Windows.h>
#endif

#include "../Array/Array.h"
#include "../Exceptions/Exceptions.h"

namespace DragAPI {
	namespace IO {
		class File {
		private:
			char* cstrFileName;
			HFILE hFile;

			long n_size;
		public:
			File();
			File(const char* cstr_fName);
			~File();


			bool Open();
			bool Close();

			long GetSize();

			bool Read(void* buffer, int bufferSize);
			bool Read(Array<void>* buffer);

			bool Write(void* buffer, int bufferSize);
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