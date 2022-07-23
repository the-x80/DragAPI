#pragma once
#include <stdint.h>

namespace DragAPI {
	struct mat3x3_uint8 {
		uint8_t elements[3][3];
	};
	struct mat3x3_uint16 {
		uint16_t elements[3][3];
	};
	struct mat3x3_uint32 {
		uint32_t elements[3][3];
	};
	struct mat3x3_uint64 {
		uint64_t elements[3][3];
	};

	struct mat3x3_float {
		float elements[3][3];
	};
	struct mat3x3_double {
		double elements[3][3];
	};

	struct mat4x4_uint8 {
		uint8_t elements[4][4];
	};
	struct mat4x4_uint16 {
		uint16_t elements[4][4];
	};
	struct mat4x4_uint32 {
		uint32_t elements[4][4];
	};
	struct mat4x4_uint64 {
		uint64_t elements[4][4];
	};

	struct mat4x4_float {
		float elements[4][4];
	};
	struct mat4x4_double {
		double elements[4][4];
	};
}