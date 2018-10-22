//
// Created by Vlad on 10.10.18.
//

#ifndef ARCHITECTURE_PAINTER_H
#define ARCHITECTURE_PAINTER_H

#include "Common/Color.h"

class Painter
{
public:
    virtual ~Painter() = default;

    virtual void clear() = 0;

    virtual void drawLine(int x1, int y1, int x2, int y2, const Color& color) = 0;
    virtual void drawRectangle(int x1, int y1, int x2, int y2, const Color& color) = 0;
    virtual void drawCircle(int x, int y, int radius, const Color& color) = 0;
};


#endif //ARCHITECTURE_PAINTER_H
