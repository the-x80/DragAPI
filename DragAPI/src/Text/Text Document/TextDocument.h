#pragma once
#ifndef DRAG_API_TEXT_DOCUMENT_H
#define DRAG_API_TEXT_DOCUMENT_H

#include <vector>
#include <string>

namespace DragAPI {
	namespace Text {
		class TextDocument {
		private:
			char* rawText;
			long length;
		protected:
		public:
			TextDocument();
			TextDocument(TextDocument& other);
			TextDocument(TextDocument&& other);
			~TextDocument();


			bool Load(char* text);
			bool Load(const char* text);


			bool LoadFromFile(char* fName);
			bool LoadFromFile(const char* fName);
		};
	}
}

#endif