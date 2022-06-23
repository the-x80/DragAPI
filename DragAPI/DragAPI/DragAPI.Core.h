#pragma once
#ifndef DRAG_API_CORE_H
#define DRAG_API_CORE_H

#ifdef _WIN32
#include <crtdbg.h>
#endif

#ifdef _WINRT_DLL
#define DRAG_API _declspec(dllexport)
#else
#define DRAG_API _declspec(dllimport)
#endif

#ifdef _DEBUG
#define DRAG_API_ASSERT(x, ...) if((x)==false){_CrtDbgReport(_CRT_ASSERT, __FILE__, __LINE__, NULL, __VA_ARGS__);__debugbreak();}
#else
#define DRAG_API_ASSERT(x, ...)
#endif
#endif

#define BIT_SET(n) (1UL << n)