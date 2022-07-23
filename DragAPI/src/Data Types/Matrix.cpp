#include <intrin.h>
#include "nmmintrin.h" // for SSE4.2
#include "immintrin.h" // for AVX

#include "../Debugging/Debug.h"
#include "Matrix.h"

//TODO: Implement SIMD http://www.cs.uu.nl/docs/vakken/magr/2017-2018/files/SIMD%20Tutorial.pdf

DragAPI::Matrix4x4::Matrix4x4()
{
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			this->m_Elements[x][y] = 0;
		}
	}
}

DragAPI::Matrix4x4::Matrix4x4(const Matrix4x4& right)
{
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			this->m_Elements[x][y] = right.m_Elements[x][y];
		}
	}
}


