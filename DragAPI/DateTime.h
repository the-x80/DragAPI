#ifndef DRAG_API_DATE_TIME_H
#define DRAG_API_DATE_TIME_H

//Developer notes.
//Instead of allowing of direct access to the variables implement getters.

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
	};
}


#endif
