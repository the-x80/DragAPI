#ifndef DRAG_API_VECTOR3_H
#define DRAG_API_VECTOR3_H
#include <stdint.h>

namespace DragAPI {
	struct vector2_uint8 {
		uint8_t x, y;
	};
	struct vector2_uint16 {
		uint16_t x, y;
	};
	struct vector2_uint32 {
		uint32_t x, y;
	};
	struct vector2_uint64 {
		uint64_t x, y;
	};
	struct vector2_int8 {
		int8_t x, y;
	};
	struct vector2_int16 {
		int16_t x, y;
	};
	struct vector2_int32 {
		int32_t x, y;
	};
	struct vector2_int64 {
		int64_t x, y;
	};

	struct vector2_float{
		float_t x, y;
	};
	struct vector2_double {
		double x, y;
	};


	struct vector3_uint8 {
		uint8_t x, y, z;
	};
	struct vector3_uint16 {
		uint16_t x, y, z;
	};
	struct vector3_uint32 {
		uint32_t x, y, z;
	};
	struct vector3_uint64 {
		uint64_t x, y, z;
	};
	struct vector3_int8 {
		int8_t x, y, z;
	};
	struct vector3_int16 {
		int16_t x, y, z;
	};
	struct vector3_int32 {
		int32_t x, y, z;
	};
	struct vector3_int64 {
		int64_t x, y, z;
	};

	struct vector3_float {
		float_t x, y, z;
	};
	struct vector3_double {
		double x, y, z;
	};


	struct vector4_uint8 {
		uint8_t x, y, z, w;
	};
	struct vector4_uint16 {
		uint16_t x, y, z, w;
	};
	struct vector4_uint32 {
		uint32_t x, y, z, w;
	};
	struct vector4_uint64 {
		uint64_t x, y, z, w;
	};
	struct vector4_int8 {
		int8_t x, y, z, w;
	};
	struct vector4_int16 {
		int16_t x, y, z, w;
	};
	struct vector4_int32 {
		int32_t x, y, z, w;
	};
	struct vector4_int64 {
		int64_t x, y, z, w;
	};

	struct vector4_float {
		float_t x, y, z, w;
	};
	struct vector4_double {
		double x, y, z, w;
	};
}
#endif