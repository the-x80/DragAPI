#ifndef DRAG_API_JSON_H
#define DRAG_API_JSON_H

#include "../Data Types/String.h"
#include "../Array/Array.h"
#include "../IO/IO.h"


namespace DragAPI {
	namespace JSON {
		class JsonEntry {
		private:
			String rawText;
		public:
			char* cstrName;

			virtual void Parse(String& text);
		};

		class JsonValue : public JsonEntry{
		private:

		public:

			void Parse(String& text) override;
		};
		class JsonObject : public JsonEntry{
		private:
			Array<JsonEntry> entries;
		public:

			void Parse(String& text) override;
		};

		class JsonDocument {
		private:
			String rawText;
			Array<JsonEntry> entries;
		public:
			JsonDocument();
			~JsonDocument();


			void LoadFromText(String& text);
			void LoadFromFile(String& fname);
		};
	}
}


#endif