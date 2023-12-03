#pragma once


//it will only be executed if it is window

#ifdef WIN32

#include <Windows.h> 

#endif

#ifdef BUILD_DLL
    #define SHOOT_API _declspec(dllexport) //if build inside engine, export it
#else
    #define SHOOT_API _declspec(dllimport) //if build outside engine, then import it
#endif

#include "Common/Logger.h"