#ifndef DRAG_API_VECTOR3_H
#define DRAG_API_VECTOR3_H



namespace DragAPI {
	/// <summary>
	/// Base class for all vectors
	/// </summary>
	class Vector {
	public:
		Vector();
	};

	/// <summary>
	/// Generic Vector3 structure using floats for components.
	/// 
	/// Kept for backwards compatibility.
	/// </summary>
	class Vector3 : public Vector
	{
	public:
		float x, y, z;


		Vector3();
		Vector3(float _x, float _y, float _z);

		Vector3 Normalized();
		float MagnitudeSquared();
		float Magnitude();

		static float Dot(Vector3 v1, Vector3 v2);
		static Vector3 Cross(Vector3 v1, Vector3 v2);

		float Distance(Vector3 v1, Vector3 v2);



		Vector3 operator +(Vector3 other);
		Vector3 operator -(Vector3 other);
		Vector3 operator *(float other);
		Vector3 operator /(float other);
		bool operator ==(Vector3 other);
		bool operator !=(Vector3 other);

	};





	class Vector3Float : public Vector{
	public:
		float x, y, z;

		Vector3Float();
		Vector3Float(float _x, float _y, float _z);
	};
	class Vector3Double {
		double x, y, z;
	};
	class Vector3Byte {
		unsigned char x, y, z;
	};
	class Vector3Short {
		short x, y, z;
	};
	class Vector3Int {
		int x, y, z;
	};
	class Vector3Long {
		long x, y, z;
	};
	class Vector3UShort {
		unsigned short x, y, z;
	};
	class Vector3UInt {
		unsigned int x, y, z;
	};
	class Vector3ULong {
		unsigned long x, y, z;
	};

}
#endif