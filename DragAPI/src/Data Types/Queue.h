#pragma once
#ifndef DRAG_API_QUEUE_H
#define DRAG_API_QUEUE_H
#include <vector>

#include "../Exceptions/Exceptions.h"

namespace DragAPI {
	template <class T> class Queue {
	protected:
		T* m_Queue;
		size_t m_AllocatedElementCount;
		size_t m_ElementCount;
	public:
		Queue() :
			m_Queue(nullptr),
			m_AllocatedElementCount(0),
			m_ElementCount(0)
		{
			throw new DragAPI::Exceptions::NotImplementedException();
		}
		Queue(Queue& other) :
		m_Queue(other.m_Queue),
		m_AllocatedElementCount(other.m_AllocatedElementCount),
		m_ElementCount(other.m_ElementCount)
		{

		}
		Queue(Queue&& other) {

		}
		~Queue() {
			if (m_Queue != nullptr) {
				delete[] this->m_Queue;
			}
		}

		/// <summary>
		/// Pushes the element of type T to the last element of the queue
		/// </summary>
		/// <param name="element">The element that is to be pushed to the queue.</param>
		void Push(T element) {
			
		}

		/// <summary>
		/// Removes the first element of the queue
		/// </summary>
		/// <param name="bResize">Set this parameter to true to reallocate and resize the buffer containing the elements.</param>
		void Pop(bool bResize = false) {

		}

		/// <summary>
		/// Clears the entire queue buffer
		/// </summary>
		/// <param name="bResize">Set this parameter to true to reallocate and resize the buffer containing the elements.</param>
		void Clear(bool bResize = false) {

		}

		/// <summary>
		/// Returns the number of elements in the buffer.
		/// </summary>
		/// <returns>Number of elements in the buffer.</returns>
		size_t ElementCount() {
			return this->m_ElementCount;
		}
		/// <summary>
		/// Returns the reserved ammount of elements in the buffer.
		/// </summary>
		/// <returns>Reserved element count.</returns>
		size_t AllocatedElementCount() {
			return this->m_AllocatedElementCount;
		}
	};
}

#endif