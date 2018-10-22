//
// Created by Vlad on 10.10.18.
//

#include "Color.h"

Color::Color()
        : m_r(0),
          m_g(0),
          m_b(0)
{
}

Color::Color(const std::string& color)
        : Color()
{
    //magic actions of getting r g b from the color name
}

Color::Color(int r, int g, int b)
        : m_r(r),
          m_g(g),
          m_b(b)
{
}

void Color::setColor(int r, int g, int b)
{
    m_r = r;
    m_g = g;
    m_b = b;
}

int Color::getR() const
{
    return m_r;
}

int Color::getG() const
{
    return m_g;
}

int Color::getB() const
{
    return m_b;
}