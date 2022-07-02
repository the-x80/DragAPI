#pragma once

namespace DragAPI {
	template <typename T, size_t X, size_t Y> class Matrix {
	public:
		T m_Elements[X * Y];

		Matrix() {

		}




		T operator[][](size_t x, size_t y){
			return this->m_Elements[x + (X * y)];
		}
	};
}