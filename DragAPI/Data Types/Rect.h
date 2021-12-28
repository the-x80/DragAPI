#pragma once
#ifndef DRAG_API_RECT_H
#define DRAG_API_RECT_H

namespace DragAPI {
	template <class T> class Rect {
	private:
		T xMin, xMax;
		T yMin, yMax;
	public:
		Rect(): xMin(0), xMax(0), yMin(0), yMax(0) {};
	};

	class RectInt : public Rect<int> {
	public:
		RectInt();
	};
}

#endif