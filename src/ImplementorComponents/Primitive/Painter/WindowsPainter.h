//
// Created by Vlad on 10.10.18.
//

#ifndef ARCHITECTURE_WINDOWSPAINTER_H
#define ARCHITECTURE_WINDOWSPAINTER_H

#include "CommonDefines.h"
#ifdef CUR_OS_WINDOWS

#include "IPainter.h"

class WindowsPainter : public IPainter
{
public:
    void clear() override;

    void drawLine(int x1, int y1, int x2, int y2, const Color& color) override;
    void drawRectangle(int x1, int y1, int x2, int y2, const Color& color) override;
    void drawCircle(int x, int y, int radius, const Color& color) override;
};

#endif

#endif //ARCHITECTURE_WINDOWSPAINTER_H
