#pragma once


namespace DragAPI {
	struct rect_u8 {
		unsigned char xMin, yMin, xMax, yMax;
	};
	struct rect_u16 {
		unsigned short xMin, yMin, xMax, yMax;
	};
	struct rect_u32 {
		unsigned int xMin, yMin, xMax, yMax;
	};
	struct rect_u64 {
		unsigned long xMin, yMin, xMax, yMax;
	};

	struct rect_8 {
		char xMin, yMin, xMax, yMax;
	};
	struct rect_16 {
		short xMin, yMin, xMax, yMax;
	};
	struct rect_32 {
		int xMin, yMin, xMax, yMax;
	};
	struct rect_64 {
		long xMin, yMin, xMax, yMax;
	};
}