//TODO:DateTime class is not platform agnostic. Currently only Windows is supported

#include "DateTime.h"

/// <summary>
/// Constructs a default DateTime object
/// </summary>
DragAPI::DateTime::DateTime()
{
	//This function is platform agnostic
	this->millisecond = 0;
	this->second = 0;
	this->minute = 0;
	this->hour = 0;
	this->day = 1;
	this->month = 1;
	this->year = 1970;
}




#ifdef _WIN32
#include <Windows.h>




int DragAPI::DateTime::GetUnixEpoch()
{
	throw new DragAPI::Exceptions::NotImplementedException();
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
#else

#endif