#pragma once
#ifndef DRAG_API_LANGUAGE_H
#define DRAG_API_LANGUAGE_H

namespace DragAPI {
	namespace Localisation {
		class Language {
		private:
			unsigned int ID;
			wchar_t* name;
		public:
			Language();
			Language(Language& other);
			Language(Language&& other);
			~Language();
		};
	}
}

#endif