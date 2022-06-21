#ifndef ARRAY_H
#define ARRAY_H

//Developer notes
//	-Switch from using new to using malloc. Slight speed increase.
//	-The Clear function needs a better implementation. See inside the function block for more info.
//Changelog
//28.8::
//	-Added Clear function to the Array class.
//15.9.2021::
//	-Added exception handling to the Add function when allocating memory for the resized array
//	-Switched memory allocation from new to malloc
//	-Switched memory deallocation from delete to free

#ifndef EXCEPTIONS_H
#include "../Exceptions/Exceptions.h"
#endif

//TODO:Make the reservedSize and reservedLength feature work. Currently its not implemented.


namespace DragAPI {
	namespace Exceptions {
		class ArrayEmptyException : public Exception {
		public:
			ArrayEmptyException();
			ArrayEmptyException(char* msg);
		};
	}

	template <typename T> class Array {
	private:
		T* elements;

		/// <summary>
		/// Specifies the current size of the array in memory.
		/// Only counts non empty elements.
		/// </summary>
		unsigned long size;

		/// <summary>
		/// Specifies the current number of elements in the array.
		/// Only counts non empty elements.
		/// </summary>
		unsigned long length;

		/// <summary>
		/// Specifies the actuall size of the array on the heap in bytes.
		/// </summary>
		unsigned long reservedSize;

		/// <summary>
		/// Specifies the ammount of total reserved slots in the array.
		/// </summary>
		unsigned long reservedLength;

		/// <summary>
		/// Set to true if this is a fixed size array.
		/// </summary>
		bool isFixedSize;
	public:
		inline Array():
			elements((T*)malloc(0)),
			length(0),
			size(0),
			reservedLength(0),
			reservedSize(0)
		{
		}
		inline Array(int n_StartLength) {
			throw new Exceptions::NotImplementedException();


			this->length = 0;
			this->size = 0 * sizeof(T);

			this->reservedLength = n_StartLength;
			this->reservedSize = sizeof(T) * this->reservedLength;

			this->elements = (T*)malloc(this->reservedSize);
		}
		inline Array(T* initialElements, unsigned int elementCount) :
			elements((T*)malloc(sizeof(T)*elementCount)),
			length(elementCount),
			size(sizeof(T)* elementCount),
			reservedLength(elementCount),
			reservedSize(sizeof(T)* elementCount) {
			memcpy_s(this->elements, sizeof(T) * this->length, initialElements, sizeof(T) * elementCount);
		}

		inline Array(Array& other) {
			
			this->length = other.length;
			this->size = other.size;
			this->elements = (T*)malloc(sizeof(T) * (this->Length() + 1));
			memcpy_s(this->elements, this->size, other.elements, other.size);
		}
		inline Array(Array&& other) noexcept {

		}
		inline ~Array()
		{
			free(elements);

			this->length = 0;
			this->size = 0;
			this->reservedLength = 0;
			this->reservedSize = 0;
		}

		/// <summary>
		/// Adds an element to the end of the array.
		/// </summary>
		/// <param name="element">The element that is added to the end of the array</param>
		/// <exception cref="::Exceptions::BadAllocationException"></exception>
		inline void Add(T element)
		{
			T* buffer = this->elements;

			this->elements = (T*)malloc(sizeof(T) * (this->Length() + 1));
			if (this->elements == nullptr) {
				throw new DragAPI::Exceptions::BadAllocationException("Unable to allocate memory for the resized array.");
			}

			//This will throw an exception. Make sure you do some sanity checks before
			memcpy_s(this->elements, this->length * sizeof(T), buffer, this->length * sizeof(T));
			free(buffer);
			this->elements[this->length] = element;
			this->length += 1;
			this->size = this->length * sizeof(T);
		}

		/// <summary>
		/// Adds an element to the first element of the array
		/// </summary>
		/// <param name="gen_Element">The element that is added at the beginning of the array.</param>
		/// <exception cref="::Exceptions::BadAllocationException"></exception>
		inline void AddFirst(T gen_Element) {
			T* buffer = this->elements;
			this->elements = (T*)malloc(sizeof(T) * (this->length + 1));
			if (this->elements == nullptr) {
				throw new DragAPI::Exceptions::BadAllocationException("Unable to allocate memory for the resized array.");
			}

			memcpy_s(this->elements + sizeof(T),
				(this->length * sizeof(T)) - sizeof(T),
				buffer,
				(this->length * sizeof(T)) - sizeof(T));
			free(buffer);
			this->elements[0] = gen_Element;
			this->length += 1;
			this->size = this->length * sizeof(T);
		}
		inline void InsertAt(T gen_Element, int index) {
			int n_SizePreInsert = sizeof(T) * index;
			int n_SizePostInsert = ((this->length + 1) * sizeof(T)) - n_SizePreInsert - sizeof(T);
			int n_InsertOffset = sizeof(T) * index;
			int n_PostInsertOffset = n_InsertOffset + sizeof(T);

			T* gen_Buffer = this->elements;
			this->elements = (T*)malloc(sizeof(T) * (this->length + 1));
			if (this->elements == nullptr) {
				throw new DragAPI::Exceptions::BadAllocationException("Unable to allocate memory for the resized array.");
			}

			memcpy(this->elements, gen_Buffer, n_SizePreInsert);
			memcpy(this->elements + n_InsertOffset, gen_Element, sizeof(T));
			memcpy(this->elements + n_PostInsertOffset, gen_Buffer, n_SizePostInsert);
			free(gen_Buffer);
			this->length += 1;
			this->size = this->length * sizeof(T);
		}
		inline bool Remove(T gen_Element) {
			if (this->Length() == 0) {
				throw new DragAPI::Exceptions::ArrayEmptyException();
			}

			bool b_Return = false;
			T* gen_Buffer = elements;//Copy the current contents into the buffer
			elements = (T*)malloc(sizeof(T) * (length - 1));//Create a new memory location with a smaller size.
			if (this->elements == nullptr) {
				throw new DragAPI::Exceptions::BadAllocationException("Unable to allocate memory for the resized array.");
			}

			int n_Index = 0;
			for (unsigned long i = 0; i < length; i++) {
				if (&gen_Buffer[i] == &gen_Element) {
					b_Return = true;
					continue;
				}
				elements[n_Index] = gen_Buffer[i];
				n_Index++;
			}
			return b_Return;
		}
		inline bool RemoveAt(int index) {
			throw new DragAPI::Exceptions::NotImplementedException();

			if ((index >= this->length) || (index < 0)) {
				throw new DragAPI::Exceptions::IndexOutOfBoundsException();
			}


		}
		inline bool RemoveLast() {
			long n_NewSize = (this->length - 1) * sizeof(T);
			if (n_NewSize < 0) {
				//There should be an exception thrown here.
				throw new Exceptions::ArrayEmptyException();
			}

			T* gen_Buffer = this->elements;
			this->elements = (T*)malloc(n_NewSize);
			if (this->elements == nullptr) {
				throw new DragAPI::Exceptions::BadAllocationException("Unable to allocate memory for the resized array.");
			}

			memcpy(this->elements, gen_Buffer, n_NewSize);
			free(gen_Buffer);
			this->length -= 1;
			this->size = this->length * sizeof(T);
		}
		inline bool RemoveFirst() {
			int n_NewSize = (this->length - 1) * sizeof(T);
			if (n_NewSize < 0) {
				//There should be an exception thrown here.
				throw new DragAPI::Exceptions::ArrayEmptyException();
			}

			T* gen_Buffer = this->elements;
			this->elements = (T*)malloc(n_NewSize);
			if (this->elements == nullptr) {
				throw new DragAPI::Exceptions::BadAllocationException("Unable to allocate memory for the resized array.");
			}

			memcpy(this->elements, gen_Buffer + sizeof(T), n_NewSize);
			free(gen_Buffer);
			this->length -= 1;
			this->size = this->length * sizeof(T);
		}

		/// <summary>
		/// Clears the contents of the array.
		/// </summary>
		inline void Clear() {
			free(this->elements);
			this->size = 0;
			this->length = 0;
			this->elements = nullptr;

			//This is where it becomes dangerous.
			//The allocation could fail and therefore
			//The elements will be nullptr wich the class does not expect.
			//Design around this. Either by adding if nullptr checks or by avoiding the exception
			//Thrown when new is called.
			this->elements = (T*)malloc(0);
			if (this->elements == nullptr) {
				throw new DragAPI::Exceptions::BadAllocationException();
			}
		}
		inline void SetFixedSize(bool value) {
			this->isFixedSize = value;
		}
		inline void SetFixedSize(bool value, int length) {
			this->isFixedSize = value;
			this->reservedLength = length;
		}

		unsigned long Length() const{
			return length;
		}
		T* GetBufferPointer() const {
			return this->elements;
		}


		inline T& operator[](unsigned long index) {
			if ((index >= this->length) || (index < 0)) {
				throw new DragAPI::Exceptions::IndexOutOfBoundsException();
			}
			return elements[index];
		}

	};
}
#endif