#pragma once
#ifndef DRAG_API_LOCALISED_STRING_H
#define DRAG_API_LOCALISED_STRING_H

#include <string>
#include<vector>
#include "Language.h"

namespace DragAPI {
	namespace Localisation {
		class LocalisedString {
		private:
			std::vector<Language*> languages;
			std::vector<std::string> strings;
		public:
			LocalisedString();
			LocalisedString(LocalisedString& other);
			LocalisedString(LocalisedString&& other) noexcept;
			~LocalisedString();
		};
	}
}

#endif