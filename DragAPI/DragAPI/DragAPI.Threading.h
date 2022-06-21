#pragma once
#ifndef DRAG_API_THREADING_H
#define DRAG_API_THREADING_H

//TODO: Implement propper threading

namespace DragAPI {
	class Thread {
	public:
		Thread();
		~Thread();

		/// <summary>
		/// Creates a default Thread object
		/// </summary>
		/// <returns>The created Thread object</returns>
		static Thread Create();
	};
}
#endif