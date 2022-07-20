#pragma once

namespace DragAPI {
	template <typename T, size_t X, size_t Y> class Matrix {
	public:
		T m_Elements[X][Y];

		Matrix() {

		}



	};

	class Matrix3x3 {
	public:
		double m_Elements[3][3];

		Matrix3x3();

	};
	class Matrix4x4 {
	public:
		double m_Elements[4][4];

		Matrix4x4();


	};
}