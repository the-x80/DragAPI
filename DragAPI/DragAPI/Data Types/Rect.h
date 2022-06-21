#pragma once
#ifndef DRAG_API_RECT_H
#define DRAG_API_RECT_H

namespace DragAPI {
	template <class T> class Rect {
	private:
		
	public:
		T xMin, xMax;
		T yMin, yMax;
		inline Rect(): xMin(0), xMax(0), yMin(0), yMax(0) {};
		inline Rect(xmin, ymin, xmax, ymax) : xMin(xmin), xMax(xmax), yMin(ymin), yMax(ymax) {};

		inline T Width() { return xMax - yMin };
		inline T Height() { return yMax - yMin };
	};
}

#endif