#pragma once

#include <windows.h>

class Timer
{
public:
    Timer();
    inline static void msleep(int ms)
    {
        Sleep(ms);
    }
};
