#ifndef DRAG_API_VECTOR3_H
#define DRAG_API_VECTOR3_H
#include <cstdarg>
#include <math.h>



namespace DragAPI {
	/// <summary>
	/// Base class for all vectors
	/// </summary>

	template <typename T, size_t N> class Vector {
		T components[N];


	public:
		Vector() {
			for (int i = 0; i < N; i++) {
				memset(components[i], 0, sizeof(T));
			}
		}
		Vector(T comps[N]) {
			memcpy(components, comps, sizeof(T) * N);
		}
		Vector(...) {
			std::va_list args;
			int argCount = N;
			va_start(args, argCount);
			for (int i = 0; i < N; i++) {
				this->components[i] = va_arg(args, T);
			}
			va_end(args);
		}
		Vector(Vector& other) {
			if (this->ComponentCount() == other.ComponentCount()) {
				memcpy(components, other.components, sizeof(T) * N);
				return;
			}
		}
		Vector(Vector&& other) {

		}

		void Normalize() {

		}
		Vector<T, N> Normalized() {
			Vector<T, N> retVal = Vector<T,N>(this->components);
			return retVal.Normalize();
		}
		float Magnitude() {
			float retVal = 0.0f;
			for (size_t i = 0; i < N; i++) {
				retVal += components[i] * components[i];
			}
			retVal = sqrt(retVal);
			return retVal;
		}
		double MagnitudeDouble() {
			double retVal = 0.0d;
			for (size_t i = 0; i < N; i++) {
				retVal += components[i] * components[i];
			}
			retVal = sqrt(retVal);
			return retVal;
		}

		float Dot() {

		}

		size_t ComponentCount() { return N; };



		T& operator[](size_t index) { return this->components[index]; }

		Vector<T, N> operator+(Vector<T, N> other) {
			Vector<T, N> retVal = Vector(this->components);
			for (size_t i = 0; i < N; i++) {
				retVal.components[i] += other.components[i];
			}
			return retVal;
		}
		Vector<T, N> operator-(Vector<T, N> other) {
			Vector<T, N> retVal = Vector<T, N>(this->components);
			for (size_t i = 0; i < N; i++) {
				retVal.components[i] -= other.components[i];
			}
			return retVal;
		}
		Vector<T, N> operator*(short other) {
			Vector<T, N> retVal = Vector<T, N>(this->components);
			for (size_t i = 0; i < N; i++) {
				retVal.components[i] *= other;
			}
			return retVal;
		}
		Vector<T, N> operator*(int other) {
			Vector<T, N> retVal = Vector<T, N>(this->components);
			for (size_t i = 0; i < N; i++) {
				retVal.components[i] *= other;
			}
			return retVal;
		}
		Vector<T, N> operator*(long other) {
			Vector<T, N> retVal = Vector<T, N>(this->components);
			for (size_t i = 0; i < N; i++) {
				retVal.components[i] *= other;
			}
			return retVal;
		}
		Vector<T, N> operator*(float other) {
			Vector<T, N> retVal = Vector<T, N>(this->components);
			for (size_t i = 0; i < N; i++) {
				retVal.components[i] *= other;
			}
			return retVal;
		}
		Vector<T, N> operator*(double other) {
			Vector<T, N> retVal = Vector<T, N>(this->components);
			for (size_t i = 0; i < N; i++) {
				retVal.components[i] *= other;
			}
			return retVal;
		}
		Vector<T, N> operator/(int other) {
			Vector<T, N> retVal = Vector<T, N>(this->components);
			for (size_t i = 0; i < N; i++) {
				retVal.components[i] /= other;
			}
			return retVal;
		}
		Vector<T, N> operator/(float other) {
			Vector<T, N> retVal = Vector<T, N>(this->components);
			for (size_t i = 0; i < N; i++) {
				retVal.components[i] /= other;
			}
			return retVal;
		}

		operator Vector<float, 3>() {
			return Vector<float, 3>(*this);
		}
		operator Vector<float, 4>() {
			return Vector<float, 4>(*this);
		}
	};

	
	/// <summary>
	/// Generic Vector3 structure using floats for components.
	/// 
	/// Kept for backwards compatibility.
	/// </summary>
	class Vector3
	{
	public:
		float x, y, z;


		Vector3();
		Vector3(Vector<float, 3> other);
		Vector3(float _x, float _y, float _z);

		Vector3(Vector3& other);
		Vector3(Vector3&& other);

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

		operator Vector<float, 3>();
	};





	class Vector3Float {
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