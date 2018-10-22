//
// Created by Vlad on 20/10/18.
//

#include "Primitive.h"
#include "Common/CommonDefines.h"

#include "Painter/LinuxPainter.h"
#include "Painter/WindowsPainter.h"

Painter& Primitive::getPainter()
{
#ifdef CUR_OS_WINDOWS
    static WindowsPainter painter;
#elif defined(CUR_OS_LINUX)
    static LinuxPainter painter;
#else
#error
#endif
    return painter;
}