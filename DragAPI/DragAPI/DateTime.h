#ifndef DRAG_API_DATE_TIME_H
#define DRAG_API_DATE_TIME_H

//Developer notes.
//Instead of allowing of direct access to the variables implement getters.
#ifdef _WIN32
	#ifndef _WINDOWS_
		#include <Windows.h>
	#endif
#endif

#include "Exceptions/Exceptions.h"


namespace DragAPI {

	class DateTime;



	namespace Exceptions {
		class InvalidDateTime : public Exception {
		public:
			InvalidDateTime();
		};
	}


	class DateTime {
	public:
		int millisecond;
		int second;
		int minute;
		int hour;
		int day;
		int month;
		int year;


		DateTime();

		int GetUnixEpoch();

		static DragAPI::DateTime Now();

#pragma region DateTime Operators

#ifdef _WIN32
		DateTime operator =(SYSTEMTIME other);
#endif
#pragma endregion
	};
}


#endif
