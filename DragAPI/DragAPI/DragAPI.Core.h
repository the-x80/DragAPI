#pragma once
#ifndef DRAG_API_CORE_H
#define DRAG_API_CORE_H

#ifdef _WINRT_DLL
#define DRAG_API _declspec(dllexport)
#else
#define DRAG_API _declspec(dllimport)
#endif

#ifdef _DEBUG
#define DRAG_API_ASSERT(x, ...) if(x==false){printf(...);__debugbreak();}
#else
#define DRAG_API_ASSERT(x, ...)
#endif
#endif