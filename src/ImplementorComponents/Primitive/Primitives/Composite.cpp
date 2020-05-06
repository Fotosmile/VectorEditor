//
// Created by Vlad on 10.10.18.
//

#include "Composite.h"
#include "Primitive/IPrimitive.h"

Composite::Composite(const std::list<std::shared_ptr<IPrimitive>>& primitives)
        : m_children(primitives)
{
}

Composite::Composite(const Composite& other)
        : IPrimitive(other),
          m_children(other.m_children)
{
}

std::unique_ptr<IPrimitive> Composite::clone()
{
    return std::make_unique<Composite>(*this);
}

void Composite::setColor(const Color& color)
{
    for (const std::shared_ptr<IPrimitive>& child: m_children)
    {
        child->setColor(color);
    }
}

void Composite::move(int x, int y)
{
    for (const std::shared_ptr<IPrimitive>& child: m_children)
    {
        child->move(x, y);
    }
}

void Composite::changeSize(int x, int y)
{
    for (const std::shared_ptr<IPrimitive>& child: m_children)
    {
        child->changeSize(x, y);
    }
}

bool Composite::containsPoint(int x, int y)
{
    for (const std::shared_ptr<IPrimitive>& child: m_children)
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

const std::list<std::shared_ptr<IPrimitive>>& Composite::getChildren()
{
    return m_children;
}