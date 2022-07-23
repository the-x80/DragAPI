#pragma once


namespace DragAPI {
	struct rect_uint8 {
		unsigned char xMin, yMin, xMax, yMax;
	};
	struct rect_uint16 {
		unsigned short xMin, yMin, xMax, yMax;
	};
	struct rect_uint32 {
		unsigned int xMin, yMin, xMax, yMax;
	};
	struct rect_uint64 {
		unsigned long xMin, yMin, xMax, yMax;
	};

	struct rect_int8 {
		char xMin, yMin, xMax, yMax;
	};
	struct rect_int16 {
		short xMin, yMin, xMax, yMax;
	};
	struct rect_int32 {
		int xMin, yMin, xMax, yMax;
	};
	struct rect_int64 {
		long xMin, yMin, xMax, yMax;
	};

	struct rect_float {
		float xMin, yMin, xMax, yMax;
	};
	struct rect_double {
		float xMin, yMin, xMax, yMax;
	};
}