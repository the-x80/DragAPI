#ifndef TYPE_INFO_H
#define TYPE_INFO_H

#include "InfoObject.h"


namespace DragAPI {
	namespace Diagnostics {
		class TypeInfo : public InfoObject {
		public:
			std::string m_TypeName;
			TypeInfo* m_BaseType;
		};
		class DebugTypeInfo : public TypeInfo {
		public:
			char* cstr_SourceFileDirectory;
			char* cstr_SourceFileName;
			int n_SourceFileLineNumber;
		};
	}
}
#endif