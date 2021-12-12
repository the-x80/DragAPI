#pragma once
#ifndef DRAG_API_TEXT_FILE_H
#define DRAG_API_TEXT_FILE_H
#include "File.h"


namespace DragAPI {
	namespace IO {
		class TextFile : protected File {
		private:
			std::string rawText;
		public:
			TextFile();
			TextFile(const char* fName);
			~TextFile();



			bool Read(char* text);

			bool Write(const char* text);
		};
	}
}


#endif