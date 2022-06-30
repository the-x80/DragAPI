#pragma once


namespace DragAPI {
	class DateTime {
	public:
		unsigned char m_Year, m_Month, m_Day;
		unsigned char m_Hour, m_Minute, m_Second;


		DateTime();


		static DateTime Now();
	};
}