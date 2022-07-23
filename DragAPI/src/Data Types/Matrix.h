#pragma once

namespace DragAPI {
	template <typename T, size_t X, size_t Y> class Matrix {
	public:
		T m_Elements[X][Y];

		Matrix() {

		}



	};

	struct Matrix3x3 {
	public:
		double m_Elements[3][3];
	};
	struct Matrix4x4 {
	public:
		double m_Elements[4][4];

		Matrix4x4();
		Matrix4x4(const Matrix4x4& right);
	};
}