//
// Created by Vlad on 03/11/18.
//

#include "PainterFactory.h"

#include "CommonDefines.h"
#include "LinuxPainter.h"
#include "WindowsPainter.h"

std::unique_ptr<IPainter> createPainter()
{
#ifdef CUR_OS_WINDOWS
    return std::make_unique<WindowsPainter>();
#elif defined(CUR_OS_LINUX)
    return std::make_unique<LinuxPainter>();
#else
    #error
#endif
}