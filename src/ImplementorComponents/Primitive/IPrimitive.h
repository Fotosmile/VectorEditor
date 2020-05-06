//
// Created by Vlad on 10.10.18.
//

#ifndef ARCHITECTURE_PRIMITIVE_H
#define ARCHITECTURE_PRIMITIVE_H

#include <memory>

#include "Common/Color.h"

class IPrimitive
{
public:
    virtual ~IPrimitive() = default;

    virtual std::unique_ptr<IPrimitive> clone() = 0;
    virtual void setColor(const Color& color) = 0;
    virtual void move(int x, int y) = 0;
    virtual void changeSize(int x, int y) = 0;
    virtual bool containsPoint(int x, int y) = 0;
    virtual const Color& getColor() = 0;
};

#endif //ARCHITECTURE_PRIMITIVE_H
