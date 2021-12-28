#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>
#include <exception>

namespace DragAPI {
	namespace Diagnostics {
		class StackTrace;
	}
	namespace Exceptions {
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

			Exception* e_InnerException;

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

		class ArgumentNullException : public Exception {
		public:
			ArgumentNullException();
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