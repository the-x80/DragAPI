#ifndef DRAG_API_JSON_H
#define DRAG_API_JSON_H

#include "../Array/Array.h"
#include "../IO/IO.h"


namespace DragAPI {
	namespace JSON {
		class JsonEntry {
		public:
			char* cstrName;
		};

		class JsonValue : public JsonEntry{

		};
		class JsonObject : public JsonEntry{

		};

		class JsonDocument {
		private:

		public:
			JsonDocument();
		};
	}
}


#endif