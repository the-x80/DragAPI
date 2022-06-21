#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>
#include <exception>

#include <array>
#include <vector>
#include <string>

#ifdef _DEBUG
#define _DEBUG_EXCEPTIONS
#endif

//TODO:Refactor the Exception class to hold a wide character string. Use std::wstring for convenience.

namespace DragAPI {
	namespace Diagnostics {
		class StackTrace;
	}
	namespace Exceptions {
		/// <summary>
		/// Base class for all exceptions
		/// </summary>
		class Exception : public std::exception {
		protected:
			/// <summary>
			/// Contains the full printable message used by ToString() method.
			/// </summary>
			char* cstr_FullMessage;
			char* message;

			int n_SourceFileLine;

			DragAPI::Diagnostics::StackTrace* stackTrace;
			/// <summary>
			/// Describes the method that the exception was thrown in.
			/// </summary>
			//DebugMethodInfo mi_Method;
			int n_WindowsLastErrorCode;
		public:
			Exception() noexcept;
			Exception(const char* msg) noexcept;
			~Exception() noexcept;

			const char* what() const override;

			virtual char* ToString();
		protected:
			void PrintToOutput();
		};
		
		class NullPointerException : public Exception {
		public:
			NullPointerException() noexcept;
			NullPointerException(const char* msg) noexcept;
			~NullPointerException() noexcept;
		};
		class OutOfMemoryException : public Exception {
		public:
			OutOfMemoryException();
		};
		class BadAllocationException : public Exception {
		public:
			BadAllocationException();
			BadAllocationException(const char* msg);
		};

		class ArgumentException : public Exception{
		public:
			void* m_ArgumentPointer;
		};
		class ArgumentNullException : public ArgumentException {
		public:
			ArgumentNullException();
		};
		class InvalidArgumentException : public ArgumentException {
		public:
			InvalidArgumentException();
			InvalidArgumentException(std::string message);
		};


		class IndexOutOfBoundsException : public Exception {
		public:
			IndexOutOfBoundsException();
		};

		class DivisionByZeroException : public Exception {
		public:
			DivisionByZeroException();
		};

		class NotImplementedException : Exception {
		public:
			NotImplementedException();
		};
	}
}
#endif