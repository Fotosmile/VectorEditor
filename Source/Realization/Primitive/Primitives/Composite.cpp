//
// Created by Vlad on 10.10.18.
//

#include "Composite.h"
#include "Primitive/Primitive.h"

Composite::Composite(const std::list<std::shared_ptr<Primitive>>& primitives)
        : m_children(primitives)
{
//    //set for each leaf the common color
//    const Color commonColor = m_children.front()->getColor();
//    for (const std::shared_ptr<Primitive>& child: m_children)
//    {
//        child->setColor(commonColor);
//    }
}

Composite::Composite(const Composite& other)
        : Primitive(other),
          m_children(other.m_children)
{
}

std::unique_ptr<Primitive> Composite::clone()
{
    return std::make_unique<Composite>(*this);
}

void Composite::setColor(const Color& color)
{
    for (const std::shared_ptr<Primitive>& child: m_children)
    {
        child->setColor(color);
    }
}

void Composite::move(int x, int y)
{
    for (const std::shared_ptr<Primitive>& child: m_children)
    {
        child->move(x, y);
    }
}

void Composite::changeSize(int x, int y)
{
    for (const std::shared_ptr<Primitive>& child: m_children)
    {
        child->changeSize(x, y);
    }
}

bool Composite::containsPoint(int x, int y)
{
    for (const std::shared_ptr<Primitive>& child: m_children)
    {
        if (child->containsPoint(x, y))
        {
            return true;
        }
    }
    return false;
}

const Color& Composite::getColor()
{
    return m_children.front()->getColor();
}

const std::list<std::shared_ptr<Primitive>>& Composite::getChildren()
{
    return m_children;
}