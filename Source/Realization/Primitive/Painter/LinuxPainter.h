//
// Created by Vlad on 10.10.18.
//

#ifndef ARCHITECTURE_LINUXPAINTER_H
#define ARCHITECTURE_LINUXPAINTER_H

#include "Painter.h"

class LinuxPainter : public Painter
{
public:
    void clear() override;

    void drawLine(int x1, int y1, int x2, int y2, const Color& color) override;
    void drawRectangle(int x1, int y1, int x2, int y2, const Color& color) override;
    void drawCircle(int x, int y, int radius, const Color& color) override;
};


#endif //ARCHITECTURE_LINUXPAINTER_H
