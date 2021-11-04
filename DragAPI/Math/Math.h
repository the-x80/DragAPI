#ifndef DRAG_API_MATH_H
#define DRAG_API_MATH_H
namespace DragAPI {
	namespace Math {
		static const double PI = 3.1415926535897932384626433832795;


		unsigned short Abs(unsigned short value);
		short Abs(short value);
		int Abs(int value);
		long Abs(long value);

		float Abs(float value);
		double Abs(double value);

#pragma region Rounding
		float Round(float value);
		double Round(double value);

		float Floor(float value);
		double Floor(double value);

		float Ceil(float value);
		double Ceil(double value);
#pragma endregion
#pragma region Power of
		unsigned char Pow(unsigned char value, float power);
		short Pow(short value, float power);
		int Pow(int value, float power);
		long Pow(long value, float power);

		float Pow(float value, float power);
		double Pow(double value, float power);
#pragma endregion
#pragma region Root
		unsigned char Root(unsigned char value, float root);
		short Root(short value, float root);
		int Root(int value, float root);
		long Root(long value, float root);

		float Root(float value, float root);
		double Root(double value, float root);
#pragma endregion
#pragma region Trigonometry
		float Deg2Rad(float value);
		double Deg2Rad(double value);

		float Rad2Deg(float value);
		double Rad2Deg(double value);

		float Sin(float value);
		float Cos(float value);
		float Tan(float value);

		float ASin(float value);
		float ACos(float value);
		float ATan(float value);

		float Sec(float value);
		float Csc(float value);
		float Cot(float value);
#pragma endregion
	}
}
#endif