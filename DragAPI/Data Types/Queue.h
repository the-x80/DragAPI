#pragma once
#ifndef DRAG_API_QUEUE_H
#define DRAG_API_QUEUE_H
#include <vector>

namespace DragAPI {
	template <class T> class Queue {
	protected:
		T* queue;
		size_t allocatedCount;
		size_t count;
	public:
		Queue() :
			queue(nullptr),
			allocatedCount(0),
			count(0)
		{

		}
		Queue(Queue& other) {

		}
		Queue(Queue&& other) {

		}
		~Queue() {
			if (queue != nullptr) {
				delete[] this->queue;
			}
		}


		void Push(T element) {

		}
		void Pop() {

		}
	};
}

#endif