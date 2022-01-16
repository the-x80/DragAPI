#pragma once
#ifndef DRAG_API_CALLBACK_H
#define DRAG_API_CALLBACK_H

namespace DragAPI {


	template <class RET, class ...Args> class Callback {
	protected:
		
	public:
		Callback() {};
		Callback(Callback& other) {};
		Callback(Callback&& other) {};
		~Callback() {};

		virtual RET Invoke(Args&& ... args) = 0;
	};
	template <class RET, class ...Args> class GlobalCallback : public Callback<RET, Args...> {
	protected:
		RET(*func)(Args...);
	public:
		GlobalCallback() {};
		GlobalCallback(GlobalCallback& other) {};
		GlobalCallback(GlobalCallback&& other) {};
		~GlobalCallback() {};

		RET Invoke(Args&&... args) override {
			return (*func)(std::forward<Args>(args)...);
		}
	};
	template <class RET, class T, class ... Args> class MemberCallback : Callback<RET, Args...> {
	protected:
		T* owner;
		RET(T::* func)(Args...);
	public:
		MemberCallback() {};
		MemberCallback(T* obj, RET(T::* fn)(Args...)) : owner(obj), func(fn) {}
		MemberCallback(MemberCallback& other) {};
		MemberCallback(MemberCallback&& other) {};
		~MemberCallback() {};


		RET Invoke(Args&&... args) override {
			return (*owner.*(func))(std::forward<Args>(args)...);
		}
	};
}

#endif