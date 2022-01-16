#pragma once
#ifndef DRAG_API_CONSOLE_H
#define DRAG_API_CONSOLE_H

namespace DragAPI {
	namespace Console {
		/// <summary>
		/// Creates the console
		/// </summary>
		/// <returns>Returns true if the console was created otherwise false</returns>
		bool Allocate();

		/// <summary>
		/// Checks to see if the console is opened
		/// </summary>
		/// <returns>True if the console is opened otherwise false.</returns>
		bool IsConsoleOpen();
	}
}

#endif