#pragma once
#ifndef DRAG_API_STACK_H
#define DRAG_API_STACK_H
#include "../Exceptions/Exceptions.h"

#define _CRT_SECURE_NO_WARNINGS
#include <memory>

namespace DragAPI {
	template <typename T> class Stack;


	namespace Exceptions {
		template <typename T> class StackOverflow : public Exception {
		private:
			Stack<T>& objectReference;
		public:
			StackOverflow() {};
			StackOverflow(Stack<T>& ref) {};
			StackOverflow(StackOverflow& other) {};
			StackOverflow(StackOverflow&& other) {};
			~StackOverflow() {};


			const char* what() const override {};
		};
		template <typename T> class StackUnderflow : public Exception {
		private:
			Stack<T>& objectReference;
		public:
			StackUnderflow() {};
			StackUnderflow(Stack<T>& ref) {};
			StackUnderflow(StackUnderflow& other) {};
			StackUnderflow(StackUnderflow&& other) {};
			~StackUnderflow() {};


			const char* what() const override {};
		};
	}

	enum class StackType : unsigned char {//Set this to a bit mask.
		FIFO = 0b00000011,
		FILO = 0b00000010,
		LIFO = 0b00000001,
		LILO = 0b00000000
	};
	template <typename T> class Stack {
	private:
		T* stackData;
		size_t stackCountCurrent;
		size_t stackCountAllocated;

		size_t maxDepth;
		StackType stackType;
	public:
		Stack() {
			this->stackData = new T[0];
			this->stackCountAllocated = 0;
			this->stackCountCurrent = 0;
			this->stackType = StackType::LILO;
		};
		Stack(Stack& other) {
			this->stackCountAllocated = other.stackCountAllocated;
			this->stackCountCurrent = other.stackCountCurrent;
			this->stackData = new T[this->stackCountAllocated];
			memcpy(this->stackData, other.stackData, other.stackCountAllocated);
		};
		Stack(Stack&& other) {};
		Stack(size_t initialSize) {
			stackCountCurrent = 0;
			stackCountAllocated = initialSize;
			stackData = new T[stackCountAllocated];
		};
		Stack(StackType type) {

		}
		Stack(StackType type, size_t initialSize) {

		}
		~Stack() {
			delete[] stackData;
			this->stackData = nullptr;
			this->stackCountAllocated = 0;
			this->stackCountCurrent = 0;
		};

		void Push(T& element) {
			if (this->stackCountCurrent >= this->maxDepth) {
				//This should throw an exception

			}

			if (this->stackCountCurrent >= this->stackCountAllocated) {
				this->ReSize(this->stackCountCurrent + 1);
			}

			if (this->stackData == nullptr) {
				//This should never happen.
				//This should be a crittical error.
				//Perform a detailed check and throw an exception

			}


			this->stackData[this->stackCountCurrent] = element;
			this->stackCountCurrent++;
		}
		T Pop(bool resize = false) {
			T retVal = this->stackData[this->stackCountCurrent-1];
			this->stackCountCurrent--;
			if (resize == true) {
				this->ReSize(this->stackCountCurrent);
			}
			return retVal;
		}
		void ReSize(size_t new_size) {
			this->stackCountAllocated = new_size;
			this->stackData = realloc(this->stackData, new_size);
		}
		void SetMaxDepth(size_t s) {
			this->maxDepth = s;
		}
	};
}

#endif