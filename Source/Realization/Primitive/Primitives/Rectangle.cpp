//
// Created by Vlad on 10.10.18.
//

#include "Rectangle.h"
#include "Primitive/Painter/Painter.h"
#include "Common/CommonDefines.h"

Rectangle::Rectangle()
        : m_color(),
          m_x1(0),
          m_y1(0),
          m_x2(defaultWindowWidth / 10),
          m_y2(defaultWindowHeight / 10)
{
}

Rectangle::Rectangle(const Rectangle& other)
        : Primitive(other),
          m_color(other.m_color),
          m_x1(other.m_x1),
          m_y1(other.m_y1),
          m_x2(other.m_x2),
          m_y2(other.m_y2)
{
}

std::unique_ptr<Primitive> Rectangle::clone()
{
    return std::make_unique<Rectangle>(*this);
}

void Rectangle::setColor(const Color& color)
{
    m_color = color;

    update();
}

void Rectangle::move(int x, int y)
{
    m_x1 += x;
    m_y1 += y;

    m_x2 += x;
    m_y2 += y;

    update();
}

void Rectangle::changeSize(int x, int y)
{
    m_x2 += x;
    m_y2 += y;

    update();
}

bool Rectangle::containsPoint(int x, int y)
{
    return m_x1 <= x && x <= m_x2 &&
           m_y1 <= y && y <= m_y2;
}

const Color& Rectangle::getColor()
{
    return m_color;
}

void Rectangle::update()
{
    getPainter().clear();
    getPainter().drawRectangle(m_x1, m_y1, m_x2, m_y2, m_color);
}