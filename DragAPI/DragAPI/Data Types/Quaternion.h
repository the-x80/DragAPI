#ifndef DRAG_API_QUATERNION_H
#define DRAG_API_QUATERNION_H
#include "Vectors.h"


namespace DragAPI {
	
	class Quaternion
	{
	public:
		float x, y, z, w;
		Quaternion();
		Quaternion(float _w, float _x, float _y, float _z);

		DragAPI::Vector3 ToEulerAngles();
		void FromEulerAngles(DragAPI::Vector3 angles);

		//Implement operators
	};
}
#endif
