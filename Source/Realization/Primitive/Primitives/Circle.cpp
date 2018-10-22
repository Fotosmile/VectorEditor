//
// Created by Vlad on 10.10.18.
//

#include <cmath>

#include "Circle.h"
#include "Common/CommonDefines.h"
#include "Primitive/Painter/Painter.h"

Circle::Circle()
        : m_color(),
          m_x(defaultWindowWidth / 10),
          m_y(defaultWindowHeight / 10),
          m_radius(defaultWindowWidth / 10)
{
}

Circle::Circle(const Circle& other)
        : Primitive(other),
          m_color(other.m_color),
          m_x(other.m_x),
          m_y(other.m_y),
          m_radius(other.m_radius)
{
}

std::unique_ptr<Primitive> Circle::clone()
{
    return std::make_unique<Circle>(*this);
}

void Circle::setColor(const Color& color)
{
    m_color = color;

    update();
}

void Circle::move(int x, int y)
{
    m_x += x;
    m_y += y;

    update();
}

void Circle::changeSize(int x, int y)
{
    double hypotenuse = sqrt(pow(static_cast<double>(x), 2) +
                             pow(static_cast<double>(y), 2));
    m_radius += static_cast<int>(hypotenuse);

    update();
}

bool Circle::containsPoint(int x, int y)
{
    return pow(static_cast<double>(x - m_x), 2) +
           pow(static_cast<double>(y - m_y), 2) < pow(static_cast<double>(m_radius), 2);
}

const Color& Circle::getColor()
{
    return m_color;
}

void Circle::update()
{
    getPainter().clear();
    getPainter().drawCircle(m_x, m_y, m_radius, m_color);
}