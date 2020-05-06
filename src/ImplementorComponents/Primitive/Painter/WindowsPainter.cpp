//
// Created by Vlad on 10.10.18.
//

#include "CommonDefines.h"
#ifdef CUR_OS_WINDOWS

#include "WindowsPainter.h"
#include "Common/Color.h"
#include <iostream>

void WindowsPainter::drawLine(int x1, int y1, int x2, int y2, const Color& color)
{
    std::cout << " [ " << __func__ << " ] : "
              << "Drawing a line: (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ") with a color: "
              << "(" << color.getR() << ", " << color.getG() << ", " << color.getB() << ")" << std::endl;
}

void WindowsPainter::drawRectangle(int x1, int y1, int x2, int y2, const Color& color)
{
    drawLine(x1, y1, x2, y1, color);
    drawLine(x2, y1, x2, y2, color);
    drawLine(x1, y2, x2, y2, color);
    drawLine(x1, y1, x1, y2, color);
}

void WindowsPainter::drawCircle(int x, int y, int radius, const Color& color)
{
    std::cout << " [ " << __func__ << " ] : "
              << "Drawing a circle (" << x << ", " << y << ") with a radius " << radius << " and a color: "
              << "(" << color.getR() << ", " << color.getG() << ", " << color.getB() << ")" << std::endl;
}

void WindowsPainter::clear()
{
    std::cout << " [ " << __func__ << " ] : "
              << "Clearing an area" << std::endl;
}

#endif