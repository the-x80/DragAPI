#ifdef _WIN32
#include "../Threading.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>




class ThreadWindows : public DragAPI::Threading::Thread {
public:
	HANDLE m_ThreadHandle;
	LPTHREAD_START_ROUTINE m_StartRoutine;

	ThreadWindows() :
		m_ThreadHandle(INVALID_HANDLE_VALUE),
		m_StartRoutine(nullptr)
	{
		this->m_ThreadHandle = CreateThread(NULL, NULL, this->m_StartRoutine, NULL, CREATE_SUSPENDED, NULL);
	}

	~ThreadWindows() {

	}

	virtual void Start(void* param = nullptr) override {

	}

	virtual void Terminate() override {

	}

	virtual void Pause() override {

	}
};

DragAPI::Threading::Thread* DragAPI::Threading::Thread::Create() {
	return new ThreadWindows();
}



#endif