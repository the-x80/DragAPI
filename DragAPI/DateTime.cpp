#include "DateTime.h"
#include <Windows.h>


DragAPI::DateTime::DateTime()
{
	this->millisecond = 0;
	this->second = 0;
	this->minute = 0;
	this->hour = 0;
	this->day = 1;
	this->month = 1;
	this->year = 1970;
}

int DragAPI::DateTime::GetUnixEpoch()
{
	return 0;
}

DragAPI::DateTime DragAPI::DateTime::Now()
{
	DragAPI::DateTime retVal;
	SYSTEMTIME st;
	GetSystemTime(&st);

	retVal.millisecond = st.wMilliseconds;
	retVal.second = st.wSecond;
	retVal.minute = st.wMinute;
	retVal.hour = st.wHour;
	retVal.day = st.wDay;
	retVal.month = st.wMonth;
	retVal.year = st.wYear;
	return retVal;
}

DragAPI::Exceptions::InvalidDateTime::InvalidDateTime()
{
	
}
