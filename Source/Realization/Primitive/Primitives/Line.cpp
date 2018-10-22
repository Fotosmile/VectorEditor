//
// Created by Vlad on 10.10.18.
//

#include "Line.h"
#include "Common/CommonDefines.h"
#include "Primitive/Painter/Painter.h"
#include <cmath>

Line::Line()
        : m_color(),
          m_x1(0),
          m_y1(0),
          m_x2(defaultWindowWidth / 10),
          m_y2(defaultWindowHeight / 10)
{
}

Line::Line(const Line& other)
        : Primitive(other),
          m_color(other.m_color),
          m_x1(other.m_x1),
          m_y1(other.m_y1),
          m_x2(other.m_x2),
          m_y2(other.m_y2)
{
}

std::unique_ptr<Primitive> Line::clone()
{
    return std::make_unique<Line>(*this);
}

void Line::setColor(const Color& color)
{
    m_color = color;

    update();
}

void Line::move(int x, int y)
{
    m_x1 += x;
    m_y1 += y;

    m_x2 += x;
    m_y2 += y;

    update();
}

void Line::changeSize(int x, int y)
{
    m_x2 += x;
    m_y2 += y;

    update();
}

bool Line::containsPoint(int x, int y)
{
    return distance(m_x1, m_y1, x, y) + distance(m_x2, m_y2, x, y) == distance(m_x1, m_y1, m_x2, m_y2);
}

const Color& Line::getColor()
{
    return m_color;
}

void Line::update()
{
    getPainter().clear();
    getPainter().drawLine(m_x1, m_y1, m_x2, m_y2, m_color);
}

double distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(static_cast<double>(x1 - x2), 2) +
                pow(static_cast<double>(y1 - y2), 2));
}