#pragma once
#ifndef DRAG_API_TYPES_H
#define DRAG_API_TYPES_H

//TODO: Implement type reflection. Should be very usefull for event system.

namespace DragAPI {
	class Type;

	/// <summary>
	/// An interface used to implement typing of objects
	/// </summary>
	class ITypeable {
	public:
		static Type* GetTypeStatic() { return nullptr; };
		virtual Type* GetType() = 0;
	};


#define DRAG_API_TYPE_METHODS(x)\
			

	/// <summary>
	/// Class representing a type
	/// </summary>
	class Type : public ITypeable{
	public:


		Type();
		~Type();
	};

	
}

#endif