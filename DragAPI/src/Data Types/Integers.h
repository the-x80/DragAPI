#ifndef DRAG_API_INTEGERS_H
#define DRAG_API_INTEGERS_H

namespace DragAPI {
	class Int8 {
	private:
		unsigned char data;
	public:
		Int8();
		Int8(unsigned char value);
		Int8(Int8& other);
		Int8(Int8&& other);




		static unsigned char MaxValue();
	};
	class Int16 {

	};
	class Int32 {

	};
	class Int64 {

	};


}

#endif