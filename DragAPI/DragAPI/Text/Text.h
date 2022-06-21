#pragma once
#ifndef DRAG_API_TEXT_H
#define DRAG_API_TEXT_H

#include "Text Document/TextDocument.h"

namespace DragAPI {
	namespace Text {
		enum class Encoding {
			ANSI,
			UTF8,
			UTF16,
			UTF32
		};
	}
}

#endif